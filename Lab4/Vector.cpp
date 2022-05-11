#include "Vector.h"

Vector::Vector()
{
    this->r = 10;
    this->phi = 10;
    this->thet = 10;
}

Vector::Vector(int r, int phi, int thet)
{
    if(r<0) throw std::invalid_argument("Неправильно вказана відстань");
    this->r = r;
    if(phi<0 || phi>=360) throw std::invalid_argument("Неправильно вказаний азимутальний кут");
    this->phi = phi;
    if(thet<0 || thet>180) throw std::invalid_argument("Неправильно вказаний полярний кут");
    this->thet = thet;
}

Vector::Vector(std::string str)
{
    std::string r, phi, thet;
    int n1 = str.find(','), n2 = str.find(',', n1+1);
    r = str.substr(0,n1);
    phi = str.substr(n1+1,n2-n1-1);
    thet = str.substr(n2+1,str.size()-n2);
    this->r = std::stoi(r);
    this->phi = std::stoi(phi);
    this->thet = std::stoi(thet);
}

Vector Vector::operator+=(int deg)
{
    Vector temp;
    temp.r = this->r;
    temp.phi = this->phi;
    int t = this->thet+deg;
    while(t>180) t-=180;
    temp.thet = t;
    return temp;
}

bool Vector::operator!=(Vector &oth)
{
    float n1, n2, n3;
    float x1, y1, z1;
    this->deccord(&x1, &y1, &z1);
    float x2, y2, z2;
    oth.deccord(&x2, &y2, &z2);
    if(x1==0 || x2==0 || y1==0 || y2==0 || z1==0 || z2==0) throw std::invalid_argument("Координати одного з векторів дорівнюють 0");
    n1 = x1/x2;
    n2 = y1/y2;
    n3 = z1/z2;
    if(n1!=n2 && n2!=n3 && n1!=n3) return true;
    else return false;
}

void Vector::deccord()
{
    float x, y, z;
    x = this->r*sin(this->thet)*cos(this->phi);
    z = this->r*cos(this->thet);
    y = z*sin(this->phi);
    std::cout << "Декартові координати:" << std::endl << "x - " << x << std::endl << "y - " << y << std::endl << "z - "<< z << std::endl;
}

void Vector::deccord(float *x, float *y, float *z)
{
    *x = this->r*sin(this->thet)*cos(this->phi);
    *z = this->r*cos(this->thet);
    *y = this->r*cos(this->thet)*sin(this->phi);
}

int Vector::Getr()
{
    return this->r;
}

int Vector::Getphi()
{
    return this->phi;
}

int Vector::Getthet()
{
    return this->thet;
}