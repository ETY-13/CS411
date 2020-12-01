// huffcode.cpp
// Theng Yang
// 2020-11-30

#include "huffcode.hpp"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::swap;
using std::iter_swap;
using std::reverse;



// A function that traverse through the tree for a given character and return
// a string of '1' and  '0' base on the direction it had taken find the character.
// Use by encode() to do the encoding.
auto encoding(const shared_ptr<Node> & ptr, const char character, const string & direction ) -> string{

    if(ptr == nullptr){
        return "";
    }

    if (ptr->_character_ == character) {
        if (direction == "right") {
            return "1";
        }
        return "0";
    }

    auto encoded_text = encoding(ptr->_right_, character, "right");

    encoded_text += encoding(ptr -> _left_, character, "left");

    if (!encoded_text.empty()) {
        if (direction == "right") {
            encoded_text += "1";
        }
        else if (direction =="left") {
            encoded_text += "0";
        }
    }

    return encoded_text;
}

// ******************* struct Node constructors ***************************

Node::Node(char character, int weight):_character_(character), _weight_(weight){}
Node::Node(int weight):_weight_(weight) {}



// ******************** Class HuffCode member functions *******************


// Given a set of characters and their weights, construct a Huffman tree
// for the characters.
void HuffCode::setWeights(const std::unordered_map<char, int> &theweights) {

    vector<shared_ptr<Node>> holder;
    holder.reserve(theweights.size());

    for (const auto & theweight : theweights) {
        holder.push_back(make_shared<Node>(theweight.first, theweight.second));
    }

    while (holder.size() > 1) {

        auto first_small = 0;
        auto second_small = 1;

        if (holder[0]->_weight_ > holder[1]->_weight_) {
            swap(first_small, second_small);
        }

        for (auto i = 2; i < holder.size(); i++) {

            if (holder[i]->_weight_ < holder[first_small]->_weight_) {
                second_small = first_small;
                first_small = i;

            } else if (holder[i]->_weight_ < holder[second_small]->_weight_) {
                second_small = i;
            }
        }

        auto node = make_shared<Node>(holder[first_small]->_weight_ + holder[second_small]->_weight_);

        node->_left_ = holder[first_small];

        node->_right_ = holder[second_small];

        holder[second_small] = node;

        iter_swap(holder.begin() + first_small, holder.end()-1);
        holder.pop_back();
    }

    if(!holder.empty())
        _tree_ = holder[0];

}

// A function that given a string of text, call encoding() on each
// character in the text to get the encoded string for the character.
// Return an encoded string.
auto HuffCode::encode(const std::string &text) const -> string {

    string encoded_str;
    for(auto character:text){
       auto encoded_char =  encoding(_tree_, character, "");
       reverse(encoded_char.begin(), encoded_char.end());
       encoded_str += encoded_char;
    }

    return encoded_str;
}

// A function that given an encoded string, go through the string and
// match each encoded component to its corresponding character.
// Return a decoded string of text.
auto HuffCode::decode(const std::string &codestr) const -> string {

    string decoded_text;
    auto cur_ptr = _tree_;
    for (auto i : codestr) {

        if (i == '0') {

            if (cur_ptr->_left_ != nullptr && cur_ptr->_left_->_character_) {
                decoded_text += string(1, cur_ptr->_left_->_character_);
                cur_ptr = _tree_;
            }
            else {
                cur_ptr = cur_ptr->_left_;
            }

        }
        else
        {
            if (cur_ptr->_right_ != nullptr && cur_ptr->_right_->_character_ ) {
                decoded_text += string(1, cur_ptr->_right_->_character_);
                cur_ptr = _tree_;
            }
            else {
                cur_ptr = cur_ptr->_right_;
            }

        }

    }

    return decoded_text;
}
