#ifndef GRAPHS_LIST_OF_EDGES_H
#define GRAPHS_LIST_OF_EDGES_H

#include <vector>
using namespace std;

class ListOfEdges {
private:
    int vertexCount;
    vector<vector<int>> edgeList;
    vector<int> edgeInDegArray;
    forward_list<int> visited;

    bool wasVertexVisited(int vertex);
    void DFSSortRecur(int vertex);
    vector<int> createInDegArray();

public:
    ListOfEdges();
    void sortDFS(int vertex);
    void sortBFS();
    void print();
    vector<int> getInDegArray();
};

#endif //GRAPHS_LIST_OF_EDGES_H
