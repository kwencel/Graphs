#include <iostream>
#include "adjacency_matrix.h"
#include "successors_list.h"

using namespace std;

int main() {
    AdjMatrixCreate(6);
    AdjMatrixPrint();
    cout << endl;
	AdjMatrixDFSSort(0);
    cout << endl;
    AdjMatrixBFSSort(0);
    cout << endl;
    SuccListCreate(6);
    SuccListPrint();
    return 0;
}