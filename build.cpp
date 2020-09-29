// build.cpp
// Theng Yang
// 9/28/2020

// A file that contain definition for build(): a function that
// solve the west and east bridges' max toll  problem.

// The algorithm for generating the subsets of possible bridges
// in generateSubsets() is taken from Dr. Hartman
// implementation of Decrease by 1 subsets generation.

#include"build.h"

#include<vector>
using std::vector;

using bridge = vector<int>;

// Given a number n and vector of bridges, generate a list of possible subsets from
// 0 to n. Use the list of subsets as the index to get the possible bridges, and
// return a vector containing subsets of all the possible bridges.
vector<vector<int>> generateSubsets(int n, const vector<bridge>& bridges) {

    if (n == 0) {
        return {{}};
    }

    auto subsets = generateSubsets(n - 1, bridges);

    auto howMany = subsets.size();
    bool skip = false;
    auto track = subsets;

    for (int i = 0; i < howMany; ++i) {

        for (int j = 0; j < track[i].size(); j++) {

            if ( (bridges[n - 1][0] > bridges[track[i][j]][0] &&   // check if bridges cross
                  bridges[n - 1][1] < bridges[track[i][j]][1])  ||
                  (bridges[n - 1][0] < bridges[track[i][j]][0] &&
                  bridges[n - 1][1] > bridges[track[i][j]][1]) ||

                  (bridges[n - 1][0] == bridges[track[i][j]][0] || // check if cities are the same
                  bridges[n - 1][1] == bridges[track[i][j]][1]) ){

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
    for (auto set: subsets) {
        int toll = 0;

        for (auto item : set) {
            toll += test[item][2];
        }

        if (toll > maxToll) {
            maxToll = toll;
        }
    }

    return maxToll;
}



