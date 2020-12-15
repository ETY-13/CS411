//
// Created by snowf on 12/13/2020.
//

#ifndef QUICKFIND_QUICKFIND_HPP
#define QUICKFIND_QUICKFIND_HPP

#include<memory>
#include<unordered_map>
#include<string>
#include<iostream>

struct node {
    node(int vertex);
    std::shared_ptr<node> _next_;
    int _vertex_;
};

struct headNode
{
    headNode() = default;
    headNode(int vertex);
    std::shared_ptr<node> _first_;
    std::shared_ptr<node> _last_;
    int _totalElements_ = 0;
};

class QuickFind {

public:
    void makeset(int vertex);
    auto find(int vertex)->headNode;

    void merge(int vertex_A, int vertex_B );

private:
    std::vector<headNode> index_holder;

};


#endif //QUICKFIND_QUICKFIND_HPP
