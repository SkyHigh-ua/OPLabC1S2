#include "Text.h"

Text::Text()
{
    this->t.push_back("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
}

Text::Text(std::string t)
{
    this->t.push_back(t);
}

void Text::addRow(std::string row)
{
    this->t.push_back(row);
}

std::string Text::GetText()
{
    std::string txt;
    for (int i = 0; i < this->t.size(); i++)
    {
        txt += this->t[i];
    }
    return txt;
}

int Text::count()
{
    int res = 0;
    for (int i = 0; i < this->t.size(); i++)
    {
        for (int j = 0; j < this->t[i].size(); j++)
        {
            if (this->t[i][j] != ' ') res++;
        }
    }
    return res;
}

int Text::count(char ch)
{
    int res = 0;
    for (int i = 0; i < this->t.size(); i++)
    {
        for (int j = 0; j < this->t[i].size(); j++)
        {
            if (this->t[i][j] == ch) res++;
        }
    }
    return res;
}

void Text::printtxt()
{
    for (int i = 0; i < this->t.size(); i++)
    {
        std::cout << this->t[i] << std::endl;
    }
}