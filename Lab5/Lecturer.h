#pragma once
#include "Person.h"

struct disciplines
{
    std::string disname; // Назва дисципліни
    int hours; // Кількість годин
};

class Lecturer : public Person
{
private:
    std::vector<disciplines> dis; // Дисципліни
public:
    Lecturer();
    Lecturer(std::string, std::string, std::vector<std::string>, std::vector<int>);
    Lecturer(std::string);
    float earn(); // Підрахунок місячної заробітньої плати
    std::vector<disciplines> GetDis(); // Повертає дисципліни
};