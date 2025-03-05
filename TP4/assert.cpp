#include <cassert>
#include <iostream>


void check_ptr_not_null(void* ptr)
{
    assert(ptr != nullptr && "Le pointeur nul a ete passe !");
    std::cout << "Le pointeur " << ptr << " est non nul !" << std::endl;
}

int main()
{
    int toto = 3;
    void* ptr = (void*) &toto;

    check_ptr_not_null(ptr);

    ptr = 0;

    check_ptr_not_null(ptr);

    return 0;
}