#ifndef GRAPHS_SUCCESSORS_LIST_H
#define GRAPHS_SUCCESSORS_LIST_H

#include <vector>
#include <forward_list>
using namespace std;

class SuccessorsList {
private:
    int vertexCount;
    vector<forward_list<int>> adjList;
    forward_list<int> succList;
    forward_list<int> visited;
    vector<int> listInDegArray;

    void DFSSortRecur(int vertex);
    bool wasVertexVisited(int vertex);
    vector<int> createInDegArray();

public:
    SuccessorsList(int vertexCout = 6);
    void sortDFS(int vertex);
    void sortBFS();
    void print();

};

#endif //GRAPHS_SUCCESSORS_LIST_H

