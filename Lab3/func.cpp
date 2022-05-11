#include "func.h"

Text *inputtexts(int *len)
{
    int n;
    std::cout << "Введіть кількість текстів - ";
    std::cin >> n; 
    if(n<=0)
    {
        std::cout << "Введіть натуральне число - ";
        std::cin >> n; 
    }
    *len = n;
    Text *texts = new Text[n];
    std::string row;
    for (int i = 0; i < n; i++)
    {
        if (ask("Вводити текст вручну?"))
        {
            std::cout << "Введіть текст:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, row);
            Text t(row);
            std::getline(std::cin, row);
            while(row.find(1) == std::string::npos) // Ознака кінця введення Ctrl+A
            {
                t.addRow(row);
                std::getline(std::cin, row);
            }
            texts[i] = t;
        }
        else 
        {
            Text t;
            texts[i] = t;
        }
    }
    return texts;
}

void addtotexts(Text texts[], int len)
{
    std::string row;
    for (int i = 0; i < len; i++)
    {
        if (ask("Додати рядок до тексту?"))
        {
            std::cout << "Введіть рядок:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, row);
            texts[i].addRow(row);
        }
    }
}

void countintext(Text texts[], int len)
{
    char ch;
    for (int i = 0; i < len; i++)
    {
        if (ask("Ввести свій символ для підрахунку?"))
        {
            std::cout << "Введіть символ - ";
            std::cin >> ch;
            std::cout << "Кількість входження символу " << ch << " в текст №" << i+1 << " - " << texts[i].count(ch) << std::endl;
        }
        else std::cout << "Кількість символів в тексті №" << i+1 << " - " << texts[i].count() << std::endl;
    }
}

void print(Text texts[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << "Текст №" << i+1 << ":" << std::endl;
        texts[i].printtxt();
    }
}

bool ask(std::string str)
{
    char ans;
    std::cout << str << " Y/N ";
    std::cin >> ans;
    while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
    {
        std::cout << "Y/N ";
        std::cin >> ans; 
    }
    if (ans == 'Y' || ans == 'y') return true;
    else return false;  
}