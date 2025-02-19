#include <iostream>


int main()
{
    float a = 0.3;
    float b = 0.30000000000000004;

    if (a == b)
        std::cout << "Les floats c'est dangereux !" << std::endl;

    return 0;
}