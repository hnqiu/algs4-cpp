/* Created by hnqiu on 28/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: test whether the sequence is sorted (P245)
 */


#pragma once

#include <cassert>


namespace algs4 {
    /* @brief: test whether the sequence is sorted */
    template <typename Iterator>
    bool isSorted(Iterator begin, Iterator end) {
        assert(begin <= end);
        for (Iterator i = begin+1; i < end; ++i) {
            if ( *i < *(i-1) ) return false;
        }
        return true;
    }
}
