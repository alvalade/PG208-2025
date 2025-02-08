#include <iostream>
#include <string>

using namespace std::literals;

int main()
{
    std::string mystring;
    mystring = "Hello "s;
    mystring += "World!"s;
    
    std::cout << mystring << std::endl;

    return 0;
}