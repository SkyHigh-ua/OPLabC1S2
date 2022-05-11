#include "func.h"

int main()
{
    int deg, r, phi, thet;
    std::string str;
    inputdat(&str, &r, &phi, &thet);
    Vector B1(str), B2(r, phi, thet), B3;
    inputdeg(&deg);
    B1+=deg;
    B1.deccord();
    findout(B2, B3);
    return 0;
}