// quickFind.cpp
// Theng Yang
// 2020.12.18

#include"quickFind.hpp"
using std::make_shared;

node::node(int x): _vertex_(x) {}

// Make a set for the given input
void QuickFind::makeset(int x) {

    if(_index_holder_.size() <= x ){
        _index_holder_.resize(x + 1);
        for(auto & i : _index_holder_){
            if(i._totalElements_ == nullptr){
                i ={};
            }
        }
    }

    headNode head;
    auto n  = make_shared<node>(x);
    head._totalElements_ = make_shared<int>(1);
    head._first_ = n;
    head._last_ = n;
    _index_holder_[x] = head;
}

// Find the set that contains the input
auto QuickFind::find(int x) -> headNode {
    if(_index_holder_.size() <= x){
        return {};
    }
    return _index_holder_[x];
}

// Make two distinct sets that contain the two
// respective inputs
void QuickFind::merge(int x, int y) {
    auto *front = &_index_holder_[x];
    auto *bottom = &_index_holder_[y];

    // Append the smaller set to the bigger set
    if (front->_totalElements_ < bottom->_totalElements_) {
       front = &_index_holder_[y];
       bottom = &_index_holder_[x];
    }

    if (front->_first_->_vertex_ != bottom->_first_->_vertex_) {
        front->_last_->_next_ = bottom->_first_;
        *front->_totalElements_ = *front->_totalElements_ + *bottom->_totalElements_;

        front->_last_ = bottom->_last_;
        auto start = bottom->_first_;

        // set all the indices in _index_holder_ to point to the new set
        while (start != nullptr) {
            _index_holder_[start->_vertex_] = *front;
            start = start->_next_;
        }
    }
}