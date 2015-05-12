#include <iostream>
#include <vector>
#include <algorithm>
#include "adjacency_matrix.h"
#include "list_of_edges.h"
using namespace std;

extern AdjacencyMatrix matrix;

ListOfEdges::ListOfEdges(int vertexCount) {
    vector<vector<int>> adjMatrix = matrix.getAdjMatrix();
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

void ListOfEdges::print() {
    cout << "--------- LIST OF EDGES ------------ " << endl;
    cout << "------------------------------------ " << endl;
    cout << "Edge   out in\n";
    for (int j=0; j < edgeList.size(); ++j) {
        cout << j << "\t";
        for (auto item: edgeList[j]) {
            cout << item << "  ";
        }
        cout << endl;
    }
}