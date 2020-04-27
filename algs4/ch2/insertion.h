/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: insertion sort implementation (P250)
 * A program with averaged n^2 running time that
 * sort a sequence in ascending order
 */


#pragma once

#include <utility>
#include <cassert>


namespace algs4 {
    /* @brief: sort a sequence of inputs using insertion sort
     * sort sequence in ascending order
     */
    template <typename Iterator>
    void insertionSort(Iterator begin, Iterator end) {
        assert(begin <= end);
        for (Iterator i = begin+1; i < end; ++i) {
            for (Iterator j = i; j > begin && *j < *(j-1); --j) {
                std::swap(*j, *(j-1));
            }
        }
    }
}
