#pragma once
#include <iostream>
#include <iomanip>
#include <string>

struct Branch
{
    char Data;
    Branch *Left;
    Branch *Right;
    Branch(char (ch)): Data(ch), Left(NULL), Right(NULL) {};
};

class Tree
{
    Branch *root;
    Branch *add(char, Branch *); // Додавання елементу до дерева
    void printleafs(Branch *); // Знаходження і виведення термінальних вершин
    void print(Branch *, int); // Виведення дерева
    void remove(Branch *); // Видалення дерева
public:
    Tree(std::string);
    void printleafs();
    void print();
    ~Tree();
};
