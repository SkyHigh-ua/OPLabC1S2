#pragma once
#include "Text.h"

Text *inputtexts(int *); // Введення текстів з консолі
void addtotexts(Text [], int); // Введення додаткового рядку до тексту
void countintext(Text [], int); // Підрахунок введеного символу в тексті
char findmax(Text [], int, int *); // Знаходження символу що більше всього повторюється у всіх текстах
int find(std::vector<char>, char); // Знаодження індексу елемента у векторі символів
int max(std::vector<int>); // Знаходження індексу максимального елемента у векторі чисел
void print(Text [], int); // Виведення текстів
bool ask(std::string); // Виведення запиту в консоль