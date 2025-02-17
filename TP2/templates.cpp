#include <iostream>
#include <array>

// Je vous avais dit qu'on aurait une methode pour
// instantier des std::array de taille arbitraire
template <typename CONTENT, std::size_t SIZE>
std::array<CONTENT, SIZE> operator+(const std::array<CONTENT, SIZE>& t1, const std::array<CONTENT, SIZE>& t2)
{
    std::array<CONTENT, SIZE> res;
    for (size_t i { 0 } ; i < t1.size() ; i++)
    {
        res[i] = t1[i] + t2[i];
    }
    return res;
}


int main()
{
    std::array<int, 3> Array_1 {1,2,3};
    std::array<int, 3> Array_2 {4,5,6};

    std::array<float, 5> Array_3 {1.,2.,3.,4.,5.};
    std::array<float, 5> Array_4 {2.,4.,6.,8.,10.};

    std::array<int, 3> Res_1 { Array_1 + Array_2 };
    std::array<float, 5> Res_2 { Array_3 + Array_4 };

    std::cout << "CONTENT = INT, SIZE = 3" << std::endl;
    for (int i {0} ; i < 3 ; i++)
        std::cout << Array_1[i] << " + " << Array_2[i] << " = " << Res_1[i] << std::endl;
    std::cout << std::endl;


    std::cout << "CONTENT = FLOAT, SIZE = 5" << std::endl;
    for (int i {0} ; i < 5 ; i++)
        std::cout << Array_3[i] << " + " << Array_4[i] << " = " << Res_2[i] << std::endl;
}