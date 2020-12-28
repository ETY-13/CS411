// simpleUnionfind.hpp
// Theng Yang
// 2020.12.26

// Header file for the following source files: simpleUnionFind, quickFind, quickUnion.

#ifndef UnionFind_UNIONFIND_HPP
#define UnionFind_UNIONFIND_HPP

#include<memory>
#include<vector>
#include<string>
#include<unordered_map>

// The following are simple implementation of the Union-Find
// data structure and algorithm, referencing to
// Introduction to Algorithm Analysis by Anny Levitin.


// A simple Union-Find data structure that uses
// a hash table to keep track of sets.
class SimpleUnionFind{
public:
    virtual void makeset(int vertex);
    virtual void merge(int vertex_A, int vertex_B );
    virtual auto noset(int vertex) ->bool;
    virtual auto isAcyclic(int scr_vertx, int dest_vertex)->bool;

    auto find(int vertex)->int;
private:
    std::unordered_map<int, int> _sets_;
};

// A simple implementation of a Union-Find data structure
// that optimize the find operation.
class QuickFind: SimpleUnionFind {
    // Node to hold the sets vertices
    struct node {
        explicit node(int vertex);
        std::shared_ptr<node> _next_;
        int _vertex_;
    };

    // The Header that contain pointers the total number
    // of vertices in the set, the first node, and
    // the last node in the set.
    struct headNode {
        std::shared_ptr<node> _first_;
        std::shared_ptr<node> _last_;
        std::shared_ptr<int> _totalElements_ = nullptr;
    };

public:
    void makeset(int vertex);
    auto find(int vertex)->headNode;
    void merge(int vertex_A, int vertex_B );

    auto noset(int vertex) ->bool;
    auto isAcyclic(int scr_vertx, int dest_vertex)->bool ;

private:
    std::vector<headNode> _mapper_;
};


// A simple implementation of a Union-Find data structure
// that optimize the merge (union) operation.
class QuickUnion:SimpleUnionFind {

    // for storing the elements
    struct rooted_tree {
        rooted_tree(int vertex);
        std::shared_ptr<rooted_tree> _parent_ = nullptr;
        std::shared_ptr<int> _height_ = nullptr;
        int _element_;
    };

public:
    void makeset(int vertex);
    void merge(int vertex_A, int vertex_B );
    auto find( int vertex)->std::shared_ptr<rooted_tree>;

    auto noset(int vertex) ->bool;
    auto isAcyclic(int scr_vertx, int dest_vertex)->bool ;

private:
    std::vector<std::shared_ptr<rooted_tree>> _mapper_;

};

#endif //UnionFind_UNIONFIND_HPP
