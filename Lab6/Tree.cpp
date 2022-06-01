#include "Tree.h"

Tree::Tree(std::string data)
{
    this->root = new Branch(data[0]);
    if (data.size()>1) for (int i = 1; i < data.size(); i++) this->root = add(data[i], this->root);
}

Branch *Tree::add(char tData, Branch *node)
{
    if (node)
    {
        if (node->Data>=tData)
        {
            if (!node->Left) node->Left = new Branch(tData);
            else add(tData, node->Left);
        }
        else 
        {
            if (!node->Right) node->Right = new Branch(tData);
            else add(tData, node->Right);
        }
    }
    else node = new Branch(tData);
    return node;
}

int Tree::height(Branch *node)
{
    int ln = 0, rn = 0;
    if(node) 
    {
        if(node->Left) ln = height(node->Left);
        if(node->Right) rn = height(node->Right);
    }
    return std::max(ln,rn)+1;
}

void Tree::print()
{
    print(this->root);
}

void Tree::printleafs()
{
    printleafs(this->root);
}

void Tree::print(Branch *node)
{
    int h = height(node);
    int i;
    for (i=1; i<=h; i++)
    {
        printbylvl(i, node);
        std::cout << std::endl;
    }
}

void Tree::printbylvl(int lvl, Branch *node)
{
    if(node)
    {
        if (lvl == 1) std::cout << node->Data << " ";
        else if (lvl > 1)
        {
            printbylvl(lvl-1, node->Left);
            printbylvl(lvl-1, node->Right);
        }
    }
}

void Tree::printleafs(Branch *node)
{
    if(node)
    {
        printleafs(node->Left);
        if (!node->Left && !node->Right)
            std::cout << node->Data << " ";
        printleafs(node->Right);
    }
}

void Tree::remove(Branch *node)
{
    if (node) 
    {
        remove(node->Left);
        remove(node->Right);
        delete node;
    }
}

Tree::~Tree()
{
    remove(this->root);
}