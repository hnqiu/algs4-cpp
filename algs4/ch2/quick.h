/* Created by hnqiu on 05/05/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: quicksort implementation (P289)
 * A popular sorting program with averaged n log n running time
 * & little extra space whose performance would be compromised in worse cases
 */


#pragma once

#include <utility>
#include <cassert>


namespace algs4 {
  namespace quick_private {
    /* @brief: re-arrange the sequence into two sublists
     * return the iterator (itr) that is in its final position in the sequence
     * @discription: any entry prior to the returned iterator <= *itr
     * any entry after itr >= *itr
     */
    template <typename Iterator>
    Iterator partition(Iterator lo, Iterator hi) {
        Iterator i = lo, j = hi;
        while (true) {
            while ( *(++i) < *lo ) { // break if *i >= *lo
                if (i == hi) break; // if reach end
            }
            while ( *lo < *(--j) ); // break if *j <= lo
            if (i >= j) break;
            std::swap(*i, *j);
        }
        std::swap(*lo, *j);
        return j;
    }
  }


    /* @brief: sort a sequence of inputs using quicksort
     * sort sequence in ascending order
     * @discription: argument types can be pointers to a c-type array
     * or iterators of any standard sequential container
     */
    template <typename Iterator>
    void quickSort(Iterator begin, Iterator end) {
        assert(begin <= end);
        if (begin == end) return; // size = 1 or both point to end()
        Iterator j = quick_private::partition(begin, end);
        // print(begin, end, begin-end);
        quickSort(begin, j);
        quickSort(j+1, end);
    }

}
