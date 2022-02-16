#include <iostream>
#include "func.h"

int main()
{
    string path1 = "input1.txt", path2 = "input2.txt", path3 = "output.txt";
    inputfile(path1, 1);
    inputfile(path2, 2);
    croutfile(path1, path2, path3);
    int flen = filelen(path3);
    cout << "Знайдено " << flen << " рядків" << endl;
    printfile(path1);
    printfile(path2);
    printfile(path3);
    return 0;
}