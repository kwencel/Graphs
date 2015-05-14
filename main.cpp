#include <iostream>
#include "adjacency_matrix.h"
#include "successors_list.h"
#include "list_of_edges.h"
using namespace std;

AdjacencyMatrix matrix;
SuccessorsList list;
ListOfEdges edges;

int main() {

    matrix.print();
    cout << endl << "DFS Sort" << endl;
	matrix.sortDFS(0);
    cout << endl << "BFS Sort" << endl;
    matrix.sortBFS();
    //cout << endl << "DFS Traversal" << endl;
    //matrix.traversalDFS(0);
    //cout << endl << "BFS Traversal" << endl;
    //matrix.traversalBFS(0);
    cout << endl << endl;

    list.print();
    cout << endl << "DFS Sort" << endl;
    list.sortDFS(0);
    cout << endl << "BFS Sort" << endl;
    list.sortBFS();
    cout << endl << endl;

    edges.print();
    cout << endl << "DFS Sort" << endl;
    edges.sortDFS(0);
    cout << endl << "BFS Sort" << endl;
    edges.sortBFS();

    return 0;
}