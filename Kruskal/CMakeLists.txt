cmake_minimum_required(VERSION 3.16)
project(Kruskal)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kruskal test.cpp quickFind.cpp quickUnion.cpp simpleUnionFind.cpp unionFind.hpp kruskal.hpp)