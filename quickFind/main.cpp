#include"quickFind.hpp"

#include<iostream>
using std::cout;
using std::endl;

#include<map>
using std::multimap;

#include<string>
using std::string;

[[maybe_unused]] // A function that print
void printList(const headNode& head) {
    cout << "Total Elements: " << *head._totalElements_ << endl;
    cout << "The elements are: ";
    auto linkedList = head._first_;
    while (linkedList != nullptr) {
        cout << static_cast<char>(linkedList->_vertex_) << " ";
        linkedList = linkedList->_next_;
    }
    cout << endl;
}

auto krusal(const multimap<int, string> & graph)->multimap<int, string> {

    multimap<int, string> spanningTree;
    QuickFind forest;

    for(const auto & edges:graph) {

        if (forest.find(edges.second[0])._totalElements_ == nullptr) {

            forest.makeset(edges.second[0]);

        }
        if (forest.find(edges.second[1])._totalElements_ == nullptr) {

           forest.makeset((edges.second[1]));

        }

        auto start_tree = forest.find(edges.second[0]);
        auto end_tree = forest.find(edges.second[1]);

        if(start_tree._first_->_vertex_ != end_tree._first_->_vertex_){
            forest.merge(edges.second[0], edges.second[1]);
            spanningTree.insert(edges);
        }
    }

    return spanningTree;
}

auto main() -> int{

    multimap<int, string> graph{{1,"ba"},{ 2, "cf"},{3,"bf"},{2,"bc"}};
    multimap<int, string> test1 = { {1, "bc"},{2, "ef"},{3, "ab"},
                                    {4, "bf"}, {4,"cf"},{5, "af"},
                                    {5,"df"},  {6,"ae"},{6,"cd"}, {8, "de"} };
    auto spanning = krusal(test1);
    for(const auto& item:spanning){
      cout<<item.first<<" "<<item.second<<endl;
    }

   return 0;
}