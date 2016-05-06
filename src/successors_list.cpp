#include <iostream>
#include <vector>
#include <forward_list>
#include <algorithm>
#include "adjacency_matrix.h"
#include "successors_list.h"
#include "utils.h"
using namespace std;

SuccessorsList::SuccessorsList(AdjacencyMatrix Matrix) {
    this->vertexCount = Matrix.getSize();
    forward_list<int> succList;
    forward_list<int>::iterator currentVertex;
    for (int row = 0; row < vertexCount; ++row) {
        // Setting list's iterator on beginning
        currentVertex = succList.before_begin();
        // Accessing the adjacency matrix and making a temporary copy
        vector<vector<int>> adjMatrix = Matrix.getAdjMatrix();
        for (int column = 0; column < vertexCount; ++column) {
            if ((adjMatrix[column][row]) == 1) {
                // Adding vertex to list
                currentVertex = succList.insert_after(currentVertex, column);
            }
        }
        // Adding list to vector
        adjList.push_back(succList);
        // Clearing list to reusing
        succList.clear();
    }
}

bool SuccessorsList::wasVertexVisited(int vertex) {
    return find(visited.begin(), visited.end(), vertex) != visited.end();
}

vector<int> SuccessorsList::createInDegArray() {
    listInDegArray.resize((unsigned long) vertexCount);
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
        int vertexInDeg = 0;
        for (int row = 0; row < vertexCount; ++row) {
            for (int currentVertex: adjList[row]) {
                // Calculate in(vertex) degree [vertex - current vertex]
                if (currentVertex == vertex) {
                    ++vertexInDeg;
                }
            }
        }
        listInDegArray[vertex] = vertexInDeg;
    }
    return listInDegArray;
}

void SuccessorsList::DFSSortRecur(int vertex) {
    if (wasVertexVisited(vertex)) {
        return;
    }
    for (int currentVertex: adjList[vertex]) {
        DFSSortRecur(currentVertex);
    }
    visited.push_front(vertex);
}

void SuccessorsList::sortDFS(int vertex) {
    int firstVertex = vertex;
    for (vertex; vertex < vertexCount; ++vertex) {
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

void SuccessorsList::sortBFS() {
    createInDegArray();
    while ((find_if(listInDegArray.begin(), listInDegArray.end(), GreaterThanZero)) != (listInDegArray.end())) {
        for (int vertex = 0; vertex < listInDegArray.size(); ++vertex) {
            // If the vertex has "in" degree == 0
            if (listInDegArray[vertex] == 0) {
                // Remove all links of this vertex
                for (int currentSuccessor: adjList[vertex]) {
                    listInDegArray[currentSuccessor] -= 1;
                    listInDegArray[vertex] -= 1;
                }
//                cout << vertex << endl;
            }
        }
    }
}

void SuccessorsList::print() {
    cout << "--------- SUCCESSORS LIST ---------- " << endl;
    cout << "------------------------------------ " << endl;
    for (int j = 0; j < adjList.size(); ++j) {
//        forward_list<int>::iterator cur;
//        for (cur = adjList[j].begin(); cur != adjList[j].end(); cur++ )
//            cout << *cur << " ";
        cout << j << ":";
        for (int item : adjList[j]) {
            cout << "->" << item;
        }
        cout << endl;
    }
}

int SuccessorsList::getSize() {
    return vertexCount;
}

vector<int> SuccessorsList::getInDegArray() {
    return listInDegArray;
}
