/**
 * @file ofstream_exc.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdexcept>
#include <fstream>
#include <iostream>

class ofstream_exc
{
public:
    ofstream_exc(std::string filename);
    ofstream_exc(std::string& filename);

    template <typename T>
    ofstream_exc& operator<<(T& other);

    template <typename T>
    ofstream_exc& operator<<(T other);
private:

private:
    std::ofstream f;
};