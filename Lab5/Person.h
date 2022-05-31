#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Person
{
protected:
    std::string fname; // Ім'я
    std::string date; // Дата народження
    int years(std::string); // Знаходження віку за рядком
public:
    int years(); // Знаходження віку
    virtual float earn() = 0;  // Підрахунок місячної заробітньої плати
    std::string GetName(); // Повертає ім'я
    std::string GetDate(); // Повертає дату народження
};