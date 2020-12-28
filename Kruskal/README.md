This is a simple implementation of Kruskal's Algorithm. The function of use is kruskal(), 
which takes a multimap<int, string> that represents a weighted graph. 
The function returns a multimap<int, string> that represents the minimum spanning tree.
kruskal() is defined in kruskal.hpp. 

When calling kruskal(), a Union-Find data structure must be specified, such as kruskal<quickFind>.
 
There are three simple Union-Find data structures (simpleUnionFind, quickFind, quickUnion) that are
decleared in unionFind.hpp and defined in simpleUnionFind.cpp, quickFind.cpp, quickUnion.cpp, respectively.

A simple test is provided in test.cpp, which made use of the doctest framework. 
Note that all files, including doctest.h, is required to run the test. 
