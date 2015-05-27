//#include <iostream>
//#include "adjacency_matrix.h"
//#include "successors_list.h"
//#include "list_of_edges.h"
#include <iostream>
#include "incidence_list.h"
//using namespace std;

//AdjacencyMatrix Matrix;
//SuccessorsList List(Matrix);
//ListOfEdges Edges(Matrix);
IncidenceList HamiltonTest(6, 30);
IncidenceList Hamilton30(9, 50);
IncidenceList Hamilton70(9, 70);

int main() {

//    HamiltonTest.clearGraph();
//    HamiltonTest.createCircularGraph(6);
//    HamiltonTest.makeEdge(0,2);
//    HamiltonTest.print();
//    HamiltonTest.removeEdge(2,0);
//    HamiltonTest.print();

    Hamilton30.print();
    cout << endl;
    Hamilton30.removeEdge(0, 8);

    if (Hamilton30.findHamiltonianCycle())
        cout << "Hamiltonian cycle is present.";
    else
        cout << "Hamiltonian cycle is not present.";

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