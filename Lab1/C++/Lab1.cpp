#include <iostream>
#include <fstream>

void inputfile(std::string, int);

int main()
{
    std::string path1 = "input1.txt", path2 = "input2.txt", path3 = "output.txt";
    inputfile(path1, 1);
    inputfile(path2, 2);
    return 0;
}

void inputfile(std::string path, int num)
{
    std::string str;
    std::ofstream file(path);
    std::cout << "Введіть текст " << num << "-го файлу:" << std::endl;
    getline(std::cin, str);
    while(str[str.length()-1] != 1) //Ознака кінця введення файлу Ctrl+A
    {
        file << str;
        getline(std::cin, str);
    }
    file.close();
}
