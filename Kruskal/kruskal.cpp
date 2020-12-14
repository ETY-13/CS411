// kruskal.cpp
// Theng Yang
// 12/13/2020

// Source file for kruskal: a simple implementation of Kruskal's algorithm.

#include "kruskal.hpp"

simpleUnionFind::simpleUnionFind(const graphs &graph) {

    for (auto const& edge : graph) {
        if (_tree_.find(edge.second[0]) == _tree_.end()) {
            _tree_.insert({ edge.second[0], -1 });
        }
        if (_tree_.find(edge.second[1]) == _tree_.end()) {
            _tree_.insert({ edge.second[1], -1 });
        }
    }

}

// Set all the vertices in a set into another set.
 void  simpleUnionFind::resetSet(int value, int newValue) {

     for(auto & tree :_tree_){
         if(tree.second == value){
             tree.second = newValue;
         }
     }
}

// A function that join vertices together with a given edge
 void simpleUnionFind::join(const std::string &edge, int set) {

     if( _tree_[edge[0]] == -1 && _tree_[edge[1]] == -1){
         _tree_[edge[0]] = set;
         _tree_[edge[1]] = set;
     }
     else if(_tree_[edge[0]]== -1){
         _tree_[edge[0]] = _tree_[edge[1]];
     }
     else if(_tree_[edge[1]] == -1){
         _tree_[edge[1]] = _tree_[edge[0]];
     }
     else if(_tree_[edge[0]] < _tree_[edge[1]]){
         resetSet(_tree_[edge[0]], _tree_[edge[1]]);
     }
     else{
         resetSet(_tree_[edge[1]], _tree_[edge[0]]);
     }

}

// A function that checks if an edge will create a cycle.
auto simpleUnionFind::isAcylic(const std::string &edge)  {

    // cycle exists if the vertices are in the same set
    if(_tree_[edge[0]] == -1 || _tree_[edge[1]] == -1){
        return true;
    }
    return (_tree_[edge[0]] != _tree_[edge[1]]);
}

// A function that given a weighted graph,
// returns a minimum spanning tree.
auto kruskal (const graphs & graph)-> graphs{

    auto setCounter = 0;
    simpleUnionFind trees(graph);
    graphs spanningTree;

    for(const auto& edge:graph){
        if(trees.isAcylic(edge.second)){
            trees.join(edge.second, setCounter);
            spanningTree.insert(edge);
        }
        setCounter +=1;
    }

    return spanningTree;
}
