//
// Created by snowf on 12/13/2020.
//
#include"quickFind.hpp"
using std::make_shared;

node::node(int x): _vertex_(x) {};

headNode::headNode(int x): _totalElements_(x) {};

void QuickFind::makeset(int x) {
    if(index_holder.size() <= x ){
        index_holder.resize(x+1);
    }
    for(auto i = 0; i<index_holder.size(); i++){
        if(index_holder[i]._totalElements_ == 0){
            index_holder[i] ={};
        }
    }


    headNode head(x);
    auto n  = make_shared<node>(x);
    head._totalElements_ = 1;
    head._first_ = n;
    head._last_ = n;
    index_holder[x] = head;

}

auto QuickFind::find(int x) -> headNode {
    if(index_holder.size() <= x){
        return {};
    }
    return index_holder[x];
}

void QuickFind::merge(int x, int y) {

    auto front = index_holder[x];
    auto bottom = index_holder[y];

   if (front._totalElements_ < bottom._totalElements_) {
       front = index_holder[y];
       bottom = index_holder[x];
    }

    if (front._first_->_vertex_ != bottom._first_->_vertex_) {
        front._last_->_next_ = bottom._first_;
        front._totalElements_ = front._totalElements_ + bottom._totalElements_;

        front._last_ = bottom._last_;
        auto start = bottom._first_;

        while (start != nullptr) {

            index_holder[start->_vertex_] = front;
            start = start->_next_;

        }
        index_holder[x] = front;
    }
}