// quickFind.cpp
// Theng Yang
// 2020.12.18

#include"unionFind.hpp"
using std::make_shared;

QuickFind::node::node(int x): _vertex_(x) {}

// Make a set for the given input
void QuickFind::makeset(int x) {

    if(_mapper_.size() <= x ){
        _mapper_.resize(x + 1);
        for(auto & set : _mapper_){
            if(set._totalElements_ == nullptr){
                set ={};
            }
        }
    }

    headNode head;
    auto n  = make_shared<node>(x);
    head._totalElements_ = make_shared<int>(1);
    head._first_ = n;
    head._last_ = n;
    _mapper_[x] = head;
}

// Find the set that contains the input
auto QuickFind::find(int x) -> headNode {
    if(_mapper_.size() <= x){
        return {};
    }
    return _mapper_[x];
}

// Make two distinct sets that contain the two
// respective inputs
void QuickFind::merge(int vertex_A, int vertex_B) {
    auto *front = &_mapper_[vertex_A];
    auto *bottom = &_mapper_[vertex_B];

    // Append the smaller set to the bigger set
    if (front->_totalElements_ < bottom->_totalElements_) {
       front = &_mapper_[vertex_B];
       bottom = &_mapper_[vertex_A];
    }

    if (front->_first_->_vertex_ != bottom->_first_->_vertex_) {
        front->_last_->_next_ = bottom->_first_;
        *front->_totalElements_ = *front->_totalElements_ + *bottom->_totalElements_;

        front->_last_ = bottom->_last_;
        auto start = bottom->_first_;

        // set all the indices in _mapper_ to point to the new set
        while (start != nullptr) {
            _mapper_[start->_vertex_] = *front;
            start = start->_next_;
        }
    }
}

auto QuickFind::noset(int vertex) -> bool {
    return (find(vertex)._totalElements_ == nullptr);
}

auto QuickFind::isAcyclic(int scr_vertx, int dest_vertex) -> bool {
    return (find(scr_vertx)._first_->_vertex_ != find(dest_vertex)._first_->_vertex_);
}