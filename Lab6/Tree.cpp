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

void Tree::print()
{
    print(this->root, 0);
}

void Tree::printleafs()
{
    printleafs(this->root);
}

void Tree::print(Branch *node, int n)
{
    if (node)
    {
        n++;
        print(node->Left, n);
        for (int i = 0; i < n; i++) std::cout << "  ";
        std::cout << node->Data << std::endl;
        print(node->Right, n);
        n--;
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