#include <iostream>
#include <time.h>
#include "incidence_list.h"

bool IncidenceList::isEdgePresent(int vertex1, int vertex2) {
    for (int item : incList[vertex1]) {
        if (item == vertex2) {
            return true;
        }
    }
    return false;
}

IncidenceList::IncidenceList(int vertexCount, int saturation) {
    this->vertexCount = vertexCount;
    this->saturation = saturation;
    forward_list<int> edgeList;
    // Calculate the maximum number of edges in graph
    int edgesCountMax = ((vertexCount * (vertexCount - 1)) / 2) * saturation / 100;
    int edgesCount = vertexCount;
    // Setting list's iterator on beginning
    for (int vertex = 0; vertex < vertexCount - 1; ++vertex) {
        edgeList.push_front(vertex + 1);
        incList.push_back(edgeList);
        edgeList.clear();
    }
    // Setting the edge between last and first vertex
    edgeList.push_front(0);
    incList.push_back(edgeList);
    edgeList.clear();
    // Setting the edge between first and last vertex
    incList[0].push_front(vertexCount - 1);
    for (int vertex = 1; vertex < vertexCount; ++vertex) {
        incList[vertex].push_front(vertex - 1);
    }
    srand((unsigned int) time(NULL));
    while (edgesCount < edgesCountMax) {
        int vertex1 = rand() % vertexCount;
        int vertex2 = rand() % vertexCount;
        int vertex3 = rand() % vertexCount;
        if (vertex1 == vertex2 || vertex2 == vertex3 ||
            vertex1 == vertex3 || isEdgePresent(vertex1, vertex2) ||
            isEdgePresent(vertex2, vertex3) || isEdgePresent(vertex1, vertex3)) {
            continue;
        }
        incList[vertex1].push_front(vertex2);
        incList[vertex2].push_front(vertex1);
        incList[vertex2].push_front(vertex3);
        incList[vertex3].push_front(vertex2);
        incList[vertex3].push_front(vertex1);
        incList[vertex1].push_front(vertex3);
        edgesCount = edgesCount + 3;
    }
}

void IncidenceList::print() {
    cout << "---------- INCIDENCE LIST ---------- " << endl;
    cout << "------------------------------------ " << endl;
    for (int j = 0; j < incList.size(); ++j) {
        cout << j << ":";
        for (int item : incList[j]) {
            cout << "->" << item;
        }
        cout << endl;
    }
}

int IncidenceList::getSize() {
    return vertexCount;
}
