// build.cpp
// Theng Yang
// 9/28/2020

// A file that contain the definition of build(): a function that
// solve the west and east bridges' max tolls  problem.

// The algorithm for generating the subsets of possible bridges
// in generateSubsets() is taken from Dr. Hartman
// implementation of Decrease by 1 subsets generation.

#include"build.h"

#include<vector>
using std::vector;

using bridge = vector<int>;

// function that check bridge cannot be build.
// Return true when the a cross or cities are the same; false otherwise.
auto noBuild(int wC, int eC, const vector<int> & bridgeIDX,
                             const vector<bridge> & bridges) -> bool{

   for( const auto & item: bridgeIDX ){

       if ( (wC >= bridges[item][0] &&   // check if bridges cross
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

// Given a number of west cities and east cities and
// a vector of bridges, return the maximum tolls
// collected from the buildable bridges.
auto build(int w, int e, const vector<bridge> & bridges) ->int {

    // w and e are not used in this implementation
    // because all the bridges can be found in the
    // vector of bridges.

    auto subsets = generateSubsets(bridges.size(), bridges);

    int maxToll = 0;
    for (const auto & set: subsets) {
        int toll = 0;

        for (const auto & item : set) {
            toll += bridges[item][2];
        }

        if (toll > maxToll) {
            maxToll = toll;
        }
    }

    return maxToll;
}

