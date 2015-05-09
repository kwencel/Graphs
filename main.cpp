#include <iostream>
#include "adjacency_matrix.h"
#include "successors_list.h"
using namespace std;

AdjacencyMatrix matrix;
SuccessorsList list;

int main() {
    matrix.print();
    cout << endl;
    cout << "DFS Sort" << endl;
	matrix.sortDFS(0);
    cout << endl;
    cout << "BFS Sort" << endl;
    matrix.sortBFS(0);
    cout << endl;
    cout << "DFS Traversal" << endl;
    matrix.traversalDFS(0);
    cout << endl;
    cout << "BFS Traversal" << endl;
    matrix.traversalBFS(0);
    cout << endl << endl;


    SuccessorsList();
    list.print();
    return 0;
}