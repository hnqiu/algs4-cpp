/* Created by hnqiu on 29/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: top-down mergesort implementation (P270)
 * A program with guaranteed n log n running time to sort a sequence
 */


#pragma once

#include "sort.h"
#include <iterator>
#include <vector>
#include <type_traits>
#include <cassert>


namespace algs4 {
  namespace merge_private {
    /* @brief: merge two ordered subsequences into a single ordered one
     * @discription: stably merge aux[lo..mid) with aux[mid..hi) into out[lo..hi)
     */
    template <typename Iterator, typename Iter>
    void merge(Iterator lo, Iterator mid, Iterator hi, Iter out) {
        assert(lo < mid && mid < hi);
        assert( isSorted(lo, mid) );
        assert( isSorted(mid, hi) );

        // merge
        Iterator i = lo, j = mid;
        while (i != mid && j != hi) {
            if (*j < *i) {
                *out++ = *j++;
            } else {
                *out++ = *i++;
            }
        }
        if (i == mid) {
            std::copy(j, hi, out);
        } else {
            std::copy(i, mid, out);
        }
    }


    /* @brief: actual implementation of mergesort
     * iteratively merges subsequences back and forth between two buffers
     * @discription: if the auxiliary subsequences are sorted,
     * merge them into the original sequence
     * if the original subsequences are sorted, merge them into the auxiliary
     */
    template <typename Iterator, typename Iterator_aux>
    void mergeSort(Iterator begin, Iterator end, 
                   Iterator_aux aux_begin, Iterator_aux aux_end) {
        if (begin == end-1) return; // size == 1
        // Iterator mid = begin + (end - begin) / 2;
        // use the following instead
        Iterator mid = std::next(begin, std::distance(begin, end)/2);
        Iterator_aux aux_mid = 
                std::next(aux_begin, std::distance(aux_begin, aux_end)/2);
        mergeSort(aux_begin, aux_mid, begin, mid);
        mergeSort(aux_mid, aux_end, mid, end);
        merge(aux_begin, aux_mid, aux_end, begin);
    }
  }


    /* @brief: sort a sequence of inputs using top-down mergesort
     * sort sequence in ascending order
     * @discription: argument types can be pointers to a c-type array
     * or iterators of any standard sequential container
     */
    template <typename Iterator>
    void mergeSort(Iterator begin, Iterator end) {
        assert(begin < end);
        // use pre-allocated space to avoid recursive allocations of temp copies
        typedef typename std::iterator_traits<Iterator>::value_type elemType;
        auto aux = std::vector<elemType>(begin, end); // std::copy(begin, end)
        merge_private::mergeSort(begin, end, aux.begin(), aux.end());
    }
}
