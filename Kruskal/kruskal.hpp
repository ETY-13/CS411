// kruskal.hpp
// Theng Yang
// 2020.12.26

#ifndef UnionFind_KRUSKAL_HPP
#define UnionFind_KRUSKAL_HPP

#include "unionFind.hpp"

#include<map>

// Kruskal's algorithm--making use of UnionFind data structures
// Static assertion:
//  kruskal must be called with an UnionFind data structure
//  as datatype -- either SimpleUnionFind, QuickFind, or QuickUnion.
template<typename unionFind>
auto kruskal(const std::multimap<int, std::string> & graph)->std::multimap<int, std::string> {
    // Cause compile error if no UnionFind data structure was specified
    static_assert(std::is_base_of<SimpleUnionFind, unionFind>::value, "kruskal<DataType> :: 'DataType' is not a UnionFind");

    std::multimap<int, std::string> spanningTree;
    unionFind set;

    for(const auto & edges:graph) {

        if (set.noset(edges.second[0])) {
            set.makeset(edges.second[0]);
        }

        if (set.noset(edges.second[1])) {
            set.makeset((edges.second[1]));
        }

        if(set.isAcyclic(edges.second[0], edges.second[1])){
            set.merge(edges.second[0], edges.second[1]);
            spanningTree.insert(edges);
        }
    }

    return spanningTree;
}


#endif //UnionFind_KRUSKAL_HPP
