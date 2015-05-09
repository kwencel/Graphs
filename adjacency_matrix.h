#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

#include <vector>
#include <forward_list>
#include <queue>
using namespace std;

class AdjacencyMatrix {
private:
    int vertexCount;
    int saturation;
    vector<vector<int>> adjMatrix;
    vector<int> adjInDegArray;
    forward_list<int> visited;
    queue<int> BFSqueue;

    bool wasVertexVisited(int vertex);
    void DFSTraversalRecur(int vertex);
    void DFSSortRecur(int vertex);
    void BFSTraversalIter(int vertex);
    vector<int> returnInDegArray();


public:
    AdjacencyMatrix(int vertexCount = 6, int saturation = 50);

    void traversalDFS(int vertex);
    void sortDFS(int vertex);
    void traversalBFS(int vertex);
    void sortBFS(int vertex);
    void print();
    int getSize();
    int getSaturation();
    vector<vector<int>> getAdjMatrix();
};

#endif //GRAPHS_ADJACENCY_MATRIX_H