#include <iostream>
#include <ctime>
#include <algorithm>
#include "incidence_list.h"

bool IncidenceList::isEdgePresent(int vertex1, int vertex2) {
    for (int adjacentVertex : incList[vertex1]) {
        if (adjacentVertex == vertex2) {
            return true;
        }
    }
    return false;
}

void IncidenceList::makeEdge(int vertex1, int vertex2) {
    if (!isEdgePresent(vertex1, vertex2)) {
        incList[vertex1].push_front(vertex2);
        incList[vertex2].push_front(vertex1);
    }
}

void IncidenceList::removeEdge(int vertex1, int vertex2) {
    if (isEdgePresent(vertex1, vertex2)) {
        incList[vertex1].remove(vertex2);
        incList[vertex2].remove(vertex1);
    }
}

void IncidenceList::clearGraph() {
    incList.clear();
}

bool IncidenceList::wasVertexVisited(int vertex) {
    return find(visited.begin(), visited.end(), vertex) != visited.end();
}

void IncidenceList::createCircularGraph(int vertexCount) {
    this->vertexCount = vertexCount;
    this->saturation = saturation;
    incList.resize(vertexCount);
    // Setting list's iterator on beginning
    for (int vertex = 0; vertex < vertexCount - 1; ++vertex) {
        makeEdge(vertex, vertex + 1);
    }
    // Setting the edge between last and first vertex
    makeEdge(vertexCount - 1, 0);
    // Setting the edge between first and last vertex
    makeEdge(0, vertexCount - 1);
    for (int vertex = 1; vertex < vertexCount; ++vertex) {
        makeEdge(vertex, vertex - 1);
    }
}

void IncidenceList::generateConnectedGraph(int vertexCount, int saturation) {
    createCircularGraph(vertexCount);
    // Calculate the maximum number of edges in graph
    int edgesCountMax = ((vertexCount * (vertexCount - 1)) / 2) * saturation / 100;
    int edgesCount = vertexCount;
    // Fill the graph with random triangles until given saturation is reached
    srand((unsigned int) time(NULL));
    while (edgesCount < edgesCountMax) {
        int vertex1 = rand() % vertexCount;
        int vertex2 = rand() % vertexCount;
        int vertex3 = rand() % vertexCount;
        if (vertex1 == vertex2 ||
            vertex2 == vertex3 ||
            vertex1 == vertex3 ||
            isEdgePresent(vertex1, vertex2) ||
            isEdgePresent(vertex2, vertex3) ||
            isEdgePresent(vertex1, vertex3)) {
            continue;
        }
        makeEdge(vertex1, vertex2);
        makeEdge(vertex2, vertex3);
        makeEdge(vertex3, vertex1);
        edgesCount = edgesCount + 3;
    }
}

IncidenceList::IncidenceList(int vertexCount, int saturation) {
    generateConnectedGraph(vertexCount, saturation);
}

bool IncidenceList::findHamiltonianCycleRecur(int vertex) {
    visited.push_back(vertex);
    for (int currentVertex : incList[vertex]) {
        if (wasVertexVisited(currentVertex)) {
            continue;
        }
        findHamiltonianCycleRecur(currentVertex);
    }
    if ((visited.size() == vertexCount) && (isEdgePresent(visited.front(), visited.back()))) {
        return true;
    } else {
        visited.pop_back();
        return false;
    }
}

bool IncidenceList::findHamiltonianCycle() {
    bool result = findHamiltonianCycleRecur(0);
    if (result) {
        for (int vertex : visited) {
            cout << vertex << "->";
        }
        cout << visited.front() << endl;
    }
    visited.clear();
    return result;
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
