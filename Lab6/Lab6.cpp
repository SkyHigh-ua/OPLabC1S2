#include "Tree.h"

int main()
{
    std::string str;
    std::cout << "Введіть набір символів - ";
    std::getline(std::cin, str);
    while(str.size()<1)
    {
        std::cout << "Введіть набір символів - ";
        std::getline(std::cin, str);
    }
    Tree tree(str);
    std::cout << "Сформоване дерево на основі введених символів:" << std::endl;
    tree.print();
    std::cout << std::endl;
    std::cout << "Термінальні вершини цього дерева:" << std::endl;
    tree.printleafs();
    std::cout << std::endl;
    return 0;
}