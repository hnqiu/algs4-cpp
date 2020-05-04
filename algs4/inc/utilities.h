/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


#pragma once

#include <vector>
#include <iostream>
#include <random>


/* @brief: print out elements in vector, seperated by " " */
template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
    for (const auto &elem : t) {
        os << elem << " ";
    }
    return os;
}


namespace algs4 {
    /* @brief: return a vector of random integers between [min, max]
     * using uniform distribution
     */
    inline std::vector<int> rand(const size_t &s, const int &min, const int &max) {
        std::random_device rd{};
        std::mt19937 e{rd()};
        std::uniform_int_distribution<int> u(min, max);

        std::vector<int> list;
        for (size_t i = 0; i < s; ++i) {
            list.push_back(u(e));
        }
        return list;
    }


    /* @brief: print out the sequence with formatting
     * @discription: print out 'num' numbers in a line
     */
    template <typename Iterator>
    void print(const Iterator begin, const Iterator end, size_t num) {
        for (const Iterator i = begin; i != end; ) {
            for (size_t n = 0; n < num && i < end; ++n) {
                std::cout << *i++ << " ";
            }
            std::cout << std::endl;
        }
    }


    /* @brief: return the smaller iterator */
    template <typename Iterator>
    Iterator min(Iterator a, Iterator b) {
        return (a < b) ? a : b;
    }

}
