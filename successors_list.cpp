#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>
#include "adjacency_matrix.h"
#include "successors_list.h"
using namespace std;

extern AdjacencyMatrix matrix;

SuccessorsList::SuccessorsList(int vertexCount) {
    for (int row = 0; row < vertexCount; ++row) {
        // setting list's iterator on beginning
        currentVertex = succList.begin();
        // adding main vertex to list
        currentVertex = succList.insert_after(succList.before_begin(), row);
        // accessing the adjacency matrix and making a temporary copy
        vector<vector<int>> adjMatrix = matrix.getAdjMatrix();
        for (int column = 0; column < vertexCount; ++column) {
            if ((adjMatrix[column][row]) == 1) {
                // adding vertex to list
                currentVertex = succList.insert_after(currentVertex, column);
            }
        }
        // adding list to vector
        adjList.push_back(succList);
        // clearing list to reusing
        succList.clear();
    }
}

void SuccessorsList::print() {
    cout << "--------- SUCCESSORS LIST ---------- " << endl;
    cout << "------------------------------------ " << endl;
    for (int j = 0; j < adjList.size(); ++j) {
        /*forward_list<int>::iterator cur;
        for (cur = adjList[j].begin(); cur != adjList[j].end(); cur++ )
            cout << *cur << " ";*/
        for (auto item : adjList[j]) {
            cout << item << " ";
        }
        cout << endl;
    }
}

/*
void SuccListCreate(int VertexCount) {
    for (int row = 0; row < VertexCount; ++row) {
        // setting list's iterator on beginning
        currentVertex = succList.begin();
        int firstVertex = row + 1;
        // adding main vertex to list
        currentVertex = succList.insert_after (succList.before_begin(), firstVertex);
        for (int column = 0; column < VertexCount; ++column) {
            if ((adjMatrix[column][row]) == 1) {
                int successorAdd = column + 1;
                // adding vertex to list
                currentVertex = succList.insert_after (currentVertex, successorAdd);
            }
        }
        // adding list to vector
        adjList.push_back(succList);
        // clearing list to reusing
        succList.clear();
    }
}
*/