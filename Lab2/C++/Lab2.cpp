#include "func.h"

int main()
{
    string path1 = "input.bin", path2 = "output.bin";
    inputfile(path1);
    croutfile(path1, path2);
    printfile(path1);
    printfile(path2);
    return 0;
}