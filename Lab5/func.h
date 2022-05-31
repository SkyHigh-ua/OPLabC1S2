#pragma once
#include "Person.h"
#include "Student.h"
#include "Lecturer.h"

Student *crstud(int *); // Створення масиву студентів
Lecturer *crlect(int *); // Створення масиву викладачів
bool valstud(std::string); // Валідація рядку, що описує студента
bool vallec(std::string); // Валідація рядку, що описує викладача
bool dateval(std::string); // Перевірка коректності введеної дати
bool isnum(std::string); // Перевірка - чи є рядок числом
void print(Student *, int); // Виведення студентів
void print(Lecturer *, int); // Виведення икладачів
void calcsc(Student *, int); // Підрахунок стипендії студентів
void calcpay(Lecturer *, int); // Підрахунок заробітньої плати викладачів
std::ostream& operator<< (std::ostream &, Student); // Виведення атрибутів класу студент
std::ostream& operator<< (std::ostream &, Lecturer); // Виведення атрибутів класу викладач