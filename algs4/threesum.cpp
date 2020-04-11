/* Created by hnqiu on 08/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


/* @brief: count number of triples in a file that sum to 0
 * A program with cubic running time that
 * reads integers from a file and counts the number of triples that sum to 0
 * Files are located at ./data/
 * 
 * To compile, g++ threesum.cpp -o threesum
 * To execute, ./threesum data/[file].txt
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/* @brief: read integers from file */
std::vector<int> read_int(const std::string &file);

/* @brief: count number of triples that sum to 0 */
int threesum(const std::vector<int> &list);


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: program requires to read a file containing integers"
            << std::endl;
        return -1;
    }

    std::string filename(argv[1]);
    std::vector<int> list = read_int(filename);
    std::cout << "Calculating..." << std::endl;
    int count = threesum(list);
    std::cout << "There are " << count
        << " of triples in file '" << filename << "' that sum to 0" << std::endl;
    return 0;
}


/* @brief: read integers from file */
std::vector<int> read_int(const std::string &file) {
    std::vector<int> list;
    std::ifstream ifs(file);
    if (!ifs) {
        std::cerr << "Error: cannot open file " << file << std::endl;
        return list;
    }

    int tmp;
    while (ifs >> tmp) {
        list.push_back(tmp);
    }
    ifs.close();
    std::cout << "Total number of integers is " << list.size() << std::endl;
    return list;
}


/* @brief: count number of triples that sum to 0 */
int threesum(const std::vector<int> &list) {
    int count = 0;
    int length = list.size();
    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            for (int k = j+1; k < length; k++) {
                if (list[i] + list[j] + list[k] == 0)
                    ++count;
            }
        }
    }
    return count;
}
