#include "Vector.h"

int main()
{
    int deg;
    Vector B1("30,20,20"), B2(50,60,30), B3;
    std::cout << "Введіть величину на яку збільшити полярний кут = ";
    std::cin >> deg;
    B1+=deg;
    B1.deccord();
    if(B2!=B3) std::cout << "Вектори не колінеарні" << std::endl;
    else std::cout << "Вектори колінеарні" << std::endl;
    return 0;
}