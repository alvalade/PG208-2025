/**
 * @file ofstream_exc.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */



#include "ofstream_exc.hpp"

ofstream_exc
::ofstream_exc(std::string filename)
: f(filename)
{}

ofstream_exc
::ofstream_exc(std::string& filename)
: f(filename)
{}

template <typename T>
ofstream_exc& ofstream_exc
::operator<<(T other)
{
    if (!f)
        throw std::runtime_error("Cannot operate on stream: is bad");
    f << other;
    return *this;
}

template <typename T>
ofstream_exc& ofstream_exc
::operator<<(T& other)
{
    if (!f)
        throw std::runtime_error("Cannot operate on stream: is bad");
    f << other;
    return *this;
}

template ofstream_exc& ofstream_exc::operator<<(const char* other);
template ofstream_exc& ofstream_exc::operator<<(char other);
template ofstream_exc& ofstream_exc::operator<<(int other);
template ofstream_exc& ofstream_exc::operator<<(unsigned int other);
template ofstream_exc& ofstream_exc::operator<<(std::string other);
