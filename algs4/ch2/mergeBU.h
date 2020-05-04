/* Created by hnqiu on 04/05/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: bottom-up mergesort implementation (P278)
 * A program with guaranteed n log n running time to sort a sequence
 */


#pragma once

#include "sort.h"
#include "../inc/utilities.h"
#include <iterator>
#include <vector>
#include <type_traits>
#include <cassert>


namespace algs4 {
  namespace mergeBU_private {
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
  }


    /* @brief: sort a sequence of inputs using bottom-up mergesort
     * @discription: argument types can be pointers to a c-type array
     * or iterators of any standard sequential container
     */
    template <typename Iterator>
    void mergeBUSort(Iterator begin, Iterator end) {
        assert(begin < end);
        if (begin == end-1) return; // size == 1
        // use pre-allocated space to avoid recursive allocations of temp copies
        typedef typename std::iterator_traits<Iterator>::value_type elemType;
        auto aux = std::vector<elemType>(begin, end);

        size_t length = std::distance(begin, end);
        for (size_t sz = 1; sz < length; sz *= 2) {
            Iterator lo = begin;
            auto lo_aux = aux.begin();
            for ( ; lo + sz < end; lo += 2*sz, lo_aux += 2*sz) {
                mergeBU_private::merge(lo, lo+sz, algs4::min(lo+2*sz, end), lo_aux);
            }
            std::copy(aux.begin(), aux.end(), begin);
            // std::cout << "sub size = " << sz << '\n';
            // print(begin, end, 2*sz);
        }
    }

        // iteratively merges subsequences back and forth between two buffers
        // if flag = true, merge sorted subsequences into the auxiliary
        // else, merge sorted auxiliary subsequences into the original
        // !!! NOT successful !!!
        // at some point when the size of the remaining subsequence is smaller than sz,
        // the program will exit the while loop, resulting in
        // NOT copying the sorted buffer into the targetted buffer
        // therefore, the remaining part of the targetted buffer is only sub-sorted
        /*
        bool flag = true;
        for (size_t sz = 1; sz < length; sz *= 2) {
            if (flag) {
                Iterator lo = begin;
                auto lo_aux = aux.begin();
                while (lo + sz < end) {
                    Iterator smaller_end = algs4::min(lo + 2*sz, end);
                    mergeBU_private::merge(lo, lo + sz, smaller_end, lo_aux);
                    lo += 2*sz;
                    lo_aux += 2*sz;
                }
                std::cout << "sub size = " << sz << '\n';
                print(begin, end, 2*sz);
                flag = false;
            }
            else {
                Iterator lo = begin;
                auto lo_aux = aux.begin();
                while (lo_aux + sz < end) {
                    Iterator smaller_end = algs4::min(lo_aux + 2*sz, aux.end());
                    mergeBU_private::merge(lo_aux, lo_aux + sz, smaller_end, lo);
                    lo += 2*sz;
                    lo_aux += 2*sz;
                }
                std::cout << "sub size = " << sz << '\n';
                print(begin, end, 2*sz);
                flag = true;
            }
        }
        if (!flag) {
            std::copy(aux.begin(), aux.end(), begin);
        }
        */
    // }

}
