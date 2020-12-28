// quickUnion.cpp
// Theng Yang
// 2020.12.18

#include"unionFind.hpp"
using std::make_shared;
using std::shared_ptr;

#include<algorithm>
using std::swap;
QuickUnion::rooted_tree::rooted_tree(int vertex): _element_(vertex), _height_(make_shared<int>(0)){}

// Put each _element_ in a rooted tree
void QuickUnion::makeset(int vertex) {

    if (_mapper_.size() < vertex + 1) {
        _mapper_.resize(vertex + 1);

        for (auto i = 0; i < vertex + 1; i++) {
            if (!_mapper_[i]) {
                _mapper_[i] = {};
            }
        }
    }
    rooted_tree node(vertex);
    node._parent_ = make_shared<rooted_tree>(node); // root points to itself

    _mapper_[vertex] = make_shared<rooted_tree>(node);

}

void QuickUnion::merge(int vertex_A, int vertex_B) {

    auto x_root = *find(vertex_A);
    auto y_root = *find(vertex_B);

    if (*x_root._height_ < *y_root._height_)
        swap(x_root, y_root);

    *y_root._parent_ = x_root;
    *x_root._height_ += 1;
    *y_root._height_ = *x_root._height_;

}

auto QuickUnion::find( int vertex)->shared_ptr<rooted_tree>  {

    if (vertex >= _mapper_.size() || _mapper_[vertex] == nullptr) {
        return {};
    }

    auto node = _mapper_[vertex];

    while (node->_parent_->_parent_ != nullptr) {

        node = node->_parent_;
    }

    return node;
}

auto QuickUnion::noset(int vertex) -> bool {
    return (find(vertex) == nullptr);
}

auto QuickUnion::isAcyclic(int scr_vertx, int dest_vertex) -> bool {

    return (find(scr_vertx)->_element_ != find(dest_vertex)->_element_);
}