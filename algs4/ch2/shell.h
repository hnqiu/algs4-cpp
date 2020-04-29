/* Created by hnqiu on 28/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: shell sort implementation (P258)
 * A (faster) extension of insertion sort
 * whose performance has not been precisely characterized
 */


#pragma once

#include <utility>
#include <iterator>
#include <cassert>


namespace algs4 {
    /* @brief: sort a sequence of inputs using shell sort
     * h-sort subsequence until h decreased to 1
     * @discription: argument type can be the pointer to a c-type array
     * or the iterator of any standard sequential container
     * or maybe can be extended to ordered associative containers (NOT tested)
     * if the relational operators (<, >) are changed to std::less()/greater()
     */
    template <typename Iterator>
    void shellSort(Iterator begin, Iterator end) {
        assert(begin < end);
        int length = std::distance(begin, end);
        int h = 1;
        while (h < length/3) {
            h = 3*h + 1; // 1, 4, 13, 40, 121 ...
        }
        while (h >= 1) {
            for (Iterator i = begin+h; i < end; ++i) {
                for (Iterator j = i; j >= begin+h && *j < *(j-h); j -= h) {
                    std::swap(*j, *(j-h));
                }
            }
            h /= 3;
        }
    }
}
