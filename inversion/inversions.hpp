// inversion.hpp
// Theng Yang
// 10/10/2020

// Header file for inversions. There is no corresponding source file.
// Contain functions inversions, mergeSort, and stableMerge.

// Functions mergeSort and stableMerge are originally implemented by Dr. Glenn Chappell,
// it is modified slightly to act as helper functions for counting inversions.

#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP

#include<iterator>
#include<vector>


// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Theng Y. addition counts the number of inversion.

// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now sorted by < (in a stable manner).
template <typename FDIter>
auto stableMerge(FDIter first, FDIter middle, FDIter last) ->int
{
    // ** C++03:
    using Value = typename std::iterator_traits<FDIter>::value_type;

    std::vector<Value> buffer(distance(first, last));
    // Buffer for temporary copy of data
    FDIter in1 = first;         // Read location in 1st half
    FDIter in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer

    int inversion = 0;

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1) { // Must do comparison this way, to be stable.
            *out++ = *in2++;
            inversion += std::distance(in1, middle); // count the inversions (added by Theng Y.)
        }
        else {
            *out++ = *in1++;
        }
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    copy(in1, middle, out);
    copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    copy(buffer.begin(), buffer.end(), first);

    return inversion;
}


// mergeSort
// Sorts a sequence, using Merge Sort.
// Theng Y. modifications count the number of inversion using merge sort.

// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner)
template <typename FDIter>
auto mergeSort(FDIter first, FDIter last) ->int
{
    // Compute size of sequence
    size_t size = std::distance(first, last);
    int inversion = 0;
    // BASE CASE
    if (size <= 1)
        return 0;

    // RECURSIVE CASE
    FDIter middle = first;
    std::advance(middle, size / 2);  // middle is iterator to middle of range

    // Recursively sort the two lists
    inversion += mergeSort(first, middle);
    inversion += mergeSort(middle, last);

    // And merge them

    inversion += stableMerge(first, middle, last);

    return inversion;
}

// A function that call on mergeSort to counts the
// number of inversion in a given sequence of numbers.
template<typename Iter>
auto inversions(Iter first, Iter last) -> size_t {
    auto inversionCount = mergeSort(first, last);
    return inversionCount;
}

#endif //INVERSIONS_HPP
