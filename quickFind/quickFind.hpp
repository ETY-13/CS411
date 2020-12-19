// quickFind.hpp
// Theng Yang
// 2020.12.18

#ifndef QUICKFIND_QUICKFIND_HPP
#define QUICKFIND_QUICKFIND_HPP

#include<memory>
#include<unordered_map>
#include<string>

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

// A variation of Union-Find that
// optimizer find operations.
class QuickFind {

public:
    void makeset(int vertex);
    auto find(int vertex)->headNode;
    void merge(int vertex_A, int vertex_B );

private:
    std::vector<headNode> _index_holder_;
};


#endif //QUICKFIND_QUICKFIND_HPP
