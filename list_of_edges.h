#ifndef GRAPHS_LIST_OF_EDGES_H
#define GRAPHS_LIST_OF_EDGES_H

#include <vector>
using namespace std;

class ListOfEdges {
private:
    vector<vector<int>> edgeList;
    vector<int> edgeInDegArray;
    forward_list<int> visited;
    int vertexCount;

    bool wasVertexVisited(int vertex);
    void DFSSortRecur(int vertex);
    vector<int> createInDegArray();

public:
    ListOfEdges(AdjacencyMatrix Matrix);
    void sortDFS(int vertex);
    void sortBFS();
    void print();
    int getSize();
    vector<int> getInDegArray();
};

#endif //GRAPHS_LIST_OF_EDGES_H
