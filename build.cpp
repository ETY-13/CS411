// build.cpp
// Theng Yang
// 9/28/2020

// A file that contain the definition of build(): a function that
// solve the west and east bridges' max tolls  problem.

// The algorithm for generating the subsets of possible bridges
// in generateSubsets() is taken from Dr. Hartman
// implementation of Decrease by 1 subsets generation.

#include"build.hpp"

#include<vector>
using std::vector;
#include<algorithm>
using std::max;
#include<iostream>
using bridge = vector<int>;

// function that check bridge cannot be build.
// Return true when the a cross or cities are the same; false otherwise.
auto noBuild(int wC, int eC, const vector<int> & bridgeIDX,
                             const vector<bridge> & bridges) -> bool{

   for( const auto & item: bridgeIDX ){

       if ( (wC>= bridges[item][0] &&   // check if bridges cross
             eC<= bridges[item][1])  ||
            (wC<= bridges[item][0] &&
             eC>= bridges[item][1])) {

           return true;
       }
   }

   return false;
}


// Given a number n and a vector of bridges, generate a list of possible subsets from
// 0 to n that correspond to the subsets of buildable bridges, and return it.
auto generateSubsets(int n, const vector<bridge>& bridges) -> vector<bridge> {

    if (n == 0) {
        return {{}};
    }

    auto subsets = generateSubsets(n - 1, bridges);
    auto howMany = subsets.size();
    auto track = subsets;

    for (int i = 0; i < howMany; ++i) {

        if (!noBuild(bridges[n - 1][0],bridges[n - 1][1], track[i], bridges )) {
            subsets.push_back(subsets[i]);
            subsets.back().push_back(n - 1);
        }

    }

    return subsets;
}

// A function that solve the max_toll bridges problem with dynamic
// programming via top-down approach.
auto dy_topDown(vector<vector<int>> & holder, const vector<vector<int>> & value, int west, int east) ->int {


    if (west < 0 || east < 0) {
        return 0;
    }
    if(holder[west][east] !=-1){
        return holder[west][east];
    }

    auto toll = max({ dy_topDown( holder, value, west - 1, east - 1) + value[west][east],
                           dy_topDown( holder, value, west - 1, east),
                           dy_topDown(holder, value, west, east - 1) });


   holder[west][east] = toll;

    return toll;

}

// A function that solve the max_toll bridges problem with dynamic
// programming via bottom-up approach.
auto dy_bottomUp(const vector<vector<int>>& value, int w, int e) -> int {

    vector<vector<int>> holder(w, vector<int>(e, 0));

    for (auto i = 0; i < w; i++) {
        for (auto j = 0; j < e; j++) {

            if (i > 0 && j > 0) {
                holder[i][j] = max({ holder[i-1][j-1] + value[i][j], holder[i][j-1], holder[i-1][j] });
            }
            else if (j > 0) {
                holder[i][j] = max({ value[i][j], holder[i][j-1] });
            }
            else if(i > 0) {
                holder[i][j] = max({ value[i][j],  holder[i-1][j] });
            }
            else{
                holder[i][j] = value[i][j];
            }

        }
    }

    return holder[w - 1][e - 1];
}

// Given a number of west cities and east cities and
// a vector of bridges, return the maximum tolls
// collected from the buildable bridges.
auto build(int w, int e, const vector<bridge> & bridges) ->int {

    // w and e are not used in this implementation
    // because all the bridges can be found in the
    // vector of bridges.

    vector<bridge> value (w, vector<int>(e, 0));
    for (const auto & bridge : bridges) {
        if(value[bridge[0]][bridge[1]] < bridge[2])
            value[bridge[0]][bridge[1]] = bridge[2];
    }

    return dy_bottomUp(value, w, e);

}

