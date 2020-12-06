//
// Theng Yang
//

#ifndef _KRUSKAL_HPP_
#define _KRUSKAL_HPP_

#include<map>
#include<unordered_map>
#include<string>

using graphs = std::multimap<int, std::string>;
using tree = std::unordered_map<char, int>;

struct simpleUnionFind{
    explicit simpleUnionFind(const graphs & graph);
    void resetSet(int value, int newValue);
    void join (const std::string& edge, int set);
    auto isAcylic(const std::string & edge);

    tree _tree_;
};

auto kruskal (const graphs & graph)-> graphs;

#endif //_KRUSKAL_HPP_
