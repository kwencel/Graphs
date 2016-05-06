#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "define.h"
#include "incidence_list.h"
#include "utils.h"

using namespace std;
using namespace chrono;

void BeginTestingCycles(bool mode) {
    typedef high_resolution_clock Clock;
    vector<int> arrHowMany;
    if (mode) {
        arrHowMany = {MAX21, MAX22, MAX23, MAX24, MAX25, MAX26, MAX27, MAX28, MAX29, MAX30};
    } else {
        arrHowMany = {MAX11, MAX12, MAX13, MAX14, MAX15, MAX16, MAX17, MAX18, MAX19, MAX20};
    }
    vector <string> arrSortName = {"Hamiltonian Cycle", "Eulerian Cycle"};
    vector <string> arrRepName = {"Incidence List 30% Saturation", "Incidence List 70% Saturation"};
    if (mode) {
        arrRepName[0] = "Incidence List 50% Saturation";
    }
    string fileName;
    string rawFileName;

    // Preparing .txt and .csv files to save logs
    for (int rep = 0; rep < arrRepName.size(); ++rep) {
        if (mode) {
            fileName = "_LOG Hamilton Isolated " + arrRepName[rep] + ".txt";
            rawFileName = "_EXCEL Hamilton Isolated " + arrRepName[rep] + ".csv";
        } else {
            fileName = "_LOG " + arrRepName[rep] + ".txt";
            rawFileName = "_EXCEL " + arrRepName[rep] + ".csv";
        }
        ofstream filePath;
        filePath.open(fileName.c_str(), ofstream::out | ofstream::trunc); // Clear file
        filePath << "----------- " << arrRepName[rep] << " -----------" << endl;
        filePath.close();
        ofstream rawFilePath;
        rawFilePath.open(rawFileName.c_str(), ofstream::out | ofstream::trunc);
        rawFilePath << "Cycle type,Data amount,Time elapsed\n";
        rawFilePath.close();
    }

    // Main testing loop
    for (int vertexAmount = 0; vertexAmount < 10; ++vertexAmount) { // Vertices amount

        int howMany = arrHowMany[vertexAmount];

        if (!mode)
            cout << "Generating 30% saturated " << howMany << "-vertex graph..." << endl;
        IncidenceList Graph30(howMany, 30);
        if (!mode)
            cout << "Generating 70% saturated " << howMany << "-vertex graph..." << endl;
        IncidenceList Graph70(howMany, 70);
        if (mode)
            cout << "Generating 50% saturated " << howMany << "-vertex graph..." << endl;
        IncidenceList Graph50(howMany, 50);
        cout << endl;
        if (mode) {
            Graph30.clearGraph();
            Graph70.clearGraph();
            Graph50.isolateVertex(RandomBetween(0, Graph50.getSize() - 1));
        } else {
            Graph50.clearGraph();
        }

        for (int rep = 0; rep < arrRepName.size() - mode; ++rep) { // Graph saturation level [0 = 30%, 1 = 70%]
            if (mode) {
                fileName = "_LOG Hamilton Isolated " + arrRepName[rep] + ".txt";
                rawFileName = "_EXCEL Hamilton Isolated " + arrRepName[rep] + ".csv";
            } else {
                fileName = "_LOG " + arrRepName[rep] + ".txt";
                rawFileName = "_EXCEL " + arrRepName[rep] + ".csv";
            }

            string repName = arrRepName[rep];
            ofstream filePath;
            ofstream rawFilePath;
            cout << "----------- " << repName << " -----------" << endl;

            for (int sortType = 0; sortType < arrSortName.size() - mode; ++sortType) { // Type of cycle to detect

                string sortName = arrSortName[sortType];
                cout << "Searching " << sortName << " in " << howMany << "-vertex graph..." << endl;

                auto start = Clock::now();

                switch (sortType) {
                    case 0: // Hamiltonian Cycle
                        switch (rep) {
                            case 0:
                                if (mode) {
                                    Graph50.findHamiltonianCycle();
                                } else {
                                    Graph30.findHamiltonianCycle();
                                }
                                break;
                            case 1:
                                Graph70.findHamiltonianCycle();
                                break;
                            default:
                                break;
                        }
                        break;
                    case 1: // Eulerian Cycle
                        switch (rep) {
                            case 0:
                                Graph30.findEulerianCycle(0);
                                break;
                            case 1:
                                Graph70.findEulerianCycle(0);
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }

                auto end = Clock::now();
                auto duration = duration_cast<milliseconds>(end - start);

                cout << "Time elapsed: " << duration.count() / 1000.0 << " seconds." << endl;

                filePath.open(fileName.c_str(), ofstream::out | ofstream::app);   // Append to file
                filePath << "Completed searching " << sortName << "\t" << " in " << repName << " " << howMany <<
                "-vertex graph in " << duration.count() / 1000.0 << " seconds." << endl;
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
