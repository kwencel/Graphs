#ifndef GRAPHS_SUCCESSORS_LIST_H
#define GRAPHS_SUCCESSORS_LIST_H

#include <vector>
#include <forward_list>
using namespace std;

class SuccessorsList {
private:
    int vertexCount;
    vector<forward_list<int>> adjList;                // vector of lists
    forward_list<int> succList;                       // list of successors
    forward_list<int>::iterator currentVertex;        // pointer in list

public:
    SuccessorsList(int vertexCout = 6);

    void print();
};

#endif //GRAPHS_SUCCESSORS_LIST_H

