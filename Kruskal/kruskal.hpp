// kruskal.hpp
// Theng Yang
// 12/13/2020

// header file for kruskal

#ifndef _KRUSKAL_HPP_
#define _KRUSKAL_HPP_

#include<map>
#include<unordered_map>
#include<string>

using graphs = std::multimap<int, std::string>;
using tree = std::unordered_map<char, int>;

// A simple data structure that checks for cycles
// and join vertices together with a given edge.
struct simpleUnionFind{
    explicit simpleUnionFind(const graphs & graph);
    void resetSet(int value, int newValue);
    void join (const std::string& edge, int set);
    auto isAcylic(const std::string & edge);

    tree _tree_;
};

auto kruskal (const graphs & graph)-> graphs;

#endif //_KRUSKAL_HPP_
