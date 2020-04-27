/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: sort a sequence of integers using different sorting algorithms
 * To compile, g++ ch2/sort.cpp -o sort
 * To execute, ./sort
 * while in dir ./algs4-cpp/algs4/
 */


#include "selection.h"
#include "../inc/utilities.h"
#include <random>


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
