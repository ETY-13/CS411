// simpleUnionFind
// 2020.12.27
// Theng Yang

#include "unionFind.hpp"

// make a new set for the vertex, with
// the vertex as the set representative
void SimpleUnionFind::makeset(int vertex) {
    _sets_.insert({vertex, vertex});
}

// merge vertices by setting vertices in set B to
// set A
void SimpleUnionFind::merge(int vertex_A, int vertex_B) {

    auto newset = _sets_[vertex_B];
    for(auto & set :_sets_){
        if(set.second == newset){
            set.second = _sets_[vertex_A];
        }
    }
}

// return the set of the vertex
auto SimpleUnionFind::find(int vertex)->int {

    if (_sets_.find(vertex) == _sets_.end()) {
        return -1;
    }
    return _sets_[vertex];
}

// check if vertices are in the same set
auto SimpleUnionFind::isAcyclic(int scr_vertx, int dest_vertex) -> bool {
    return (_sets_[scr_vertx] != _sets_[dest_vertex]);
}

// check if a vertex is in a set
auto SimpleUnionFind::noset(int vertex) -> bool {
    return (find(vertex) == -1);
}
