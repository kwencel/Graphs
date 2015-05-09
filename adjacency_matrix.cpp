#include <iostream>
#include <vector>
#include <forward_list>
#include <queue>
#include <algorithm>
#include "utils.h"
using namespace std;

vector<vector<int>> adjMatrix;
forward_list<int> visited;
queue<int> BFSqueue;

/* The vector of vector (matrix) indexing is the following:
 * Matrix[i][j]
 * i - index of a column
 * j - index of a row
 */

void AdjMatrixCreate(int vertexCount, int saturation) {     // Generate acyclic V x V matrix with 50% saturation
    // Resize the vector to be V x V matrix
    adjMatrix.resize(vertexCount, vector<int>(vertexCount, 0));   // Casting suggested by IDE
    // Calculate the maximum number of edges/links (ones in the matrix)
    int linksCountMax = ((vertexCount * (vertexCount - 1)) / 2) * saturation/100;
    int linksCount = 0;
    // Filling the upper triangle with ones (1) in random positions
    while (linksCount < linksCountMax) {
        // Generating random indexes to put (1) in
        int i = RandomBetween(0, vertexCount-1);
        int j = RandomBetween(0, i);
        // Check if (1) is already there, if so - repeat the process
        if ((adjMatrix[i][j] == 1) || (i == j)) {
            continue;
        } else {
            adjMatrix[i][j] = 1;
            ++linksCount;
        }
    }

    adjMatrix[0][0] = 0;
    adjMatrix[1][0] = 0;
    adjMatrix[2][0] = 1;
    adjMatrix[3][0] = 0;
    adjMatrix[4][0] = 0;
    adjMatrix[5][0] = 0;
    adjMatrix[0][1] = 1;
    adjMatrix[1][1] = 0;
    adjMatrix[2][1] = 1;
    adjMatrix[3][1] = 0;
    adjMatrix[4][1] = 0;
    adjMatrix[5][1] = 0;
    adjMatrix[0][2] = 0;
    adjMatrix[1][2] = 0;
    adjMatrix[2][2] = 0;
    adjMatrix[3][2] = 0;
    adjMatrix[4][2] = 0;
    adjMatrix[5][2] = 0;
    adjMatrix[0][3] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[2][3] = 0;
    adjMatrix[3][3] = 0;
    adjMatrix[4][3] = 1;
    adjMatrix[5][3] = 0;
    adjMatrix[0][4] = 0;
    adjMatrix[1][4] = 1;
    adjMatrix[2][4] = 1;
    adjMatrix[3][4] = 0;
    adjMatrix[4][4] = 0;
    adjMatrix[5][4] = 0;
    adjMatrix[0][5] = 1;
    adjMatrix[1][5] = 0;
    adjMatrix[2][5] = 0;
    adjMatrix[3][5] = 0;
    adjMatrix[4][5] = 1;
    adjMatrix[5][5] = 0;
    // http://edu.i-lo.tarnow.pl/inf/alg/001_search/0137.php - representation of this graph for testing purposes

}

bool AdjMatrixWasVertexVisited(int vertex) {
    return !(find(visited.begin(), visited.end(), vertex) == visited.end());
}

void AdjMatrixDFSTraversalRecur(int vertex) {
    if (AdjMatrixWasVertexVisited(vertex)) {
        return;
    } else {
        cout << vertex;
        visited.push_front(vertex);
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if (adjMatrix[i][vertex] == 1) {
                AdjMatrixDFSTraversalRecur(i);
            }
        }
    }
}

void AdjMatrixDFSTraversal(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        AdjMatrixDFSTraversalRecur(vertex);
    }
    for (int i = 0; i < firstVertex; ++i) {
        AdjMatrixDFSTraversalRecur(i);
    }
    visited.clear();
}

void AdjMatrixDFSSortRecur(int vertex) {
    if (AdjMatrixWasVertexVisited(vertex)) {
        return;
    }
    for (int i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[i][vertex] == 1) {
            AdjMatrixDFSSortRecur(i);
        }
    }
    visited.push_front(vertex);
}

void AdjMatrixDFSSort(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        AdjMatrixDFSSortRecur(vertex);
    }
    for (int i = 0; i < firstVertex; ++i) {
        AdjMatrixDFSSortRecur(i);
    }
    for (int item :visited) {
        cout << item;
    }
    visited.clear();
}

void AdjMatrixBFSTraversalIter(int vertex) {
	BFSqueue.push(vertex);
	visited.push_front(vertex);
	while (!BFSqueue.empty()) {
		vertex = BFSqueue.front();
		BFSqueue.pop();
		cout << vertex;
		for (int i = 0; i < adjMatrix.size(); ++i) {
			if ((adjMatrix[i][vertex] == 0) || (AdjMatrixWasVertexVisited(i))) {
				continue;
			} else {
				BFSqueue.push(i);
				visited.push_front(i);
			}
		}
	}
}

void AdjMatrixBFSTraversal(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        if (!AdjMatrixWasVertexVisited(vertex)) {
            AdjMatrixBFSTraversalIter(vertex);
        }
    }
    for (int i = 0; i < firstVertex; ++i) {
        if (!AdjMatrixWasVertexVisited(i)) {
            AdjMatrixBFSTraversalIter(i);
        }
    }
    visited.clear();
}

vector<int> AdjMatrixReturnInDegMatrix() {
    vector<int> adjInDegMatrix;
    adjInDegMatrix.resize(adjMatrix.size());
    for (int i = 0; i < adjMatrix.size(); ++i) {
        int vertexInDeg = 0;
        for (int j = 0; j < adjMatrix.size(); ++j) {
            // Calculate in(i) degree [i - current vertex]
            if (adjMatrix[i][j] == 1) {
                ++vertexInDeg;
            }
        }
        adjInDegMatrix[i] = vertexInDeg;
    }
    return adjInDegMatrix;
}

void AdjMatrixBFSSort(int vertex) {
    vector<int> adjInDegMatrix = AdjMatrixReturnInDegMatrix();
    while ( (find_if(adjInDegMatrix.begin(), adjInDegMatrix.end(), GreaterThanZero)) != ( adjInDegMatrix.end()) ) {
        for (vertex = 0; vertex < adjInDegMatrix.size(); ++vertex) {
            // If the vertex has "in" degree == 0
            if (adjInDegMatrix[vertex] == 0) {
                // Remove all links of this vertex
                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[i][vertex] == 1) {
                        adjInDegMatrix[i] -= 1;
                        adjInDegMatrix[vertex] -= 1;
                    }
                }
                cout << vertex;
            }
        }
    }
}

void AdjMatrixPrint() {
    cout << "--------- ADJACENCY MATRIX --------- " << endl;
    cout << "------------------------------------ " << endl;
    for (int j = 0; j < adjMatrix.size(); ++j) {
        for (int i = 0; i < adjMatrix.size(); ++i) {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
}
