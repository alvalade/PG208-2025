/**
 * @file ifstream_exc.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "ifstream_exc.hpp"

ifstream_exc
::ifstream_exc(std::string filename)
: f(filename)
{}

ifstream_exc
::ifstream_exc(std::string& filename)
: f(filename)
{}


template <typename T>
ifstream_exc& ifstream_exc
::operator>>(T& other)
{
    if (!f)
        throw std::runtime_error("Cannot operate on stream: is bad");
    f >> other;
    return *this;
}

template ifstream_exc& ifstream_exc::operator>>(char& other);
template ifstream_exc& ifstream_exc::operator>>(int& other);
template ifstream_exc& ifstream_exc::operator>>(unsigned int& other);
template ifstream_exc& ifstream_exc::operator>>(std::string& other);
