/* Created by hnqiu on 27/04/2020.
 * Copyright (C) 2020 hnqiu. All Rights Reserved.
 * Licensed under the MIT License. See LICENSE for details.
 */


#pragma once

#include <vector>
#include <iostream>


/* @brief: print out elements in vector, seperated by " " */
template <typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
    for (const auto &elem : t) {
        os << elem << " ";
    }
    return os;
}

