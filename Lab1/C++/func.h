#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void inputfile(string, int); // Введення файлу через консоль
void croutfile(string, string, string); // Створення вихідного файлу
vector<string> matchlines(string, string); // Пошук однакових рядків
vector<string> lstlines(string); // Створення вектора з файлу
int filelen(string); // Визначення кількості рядків у файлі
void printfile(string); // Вивід файлу в консоль