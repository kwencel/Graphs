#ifndef GRAPHS_LIST_OF_EDGES_H
#define GRAPHS_LIST_OF_EDGES_H

#include <vector>
using namespace std;

class ListOfEdges {
private:
    vector<vector<int>> edgeList;      //vector of lists
    vector<int> edge;

public:
    ListOfEdges(int vertexCount = 6);
    void print();
};
#endif //GRAPHS_LIST_OF_EDGES_H
