#ifndef GRAPHS_INCIDENCE_LIST_H
#define GRAPHS_INCIDENCE_LIST_H

#include <vector>
#include <forward_list>

using namespace std;

class IncidenceList {
private:
    vector<forward_list<int>> incList;
    int vertexCount;
    int saturation;

public:
    IncidenceList(int vertexCount, int saturation);

    bool isEdgePresent(int vertex1, int vertex2);

    void print();

    int getSize();
};


#endif //GRAPHS_INCIDENCE_LIST_H
