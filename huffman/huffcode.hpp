// huffcode.hpp
// Theng Yang
// 2020-11-25

#ifndef HUFFCODE_HPP
#define HUFFCODE_HPP

#include<unordered_map>
#include <string>
#include<memory>

struct Node{
    Node(char character, int weight);
    Node(int weight);

    std::shared_ptr<Node> _right_;
    std::shared_ptr<Node> _left_;

    char _character_ = NULL;
    int _weight_;

};

class HuffCode{
public:
    void setWeights(const std::unordered_map<char, int> & theweights);
    std::string encode(const std::string & text) const;
    std::string decode(const std::string & codestr) const;
private:
    std::shared_ptr<Node> _tree_;
};
#endif //HUFFCODE_HPP
