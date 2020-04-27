/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: sort a sequence of integers using selection sort (P248)
 * A program with n^2 running time that
 * sort a sequence in ascending order
 * 
 * To compile, g++ ch2/selection.cpp -o algs
 * To execute, ./algs
 * while in dir ./algs4-cpp/algs4/
 */


#include "../inc/utilities.h"
#include <iostream>
#include <vector>
#include <random>


namespace algs4 {
    /* @brief: sort a sequence of inputs using selection sort */
    template <typename Iterator>
    void selectionSort(Iterator begin, Iterator end) {
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


int main(int argc, char* argv[]) {
    size_t num = 0;
    std::cout << "Input number of integer sequence: ";
    std::cin >> num;

    // rand num generator
    std::random_device rd{};
    std::mt19937 e{rd()};
    std::uniform_int_distribution<int> u(-1000, 1000);

    std::vector<int> list;
    for (size_t i = 0; i < num; i++) {
        list.push_back(u(e));
    }
    std::cout << list.size() << " ints generated: \n" << list << std::endl;

    algs4::selectionSort(list.begin(), list.end());
    std::cout << "Sequence sorted:\n" << list << std::endl;
}
