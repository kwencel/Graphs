#include <iostream>
#include "adjacency_matrix.h"

using namespace std;

int main() {
    AdjMatrixCreate(6);
    AdjMatrixPrint();
    cout << endl;
	AdjMatrixDFSSort(0);
    cout << endl;
    AdjMatrixBFSSort(0);
    return 0;
}