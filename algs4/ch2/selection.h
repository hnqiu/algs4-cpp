/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: selection sort implementation (P248)
 * A program with consistent ~n^2/2 running time that
 * sort a sequence in ascending order
 */


#pragma once

#include <utility>
#include <cassert>


namespace algs4 {
    /* @brief: sort a sequence of inputs using selection sort
     * @discription: argument type can be the pointer to a c-type array
     * or the iterator of any standard sequential container
     */
    template <typename Iterator>
    void selectionSort(Iterator begin, Iterator end) {
        assert(begin < end);
        for (Iterator i = begin; i < end; ++i) {
            Iterator min = i;
            for (Iterator j = i+1; j < end; ++j) {
                if (*min > *j)
                    min = j;
            }
            std::swap(*min, *i);
        }
    }
}
