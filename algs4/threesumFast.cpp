/* Created by hnqiu on 21/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: count number of triples in a file that sum to 0 (P190)
 * A program with n^2 log n running time that
 * reads integers from a file and counts the number of triples that sum to 0
 * Files are located at ./data/
 * 
 * To compile, g++ threesumFast.cpp -o threesumfast
 * To execute, ./threesumfast data/[file].txt
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

/* @brief: read integers from file */
std::vector<int> read_int(const std::string& file);

/* @brief: count number of triples that sum to 0
 * a faster program compared with threesum() (see ./threesum.cpp for details)
 */
int threesumFast(std::vector<int>& list);


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: program requires to read a file containing integers"
            << std::endl;
        return -1;
    }

    using namespace std::chrono;

    try {
        std::cout << "Reading file " << argv[1] << std::endl;
        auto list = read_int(argv[1]);
        std::cout << "Total number of integers is " << list.size() << std::endl;

        std::cout << "Calculating..." << std::endl;
        auto now = steady_clock::now();
        auto count = threesumFast(list);
        duration<double> dur = steady_clock::now() - now;
        std::cout << "There are " << count << " of triples in file '"
            << argv[1] << "' that sum to 0" << std::endl;
        std::cout << "Time elapsed during counting is " 
            << dur.count() << "s" << std::endl;
    }
    catch(const std::ifstream::failure& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


/* @brief: read integers from file */
std::vector<int> read_int(const std::string& file) {
    std::ifstream ifs(file);
    // this will catch eof as well
    // ifs.exceptions(std::ifstream::failbit);
    // std::cout << ifs.exceptions() << std::endl;
    // use this instead
    if (!ifs) {
        throw std::ifstream::failure("cannot open file " + file);
    }

    std::vector<int> list;
    int tmp;
    while (ifs >> tmp) {
        list.push_back(tmp);
    }
    ifs.close();

    return list;
}


/* @brief: count number of triples that sum to 0
 * a faster program compared with threesum() (see ./threesum.cpp for details)
 */
int threesumFast(std::vector<int>& list) {
    int count = 0;
    // note std::stable_sort() does NOT necessarily implement mergesort
    // which might be different from the example on P190 of the book
    std::stable_sort(list.begin(), list.end());

    auto length = list.size();
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = i+1; j < length; ++j) {
            // if there is a number equals -a[i]-a[j] in the vector after a[j]
            if ( std::binary_search(list.begin()+j+1, list.end(), -list[i]-list[j]) )
                ++count;
        }
    }

    return count;
}
