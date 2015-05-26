//#include <iostream>
//#include "adjacency_matrix.h"
//#include "successors_list.h"
//#include "list_of_edges.h"
#include "incidence_list.h"
//using namespace std;

//AdjacencyMatrix Matrix;
//SuccessorsList List(Matrix);
//ListOfEdges Edges(Matrix);
IncidenceList Hamilton30(9, 50);
IncidenceList Hamilton70(9, 70);

int main() {

    Hamilton30.print();
    Hamilton70.print();

//    BeginTestingAll();

//    Matrix.print();
//    cout << endl << "DFS Sort" << endl;
//    Matrix.sortDFS(0);
//    cout << endl << "BFS Sort" << endl;
//    Matrix.sortBFS();
//    cout << endl << "DFS Traversal" << endl;
//    Matrix.traversalDFS(0);
//    cout << endl << "BFS Traversal" << endl;
//    Matrix.traversalBFS(0);
//    cout << endl << endl;
//
//    List.print();
//    cout << endl << "DFS Sort" << endl;
//    List.sortDFS(0);
//    cout << endl << "BFS Sort" << endl;
//    List.sortBFS();
//    cout << endl << endl;
//
//    Edges.print();
//    cout << endl << "DFS Sort" << endl;
//    Edges.sortDFS(0);
//    cout << endl << "BFS Sort" << endl;
//    Edges.sortBFS();

    return 0;
}