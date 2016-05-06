#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "define.h"
#include "adjacency_matrix.h"
#include "successors_list.h"
#include "list_of_edges.h"

using namespace std;
using namespace chrono;

void BeginTestingSorting() {
    typedef high_resolution_clock Clock;
    int arrHowMany[10] = {MAX1, MAX2, MAX3, MAX4, MAX5, MAX6, MAX7, MAX8, MAX9, MAX10};
    vector<string> arrSortName = {"DFS","BFS"};
    vector<string> arrRepName = {"Adjacency Matrix", "Successors List", "List of Edges"};

    // Preparing .txt and .csv files to save logs
    for (int rep = 0; rep < 3; ++rep) {
        string fileName = "_LOG " + arrRepName[rep] + ".txt";
        string rawFileName = "_EXCEL " + arrRepName[rep] + ".csv";
        ofstream filePath;
        filePath.open(fileName.c_str(), ofstream::out | ofstream::trunc); // Clear file
        filePath << "----------- " << arrRepName[rep] << " -----------" << endl;
        filePath.close();
        ofstream rawFilePath;
        rawFilePath.open(rawFileName.c_str(), ofstream::out | ofstream::trunc);
        rawFilePath << "Sort type,Data amount,Time elapsed\n";
        rawFilePath.close();
    }

    // Main testing loop
    for (int vertexAmount = 0; vertexAmount < 10; ++vertexAmount) { // Vertices amount

        int howMany = arrHowMany[vertexAmount];
        cout << "Generating " << howMany << "-vertex graph..." << endl << endl;
        AdjacencyMatrix Matrix(howMany, 50);
        SuccessorsList List(Matrix);
        ListOfEdges Edges(Matrix);

        for (int rep = 0; rep < 3; ++rep) { // Graph representation type

            string repName = arrRepName[rep];
            string fileName = "_LOG " + arrRepName[rep] + ".txt";
            string rawFileName = "_EXCEL " + arrRepName[rep] + ".csv";
            ofstream filePath;
            ofstream rawFilePath;
            cout << "----------- " << repName << " -----------" << endl;

            for (int sortType = 0; sortType < 2; ++sortType) {  // Topological sort type

                string sortName = arrSortName[sortType];
                cout << "Sorting " << sortName << " " << howMany << "-vertex graph..." << endl;

                auto start = Clock::now();

                switch (sortType) {
                    case 0: // DFS
                        switch (rep) {
                            case 0:
                                Matrix.sortDFS(0);
                                break;
                            case 1:
                                List.sortDFS(0);
                                break;
                            case 2:
                                Edges.sortDFS(0);
                                break;
                            default:break;
                        }
                        break;
                    case 1: // BFS
                        switch (rep) {
                            case 0:
                                Matrix.sortBFS();
                                break;
                            case 1:
                                List.sortBFS();
                                break;
                            case 2:
                                Edges.sortBFS();
                                break;
                            default:break;
                        }
                        break;
                    default:break;
                }

                auto end = Clock::now();
                auto duration = duration_cast<milliseconds>(end - start);

                cout << "Time elapsed: " << duration.count() / 1000.0 << " seconds." << endl;

                filePath.open(fileName.c_str(), ofstream::out | ofstream::app);   // Append to file
                filePath << "Completed sorting " << sortName << " " << repName << " " << howMany << "-vertex graph in " << duration.count() / 1000.0 << " seconds." << endl;
                filePath.close();
                rawFilePath.open(rawFileName.c_str(), ofstream::out | ofstream::app);
                rawFilePath << sortName << "," << howMany << "," << duration.count() / 1000.0 << endl;
                rawFilePath.close();
            }
            auto len = repName.length();
            repName.clear();
            for (int i = 0; i < len + 2; ++i) {
                repName.append("-");
            }
            cout << "Results has been saved to file " << fileName << endl;
            cout << "-----------" << repName << "-----------" << endl << endl;
        }
    }
}
