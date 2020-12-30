// 2020.12.30
// Theng Yang
//

#ifndef BRUTEFORCE_BRUTE_FORCE_HPP
#define BRUTEFORCE_BRUTE_FORCE_HPP

#include<string>
#include<utility>
#include<iostream>
#include <vector>
#include<set>
#include<math.h>
#include <algorithm>

// Selection sort
template<typename Iter>
void selection_sort(Iter first, Iter last){

    for (first; first !=last; ++first){
        auto smallest = first;

        for(auto j = first+1; j != last; ++j){
            if(*j < *smallest){
                smallest = j;
            }
        }

        auto hold = *first;
        *first = *smallest;
        *smallest = hold;
    }

}

template<typename Iter, typename Func>
void selection_sort(Iter first, Iter last, Func func ){

    for (first; first !=last; ++first){
        auto smallest = first;

        for(auto j = first+1; j != last; ++j){
            if(func(*j, *smallest)){
                smallest = j;
            }
        }

        auto hold = *first;
        *first = *smallest;
        *smallest = hold;
    }

}


// Bubblde sort

template <typename Iter>
void bubble_sort(Iter first, Iter last){

    for(first; first !=last; ++first){
        for(auto j = first + 1; j != last; ++j){
            if(*j < *first){
                auto holder = *first;
                *first = *j;
                *j = holder;
            }
        }
    }

}

template<typename Iter, typename Func>
void bubble_sort(Iter first, Iter last, Func func ){

    for (first; first !=last; ++first){

        for(auto j = first+1; j != last; ++j){
            if(func(*j, *smallest)){
                auto holder = *first;
                *first = *j;
                *j = holder
            }
        }
    }
}

template<typename Iter, typename Key>
auto seq_search(Iter first, Iter last, Key key)->int{
    for(auto i = first; i!=last; ++i){
        if(*i== key)
            return (int)(i - first);
    }
    return -1;
}

auto string_matching(std::string text, std::string pattern)->std::pair<int,int>{
    for(auto n = 0; n <= text.length()-pattern.length(); ++n){
        auto j = n;
        for(auto m = 0; m < pattern.length(); ++m){
            if(pattern[m] !=text[j]){
                break;
            }
            if(m == pattern.length() -1){
                return {n, j};
            }
            ++j;
        }
    }
    return {-1,-1};
}

auto closest_pair(const std::vector<std::pair<int,int>> & points)->int{
    auto closet = std::sqrt(std::pow(points[0].first - points[1].first, 2) +
                            std::pow(points[0].second - points[1].second,2));

    for(auto i = 0; i < points.size(); ++i){
        for(auto j = i+1; j<points.size(); ++j ){
            auto dist = std::sqrt(std::pow(points[i].first - points[j].first, 2) +
                                  std::pow(points[i].second - points[j].second,2));
            closet = std::min(closet, dist);
        }
    }
    return closet;
}

auto convex_hull(const std::vector<std::pair<int,int>> & points)->std::set<std::pair<int, int>>{
    std::set<std::pair<int, int>> hull;

    for(auto i = 0; i < points.size(); ++i) {
        for (auto j = i + 1; j < points.size(); ++j) {
            auto a = points[j].second - points[i].second;
            auto b = points[i].first - points[j].first;
            auto c = points[i].first * points[j].second - points[i].second * points[j].first;

            int pass_sign = 0;
            bool convex = true;
            for (const auto point:points) {
                auto point_lie = a * point.first + b * point.second - c;
                if (pass_sign == 0) {
                    pass_sign = point_lie;
                }
                else if (pass_sign < 0 && pass_sign - point_lie < pass_sign) {
                    convex = false;
                    break;
                }
                else if (pass_sign > 0 && pass_sign - point_lie > pass_sign) {
                    convex = false;
                    break;
                }
            }

            if (convex) {
                hull.insert({points[i].first, points[i].second});
                hull.insert({points[j].first, points[j].second});
                break;
            }
        }
    }
    return hull;
}


#endif //BRUTEFORCE_BRUTE_FORCE_HPP
