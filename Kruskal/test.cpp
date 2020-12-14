// test.cpp
// Theng Yang
// 12/13/2020

// A simple test file for Kruskal's algorithm

#include "kruskal.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include<map>
using std::multimap;
#include<unordered_map>
using std::unordered_map;
#include<string>
using std::string;


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE ("Initial Test Of Kruskal Algorithm: ") {
    graphs graph;
    SUBCASE("Small Test -- Empty graph "){
       REQUIRE(graph == kruskal(graph));
    }

    SUBCASE("Small Test -- Graph with one edge"){
        graph.insert({1,"ab"});
        REQUIRE(graph == kruskal(graph));
    }

    SUBCASE("Small Test -- Graph with four edges"){
        graph.insert({1, "ab"});
        graph.insert({2, "ac"});
        graph.insert({3, "bd"});
        graph.insert({4, "cd"});

        graphs spanningTree {{1,"ab"}, {2, "ac"}, {3, "bd"}};
        REQUIRE(spanningTree == kruskal(graph));
    }
}

TEST_CASE("Medium Test:"){
    graphs graph;
    graphs spanningTree;
    SUBCASE("One edge connect to all other edges"){
        graph = { {1, "ab"}, {2, "ac"}, {3, "ae"},
                  {4,"be"}, {5,"ec"},{6, "ed"},
                  {7,"cd"}, {8, "bd"}
                };

        spanningTree = {{1,"ab"}, {2, "ac"},
                             {3, "ae"}, {6, "ed"}};

        CHECK(spanningTree == kruskal(graph));
    }

    SUBCASE("Graph from Anny Levitin's algorithm book"){
        graph = { {1, "bc"},{2, "ef"},{3, "ab"},
                  {4, "bf"}, {4,"cf"},{5, "af"},
                  {5,"df"},  {6,"ae"},{6,"cd"},
                  {8, "de"}
                };

        spanningTree = {{1, "bc"}, {2,"ef"}, {3, "ab"},
                        {4, "bf"}, {5, "df"}};

        CHECK(spanningTree == kruskal(graph));
    }
}