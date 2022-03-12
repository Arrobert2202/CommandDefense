#include <iostream>
#include "Math.h"

int main()
{
    //Example for static int Add(int, int)
    std::cout << Math::Add(4, 19) << '\n';

    // Example for static int Add(int, int, int)
    std::cout << Math::Add(4, 19, 7) << '\n';

    // Example for static int Add(double, double)
    std::cout << Math::Add(5.9, 10.0) << '\n';

    // Example for static int Add(double, double, double)
    std::cout << Math::Add(7.5, 12.7,23.4)<< '\n';

    // Example for static int Mul(int, int)
    std::cout << Math::Mul(4, 19) << '\n';

    // Example for static int Mul(int, int, int)
    std::cout << Math::Mul(4, 19,2)<< '\n';

    // Example for static int Mul(double, double)
    std::cout << Math::Mul(3.5, 19.4) << '\n';

    // Example for static int Mul(double, double, double)
    std::cout << Math::Mul(3.0, 12.5,9.9)<< '\n';

    //Example for static int Add(int count, ...)
    std::cout << Math::Add(4, 2, 7, 10, 29) << '\n';

    // Example for static char* Add(const char*,const char*)
    std::cout << Math::Add("Rob", "ert")<< '\n';
    return 0;
}