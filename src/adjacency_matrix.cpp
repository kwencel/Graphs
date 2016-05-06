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
    adjMatrix.resize((unsigned long) vertexCount, vector<int>((unsigned long) vertexCount, 0));
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
 }

bool AdjacencyMatrix::wasVertexVisited(int vertex) {
    return find(visited.begin(), visited.end(), vertex) != visited.end();
}

vector<int> AdjacencyMatrix::createInDegArray() {
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

void AdjacencyMatrix::sortDFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < adjMatrix.size(); ++vertex) {
        DFSSortRecur(vertex);
    }
    for (int i = 0; i < firstVertex; ++i) {
        DFSSortRecur(i);
    }
//    for (int item :visited) {
//        cout << item << endl;
//    }
    visited.clear();
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

void AdjacencyMatrix::sortBFS() {
    createInDegArray();
    while ((find_if(adjInDegArray.begin(), adjInDegArray.end(), GreaterThanZero)) != (adjInDegArray.end())) {
        for (int vertex = 0; vertex < adjInDegArray.size(); ++vertex) {
            // If the vertex has "in" degree == 0
            if (adjInDegArray[vertex] == 0) {
                // Remove all links of this vertex
                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[i][vertex] == 1) {
                        adjInDegArray[i] -= 1;
                        adjInDegArray[vertex] -= 1;
                    }
                }
//                cout << vertex << endl;
            }
        }
    }
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

vector<int> AdjacencyMatrix::getInDegArray() {
    return createInDegArray();
}
