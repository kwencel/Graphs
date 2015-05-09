#include <iostream>
#include "adjacency_matrix.h"
#include "successors_list.h"

using namespace std;

int main() {
    AdjMatrixCreate(6,50);
    //AdjMatrixPrint();
    cout << "DFS Sort" << endl;
	AdjMatrixDFSSort(0);
    cout << endl;
    cout << "BFS Sort" << endl;
    AdjMatrixBFSSort(0);
    cout << endl;
    cout << "DFS Traversal" << endl;
    AdjMatrixDFSTraversal(0);
    cout << endl;
    cout << "BFS Traversal" << endl;
    AdjMatrixBFSTraversal(0);
    cout << endl;
    SuccListCreate(6);
    SuccListPrint();
    return 0;
}