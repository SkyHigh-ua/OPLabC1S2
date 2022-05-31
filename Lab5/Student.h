#pragma once
#include "Person.h"

class Student : public Person
{
private:
    int grpnum; // Номер групи
    float avratsc; // Середній рейтинговий бал
    std::string scholstat; // Статус отримання стипендії
public:
    Student();
    Student(std::string, std::string, int, float);
    Student(std::string);
    float earn(); // Підрахунок стипендії
    int GetGrnum(); // Повертає номер групи
    float GetAvrat(); // Повертає середній рейтинговий бал
    std::string GetStat(); // Повертає статус отримання стипендії
};