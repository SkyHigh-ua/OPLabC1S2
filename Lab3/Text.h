#pragma once
#include <iostream>
#include <string>
#include <vector>

class Text
{
    std::vector<std::string> t;
public:
    Text(); // Конструктор для створення тексту без введеного рядка
    Text(std::string); // Конструктор для створення тексту за введеним рядком 
    void addRow(std::string); // Додавання рядка до тексту
    std::string GetText(); // Повертає текст у вигляді строки
    int count(); // Підрахунок усіх символів в тексті
    int count(char); // Підрахунок введеного символу в тексті
    void printtxt(); // Виведення тексту
};