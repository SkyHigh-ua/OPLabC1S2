#pragma once
#include "Text.h"

Text *inputtexts(int *);
void addtotexts(Text [], int);
void countintext(Text [], int);
char findmax(Text [], int, int *);
int find(std::vector<char>, char);
int max(std::vector<int>);
void print(Text [], int);
bool ask(std::string);