// contigsum.hpp
// Theng Yang
// 10/12/2020

// Header file for contigsum. There is no corresponding source file.
// Contain functions contigSum and ComputeGCS.
// Given a sequence of number, returns the GCS of the sequence.

#ifndef CONTIGSUM_HPP
#define CONTIGSUM_HPP

#include<iterator>
#include<algorithm>

// A data container for each part of the sequence calculated
struct calculatedData{
    int seq_gcs = 0,fval_gcs = 0,lval_gcs = 0,seq_sum = 0;
};


// A function that recursively calculate the GCS of a sequence
// of numbers using a divide and conquer algorithm. Returns
// a data container that have each calculated part
// including the GCS of the sequence.
template<typename iter>
auto computeGCS(iter first, iter last) -> calculatedData {

    auto seqLen = std::distance(first, last);

    if(seqLen == 0){
        return {};
    }
    if (seqLen == 1) {
        return {*first, *first, *first, *first };
    }

    auto left = computeGCS(first, first + (seqLen / 2));
    auto right = computeGCS(first + (seqLen / 2), last);

    // create a calculatedData with given value assigned
    calculatedData wholeSeq {
            std::max({left.seq_gcs, right.seq_gcs, left.lval_gcs + right.fval_gcs}),
            std::max({left.fval_gcs, left.seq_sum + right.fval_gcs}),
            std::max({right.lval_gcs, right.seq_sum + left.lval_gcs}),
            left.seq_sum + right.seq_sum
    };

    return wholeSeq;
}

// Solve the GCS by storing the sum of the n-1
// sequence.
template<typename iter>
auto dynamic_GCS(iter first, iter last)->int{

    int sub_sum = 0;
    int gcs = 0;

    for(auto i = first; i < last; i++){
        sub_sum = std::max(sub_sum + *i, 0);
        gcs = std::max(sub_sum, gcs);
    }
    return gcs;
}


// A function that use a helper function to calculate the GCS
// of a sequence of numbers. Returns the GCS.
template<typename Iter>
auto contigSum(Iter first, Iter last) -> int{

    return dynamic_GCS(first, last);
}
#endif //CONTIGSUM_HPP
