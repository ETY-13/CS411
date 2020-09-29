// build.cpp
// Theng Yang
// 9/28/2020

// A file that contain the definition for build(): a function that
// solve the west and east bridges' max toll  problem.

// The algorithm for generating the subsets of possible bridges
// in generateSubsets() is taken from Dr. Hartman
// implementation of Decrease by 1 subsets generation.

#include"build.h"

#include<vector>
using std::vector;

using bridge = vector<int>;

// Given a number n and a vector of bridges, generate a list of possible subsets from
// 0 to n that correspond to the subsets of buildable bridges, and return it.
auto generateSubsets(int n, const vector<bridge>& bridges) -> vector<bridge> {

    if (n == 0) {
        return {{}};
    }

    auto subsets = generateSubsets(n - 1, bridges);

    auto howMany = subsets.size();
    bool skip = false;
    auto track = subsets;

    for (int i = 0; i < howMany; ++i) {

        for (auto const & item:track[i]) {

            if ( (bridges[n - 1][0] > bridges[item][0] &&   // check if bridges cross
                  bridges[n - 1][1] < bridges[item][1])  ||
                  (bridges[n - 1][0] < bridges[item][0] &&
                  bridges[n - 1][1] > bridges[item][1]) ||

                  (bridges[n - 1][0] == bridges[item][0] || // check if cities are the same
                  bridges[n - 1][1] == bridges[item][1]) ){

                  skip = true;
                  break;
            }
        }

        if (!skip) {
            subsets.push_back(subsets[i]);
            subsets.back().push_back(n - 1);
        }
        else {
            skip = false;
            subsets.push_back(subsets[i]);
        }
    }

    return subsets;
}

int build(int w, int e, const vector<bridge> & test) {

    auto subsets = generateSubsets(test.size(), test);

    int maxToll = 0;
    for (auto const & set: subsets) {
        int toll = 0;

        for (auto const & item : set) {
            toll += test[item][2];
        }

        if (toll > maxToll) {
            maxToll = toll;
        }
    }

    return maxToll;
}

