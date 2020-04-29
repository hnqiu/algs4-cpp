/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: sort a sequence of integers using different sorting algorithms
 * To compile, g++ ch2/sort.cpp -o sort
 * To execute, ./sort
 * while in dir ./algs4-cpp/algs4/
 * 
 * Note the sequence to be sorted can be
 * any standard sequential container, or a c-type array
 */


#include "sort.h"
#include "selection.h"
#include "insertion.h"
#include "shell.h"
#include "../inc/utilities.h"


int main(int argc, char* argv[]) {
    size_t num = 0;
    std::cout << "Input number of integer sequence: ";
    std::cin >> num;

    // rand nums
    std::vector<int> list = algs4::rand(num, -1000, 1000);
    std::cout << list.size() << " ints generated: \n" << list << std::endl;
    // if 'list' is a c-type array, 
    // use std::begin(list) instead of list.begin() as the alg argument
    // int list[10] = {10, 2, 35, 25, 51, 43, 36, 81, 4, 15};

    // sort
    // algs4::selectionSort(list.begin(), list.end());
    // algs4::insertionSort(list.begin(), list.end());
    algs4::shellSort(list.begin(), list.end());
    assert( algs4::isSorted(std::begin(list), std::end(list)) );
    std::cout << "Sequence sorted:\n" << list << std::endl;
}
