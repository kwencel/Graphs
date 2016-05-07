# Graphs
An application for testing the speed of topological sorting and cycle finding algorithms in DAGs.

*DAG - Directed Acyclic Graph*

# Build prerequisites
    CMake 3.2 (it will probably compile using older version too, see the last paragraph)

# Build instructions
```
$ cmake .
$ make
```

# Testing procedure
The program will test the speed of DFS and BFS-like topological sorting and Hamiltonian and Eulerian cycle finding
on multiple graph representations - adjacency matrix, list of edges and successors list.

Each representation will be tested 10 times - every time on a bigger graph.
What is more, each graph instance will be tested in two variants - with 30% and 70% saturation.
By saturation I mean a ratio of edges present in the graph to all possible edges in the graph (clique).

That gives 3 * 10 * 2 = 60 measurements for one algorithm. That's a lot of testing!

# Test results
Testing results will be stored in multiple files for your convenience. You'll find .txt files that are reading-friendly
and .csv files for an easy import to your favourite spreadsheet application.

**WARNING**
Running the program again (even before starting any test) will remove the files storing previous results. Please move these files from the *bin* folder when the program finishes testing.

# Configuration
You can adjust vertices amount used for testing purposes in *define.h* file. You have to do this before compiling the program.

# How to use the program?
Use numeric keys to choose the appropriate test.

**1: Topological sorting algorithms**

The program will test the speed of Depth-first search TS algorithm and BFS-like TS algorithm commonly known as the
Kahn's algorithm.

**2: Hammiltonian and Eulerian Cycles searching**

The program will test the speed of Hamiltonian cycle finding algorithm and Eulerian cycle finding algorithm.

**3: Nonexistent Hammiltonian Cycles searching**

The program will test the speed of Hamiltonian cycle finding algorithm in graphs that don't contain Hamiltonian cycle.
In this case the test will run for a very long time. For this reason it is recommended to lower the vertices amount in
*define.h* file. Alternatively you can switch to *custom* branch where vertices amount is lower and the saturation is set
to 50% and only this case will be tested instead of seperate 30% and 70% instances. This should reduce the time needed
to complete this test.

# Too old CMake version?
Try to change the minimum required version in CMakeLists.txt to match the version you have installed. There shouldn't be any issues.
