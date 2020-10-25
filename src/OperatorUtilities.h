// This file contains useful overloads for various operators (in particular printing)
#ifndef SRC_OPERATORUTILITIES_H
#define SRC_OPERATORUTILITIES_H

#include <iostream>
#include <utility>
#include <vector>

// C++ template to print vector container elements 
template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) 
{ 
    os << "["; 
    for (std::size_t i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n"; 
    return os; 
}

#endif