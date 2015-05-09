#include <iostream>
#include <algorithm>
#include "adjacency_matrix.h"
#include "utils.h"
using namespace std;

/* The vector of vector (matrix) indexing is the following:
 * Matrix[i][j]
 * i - index of a column
 * j - index of a row
 */

AdjacencyMatrix::AdjacencyMatrix(int vertexCount, int saturation) {
    // Generate acyclic V x V matrix with a given saturation
    this->vertexCount = vertexCount;
    this->saturation = saturation;
    // Resize the vector to be V x V matrix
    adjMatrix.resize(vertexCount, vector<int>(vertexCount, 0));
    // Calculate the maximum number of edges/links (ones in the matrix)
    int linksCountMax = ((vertexCount * (vertexCount - 1)) / 2) * saturation / 100;
    int linksCount = 0;
    // Filling the upper triangle with ones (1) in random positions
    while (linksCount < linksCountMax) {
        // Generating random indexes to put (1) in
        int i = RandomBetween(0, vertexCount - 1);
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

bool AdjacencyMatrix::wasVertexVisited(int vertex) {
    return !(find(visited.begin(), visited.end(), vertex) == visited.end());
}

void AdjacencyMatrix::DFSTraversalRecur(int vertex) {
    if (wasVertexVisited(vertex)) {
        return;
    } else {
        cout << vertex;
        visited.push_front(vertex);
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if (adjMatrix[i][vertex] == 1) {
                DFSTraversalRecur(i);
            }
        }
    }
}

void AdjacencyMatrix::DFSSortRecur(int vertex) {
    if (wasVertexVisited(vertex)) {
        return;
    }
    for (int i = 0; i < adjMatrix.size(); ++i) {
        if (adjMatrix[i][vertex] == 1) {
            DFSSortRecur(i);
        }
    }
    visited.push_front(vertex);
}

void AdjacencyMatrix::BFSTraversalIter(int vertex) {
    BFSqueue.push(vertex);
    visited.push_front(vertex);
    while (!BFSqueue.empty()) {
        vertex = BFSqueue.front();
        BFSqueue.pop();
        cout << vertex;
        for (int i = 0; i < adjMatrix.size(); ++i) {
            if ((adjMatrix[i][vertex] == 0) || (wasVertexVisited(i))) {
                continue;
            } else {
                BFSqueue.push(i);
                visited.push_front(i);
            }
        }
    }
}

vector<int> AdjacencyMatrix::returnInDegArray() {
    vector<int> adjInDegArray;
    adjInDegArray.resize(adjMatrix.size());
    for (int i = 0; i < adjMatrix.size(); ++i) {
        int vertexInDeg = 0;
        for (int j = 0; j < adjMatrix.size(); ++j) {
            // Calculate in(i) degree [i - current vertex]
            if (adjMatrix[i][j] == 1) {
                ++vertexInDeg;
            }
        }
        adjInDegArray[i] = vertexInDeg;
    }
    return adjInDegArray;
}

void AdjacencyMatrix::traversalDFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        DFSTraversalRecur(vertex);
    }
    for (int i = 0; i < firstVertex; ++i) {
        DFSTraversalRecur(i);
    }
    visited.clear();
}

void AdjacencyMatrix::sortDFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        DFSSortRecur(vertex);
    }
    for (int i = 0; i < firstVertex; ++i) {
        DFSSortRecur(i);
    }
    for (int item :visited) {
        cout << item;
    }
    visited.clear();
}

void AdjacencyMatrix::traversalBFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        if (!wasVertexVisited(vertex)) {
            BFSTraversalIter(vertex);
        }
    }
    for (int i = 0; i < firstVertex; ++i) {
        if (!wasVertexVisited(i)) {
            BFSTraversalIter(i);
        }
    }
    visited.clear();
}

void AdjacencyMatrix::sortBFS(int vertex) {
    adjInDegArray = returnInDegArray();
    while ((find_if(adjInDegArray.begin(), adjInDegArray.end(), GreaterThanZero)) != (adjInDegArray.end())) {
        for (vertex = 0; vertex < adjInDegArray.size(); ++vertex) {
            // If the vertex has "in" degree == 0
            if (adjInDegArray[vertex] == 0) {
                // Remove all links of this vertex
                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[i][vertex] == 1) {
                        adjInDegArray[i] -= 1;
                        adjInDegArray[vertex] -= 1;
                    }
                }
                cout << vertex;
            }
        }
    }
}

void AdjacencyMatrix::print() {
    cout << "--------- ADJACENCY MATRIX --------- " << endl;
    cout << "------------------------------------ " << endl;
    for (int j = 0; j < adjMatrix.size(); ++j) {
        for (int i = 0; i < adjMatrix.size(); ++i) {
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
}

int AdjacencyMatrix::getSize() {
    return vertexCount;
}

int AdjacencyMatrix::getSaturation() {
    return saturation;
}

vector<vector<int>> AdjacencyMatrix::getAdjMatrix() {
    return adjMatrix;
}



