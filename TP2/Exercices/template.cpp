/**
 * @file template.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <array>

template <typename T>
T total(std::vector<T>& v)
{
    T out {(T)0};

    for (const auto& e: v)
        out += e;

    return out;
}

std::string total(std::vector<std::string>& v)
{
    std::string out {""};
    for (const auto& e: v)
        out += e;

    return out;
}

template <typename T>
void display(std::vector<T>& v)
{
    for (size_t i {0} ; i < v.size() ; i++)
        std::cout << i << " : " << v[i] << std::endl;
}

template <typename T, size_t t>
void display(std::array<T, t>& a)
{
    for (size_t i {0} ; i < a.size() ; i++)
        std::cout << i << " : " << a[i] << std::endl;
}

template <typename K, typename V>
void display(std::unordered_map<K, V>& m)
{
    for (const auto& p: m)
        std::cout << p.first << " : " << p.second << std::endl;
}

int main()
{
    std::vector<int> test_int {1,2,3};
    std::vector<std::string> test_str {"fuck ", "tumors"};

    std::cout << total(test_int) << std::endl;
    std::cout << total(test_str) << std::endl;
    return 0;
}