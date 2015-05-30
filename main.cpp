#include <iostream>
#include "testing_sorting.h"
#include "testing_cycles.h"
//#include "adjacency_matrix.h"
//#include "successors_list.h"
//#include "list_of_edges.h"
//#include "incidence_list.h"
using namespace std;

int main() {

    while (true) {
        cout << "Choose your prefered testing option and press Enter." << endl;
        cout << "----------------------------------------------------" << endl;
        cout << " 1:    Topological sorting algorithms               " << endl;
        cout << " 2:    Hammiltonian and Eulerian Cycles searching   " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Press any other key to run all tests or 'q' to quit." << endl << endl;
        char choice = '2';
        cout << "Your choice: ";
//        cin >> choice;
//        cout << endl;

        switch (choice) {
            case '1':
                BeginTestingSorting();
                break;
            case '2':
                BeginTestingCycles();
                getchar();
                break;
            case 'q':
                exit(0);
            default:
                BeginTestingSorting();
                BeginTestingCycles();
                break;
        }
        cout << string(5, '\n');
    }

//    AdjacencyMatrix Matrix;
//    SuccessorsList List(Matrix);
//    ListOfEdges Edges(Matrix);
//    IncidenceList Graph30(20, 30);
//    IncidenceList Graph70(20, 70);
//
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
//
//    if (Graph30.findHamiltonianCycle())
//        cout << "Hamiltonian cycle is present." << endl;
//    else
//        cout << "Hamiltonian cycle is not present." << endl;
//
//    if (Graph30.findEulerianCycle(0))
//        cout << "Eulerian cycle is present." << endl;
//    else
//        cout << "Eulerian cycle is not present." << endl;
//
//    return 0;

}