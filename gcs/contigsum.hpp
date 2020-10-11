// contigsum.hpp
// Theng Yang
//

#ifndef GCS_CONTIGSUM_HPP
#define GCS_CONTIGSUM_HPP

#include<iterator>
#include<algorithm>

struct calculatedData{
    int a, b,c,d = 0;
};

template<typename iter>
calculatedData computeGCS(iter first, iter last) {

    auto itemLen = std::distance(first, last);

    if(itemLen == 0){
        calculatedData gcs_stuff;
        return gcs_stuff;
    }
    if (itemLen == 1) {
        calculatedData gcs_stuff{*first, *first, *first, *first };
        return gcs_stuff;
    }

    auto left = computeGCS(first, first + (itemLen / 2));
    auto right = computeGCS(first + (itemLen / 2), last);

    calculatedData wholeSeq {
            std::max({left.a, right.a, left.c + right.b}),
            std::max({left.b, left.d + right.b}),
            std::max({right.c, right.d + left.c}),
            left.d + right.d
    };

    return wholeSeq;
}

template<typename Iter>
int contigSum(Iter first, Iter last){
   
    auto result = computeGCS(first, last);
    return std::max(0,result.a);
}
#endif //GCS_CONTIGSUM_HPP
