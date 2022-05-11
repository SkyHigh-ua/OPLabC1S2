#include "func.h"

void inputdat(std::string *str, int *r, int *phi, int *thet)
{
    std::string ts;
    int tr, tp, tt;
    std::cout << "Введіть значення першого вектора (Напр. - 30,20,40) - ";
    std::getline(std::cin, ts);
    *str = ts;
    std::cout << "Введіть значення другого вектора (Напр. - 30,20,40) - ";
    std::getline(std::cin, ts);
    int n1 = ts.find(','), n2 = ts.find(',', n1+1);
    tr = std::stoi(ts.substr(0,n1));
    tp = std::stoi(ts.substr(n1+1,n2-n1-1));
    tt = std::stoi(ts.substr(n2+1,ts.size()-n2));
    *r = tr;
    *phi = tp;
    *thet = tt;
}

void inputdeg(int *d)
{
    int deg;
    std::cout << "Введіть величину на яку збільшити полярний кут = ";
    std::cin >> deg;
    *d = deg;
}

void findout(Vector B2, Vector B3)
{
    if(B2!=B3) std::cout << "Вектори не колінеарні" << std::endl;
    else std::cout << "Вектори колінеарні" << std::endl;
}