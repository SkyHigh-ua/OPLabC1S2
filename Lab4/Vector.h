#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Vector
{
private:
    int r; // Відстань від початку координат
    int phi; // Азимутальний кут
    int thet; // Полярний кут
public:
    Vector(); // Створення вектора 
    Vector(int, int, int); // Створення вектора за введеними даними
    Vector(std::string); // Створення вектора за введеною строкою
    Vector operator+=(int); // Збільшити полярний кут на задану величину
    bool operator!=(Vector &); // Перевірити на неколінеарність
    void deccord(); // Отримати декартові координати на вивід
    void deccord(float *, float *, float *); // Отримати декартові координати у задані змінні
    int Getr(); // Отримати відстань від початку координат
    int Getphi(); // Отримати азимутальний кут
    int Getthet(); // Отримати полярний кут
};