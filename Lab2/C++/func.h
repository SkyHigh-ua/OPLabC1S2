#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

struct customer
{
    string surn;
    char sex;
    string age;
    int amt;
};

void inputfile(string); // Введення файлу через консоль
bool validation(customer, bool); // Перевірка введених даних
bool strtostruct(string, customer *); // Переведення зі строки в структуру
int years(string); // Визначення кількості років 
void croutfile(string, string); // Створення вихідного файлу
int disc(string, int); // Визначення ціни зі знижкою
vector<customer> lstlines(string); // Створення вектора з файлу
void printfile(string); // Вивід файлу в консоль