#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

#include <vector>
#include <forward_list>
#include <queue>

using namespace std;

class AdjacencyMatrix {
private:
    vector <vector<int>> adjMatrix;
    vector<int> adjInDegArray;
    forward_list<int> visited;
    queue<int> BFSqueue;
    int vertexCount;
    int saturation;

    bool wasVertexVisited(int vertex);

    void DFSSortRecur(int vertex);

    void DFSTraversalRecur(int vertex);

    void BFSTraversalIter(int vertex);

    vector<int> createInDegArray();

public:
    AdjacencyMatrix(int vertexCount = 6, int saturation = 50);

    void sortDFS(int vertex);

    void traversalDFS(int vertex);

    void sortBFS();

    void traversalBFS(int vertex);

    void print();

    int getSize();

    int getSaturation();

    vector<int> getInDegArray();

    vector <vector<int>> getAdjMatrix();
};

#endif //GRAPHS_ADJACENCY_MATRIX_H