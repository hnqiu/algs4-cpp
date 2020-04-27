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
#include "insertion.h"
#include "../inc/utilities.h"


int main(int argc, char* argv[]) {
    size_t num = 0;
    std::cout << "Input number of integer sequence: ";
    std::cin >> num;

    // rand nums
    std::vector<int> list = algs4::rand(num, -1000, 1000);
    std::cout << list.size() << " ints generated: \n" << list << std::endl;

    // sort
    // algs4::selectionSort(list.begin(), list.end());
    algs4::insertionSort(list.begin(), list.end());
    std::cout << "Sequence sorted:\n" << list << std::endl;
}
