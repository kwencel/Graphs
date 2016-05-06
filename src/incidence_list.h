#ifndef GRAPHS_INCIDENCE_LIST_H
#define GRAPHS_INCIDENCE_LIST_H

#include <vector>
#include <forward_list>

using namespace std;

class IncidenceList {
private:
    vector <vector<int>> incList;
    vector <vector<int>> incListCopy;
    vector<int> visited;
    vector<int> stack;
    int vertexCount;
    int saturation;

    bool wasVertexVisited(int vertex);

    bool findHamiltonianCycleRecur(int vertex);

    void findEulerianCycleRecur(int vertex);

    void removeEdge(int vertex1, int vertex2, vector <vector<int>>& list);

public:
    IncidenceList(int vertexCount, int saturation);

    void createCircularGraph(int vertexCount);

    void generateConnectedGraph(int vertexCount, int saturation);

    bool isEdgePresent(int vertex1, int vertex2);

    void makeEdge(int vertex1, int vertex2);

    void removeEdge(int vertex1, int vertex2);

    void isolateVertex(int vertex);

    bool findHamiltonianCycle();

    bool findEulerianCycle(int vertex);

    void clearGraph();

    void print();

    int getSize();
};

#endif //GRAPHS_INCIDENCE_LIST_H
