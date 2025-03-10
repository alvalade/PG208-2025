/**
 * @file ifstream_exc.hpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-03-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <string>
#include <fstream>

class ifstream_exc
{
public:
    ifstream_exc(std::string filename);
    ifstream_exc(std::string& filename);

    template <typename T>
    ifstream_exc& operator>>(T& other);
private:

private:
    std::ifstream f;
};