#ifndef GRAPHS_ADJACENCY_MATRIX_H
#define GRAPHS_ADJACENCY_MATRIX_H

void AdjMatrixCreate(int vertexCount, int saturation);
void AdjMatrixDFSTraversal(int vertex);
void AdjMatrixBFSTraversal(int vertex);
void AdjMatrixDFSSort(int vertex);
void AdjMatrixBFSSort(int vertex);
void AdjMatrixPrint();

#endif //GRAPHS_ADJACENCY_MATRIX_H