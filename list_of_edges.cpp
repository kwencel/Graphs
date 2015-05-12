#include <iostream>
#include <vector>
#include <algorithm>
#include "adjacency_matrix.h"
#include "list_of_edges.h"
#include "utils.h"
using namespace std;

extern AdjacencyMatrix matrix;

ListOfEdges::ListOfEdges() {
    vertexCount = matrix.getSize();
    vector<vector<int>> adjMatrix = matrix.getAdjMatrix();
    vector<int> edge;
    for (int row = 0; row < vertexCount; ++row) {
        for (int column = 0; column < vertexCount; ++column) {
            if ((adjMatrix[column][row]) == 1) {
                edge.push_back(row);
                edge.push_back(column);
                edgeList.push_back(edge);
                edge.clear();
            }
        }
    }
}

bool ListOfEdges::wasVertexVisited(int vertex) {
    return !(find(visited.begin(), visited.end(), vertex) == visited.end());
}

vector<int> ListOfEdges::createInDegArray() {
    edgeInDegArray.resize(vertexCount);
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
        int vertexInDeg = 0;
        for (int edge = 0; edge < edgeList.size(); ++edge) {
            // Calculate in(vertex) degree [vertex - current vertex]
            if (edgeList[edge][1] == vertex) { // [1] - "in" degree
                ++vertexInDeg;
            }
        }
        edgeInDegArray[vertex] = vertexInDeg;
    }
    return edgeInDegArray;
}

void ListOfEdges::DFSSortRecur(int vertex) {
    if (wasVertexVisited(vertex)) {
        return;
    }
    for (int edge = 0; edge < edgeList.size(); ++edge) {
        if (edgeList[edge][0] == vertex) {   // [0] - Out [1] - In
            DFSSortRecur(edgeList[edge][1]);
        }
    }
    visited.push_front(vertex);
}

void ListOfEdges::sortDFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < vertexCount; ++vertex) {
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

void ListOfEdges::sortBFS(int vertex) {
    createInDegArray();
    while ((find_if(edgeInDegArray.begin(), edgeInDegArray.end(), GreaterThanZero)) != (edgeInDegArray.end())) {
        for (vertex = 0; vertex < edgeInDegArray.size(); ++vertex) {
            // If the vertex has "in" degree == 0
            if (edgeInDegArray[vertex] == 0) {
                // Remove all links of this vertex
                for (int edge = 0; edge < edgeList.size(); ++edge) {
                    if (edgeList[edge][0] == vertex) {
                        edgeInDegArray[edgeList[edge][1]] -= 1;
                        edgeInDegArray[edgeList[edge][0]] -= 1;
                        edgeList[edge].clear();
                    }
                }
                cout << vertex;
            }
        }
    }
}

void ListOfEdges::print() {
    cout << "--------- LIST OF EDGES ------------ " << endl;
    cout << "------------------------------------ " << endl;
    cout << "Edge   Out In\n";
    for (int j=0; j < edgeList.size(); ++j) {
        cout << j << "\t";
        for (int item: edgeList[j]) {
            cout << item << "  ";
        }
        cout << endl;
    }
}


vector<int> ListOfEdges::getInDegArray() {
    return createInDegArray();
}
