#pragma once
#include <iostream>
#include <string>
#include <vector>

class Text
{
    std::vector<std::string> t;
public:
    Text();
    Text(std::string); 
    void addRow(std::string);
    int count();
    int count(char);
    void printtxt();
};