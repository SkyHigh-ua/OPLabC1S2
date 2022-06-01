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
    Branch *add(char, Branch *);
    void printleafs(Branch *);
    void print(Branch *);
    void printbylvl(int, Branch *);
    void remove(Branch *);
public:
    Tree(std::string);
    int height(Branch *);
    void printleafs();
    void print();
    ~Tree();
};
