#include "brute-force.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using  std::sort;

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<set>
using std::set;
#include<utility>
using std::pair;
int main() {
    vector<pair<int, int>> points{{0,0},{1,4},{3,4},{4,1},{2,0},
                                  {1,2},{2,1},{2,2},{2,3},{3,2}};
    auto ans = convex_hull(points);
    for(auto p:ans){
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}
