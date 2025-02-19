/**
 * @file fichiers.cpp
 * @author Alexandre Valade (alvalade@enseirb-matmeca.fr)
 * @brief 
 * @version 0.1
 * @date 2025-02-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void write_file(std::ofstream& fout, std::vector<std::string>& buffer)
{
    for (int i = buffer.size() - 1 ; i >= 0 ; i--)
        fout << buffer[i] << "\n";
}

void read_file(std::ifstream& fin, std::vector<std::string>& buffer)
{
    std::string tmp {""};
    while (std::getline(fin, tmp))
    {
        buffer.push_back(tmp);
        std::cout << "Write " << tmp << " to buffer" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " src dst" << std::endl;
        return 1;
    }

    std::ifstream fin { argv[1] };
    std::ofstream fout { argv[2] };
    std::vector<std::string> buffer; // /!\ vecteur VIDE

    read_file(fin, buffer);
    write_file(fout, buffer);
    

    return 0;
}