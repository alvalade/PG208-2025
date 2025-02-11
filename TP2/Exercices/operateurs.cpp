/**
 * @file operateurs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <ostream>
#include <vector>
#include <string>




std::string operator*(const int m, std::string& s)
{
    std::string out {""};
    for (int i = 0 ; i < m ; i++)
    {
        out += s;
    }

    return out;
}

int operator*(std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.size() != v2.size())
        exit(1);

    int val = 0;
    for (size_t i = 0 ; i < v1.size() ; i++)
        val += v1[i] * v2[i];

    return val;
}

std::ostream& operator<<(std::ostream& os, std::vector<int>& v)
{
    os << "{";
    for (size_t i = 0 ; i < v.size() - 1 ; i++)
        os << v[i] << ", ";
    os << v[v.size() - 1] << "}\n";
    return os;
}

std::vector<int> operator<<(std::vector<int>& v, const int shift)
{
    std::vector<int> out;
    for (size_t i = 0 ; i < v.size() ; i++)
        out.push_back(v[((i+shift)%(v.size()))]);

    return out;
}



int main()
{
    std::vector<int> test {1,2,3,4};

    std::vector<int> test2 { test << 1};

    std::cout << test2 << std::endl;

    return 0;
}