#ifndef GRAPHS_SUCCESSORS_LIST_H
#define GRAPHS_SUCCESSORS_LIST_H

#include <vector>
#include <forward_list>

using namespace std;

class SuccessorsList {
private:
    vector <forward_list<int>> adjList;
    vector<int> listInDegArray;
    forward_list<int> visited;
    int vertexCount;

    bool wasVertexVisited(int vertex);

    void DFSSortRecur(int vertex);

    vector<int> createInDegArray();

public:
    SuccessorsList(AdjacencyMatrix Matrix);

    void sortDFS(int vertex);

    void sortBFS();

    void print();

    int getSize();

    vector<int> getInDegArray();
};

#endif //GRAPHS_SUCCESSORS_LIST_H

