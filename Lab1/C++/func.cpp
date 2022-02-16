#include "func.h"

void inputfile(string path, int num)
{
    string str;
    ofstream file(path);
    cout << "Введіть текст " << num << "-го файлу:" << endl;
    getline(cin, str);
    while(str[str.length()-1] != 1) //Ознака кінця введення файлу Ctrl+A
    {
        file << str << endl;
        getline(cin, str);
    }
    file.close();
}

void croutfile(string path1, string path2, string path3)
{
    ofstream outf(path3);
    vector<string> lst = matchlines (path1, path2);
    for (int i = 0; i < lst.size(); i++) outf << lst[i] << endl;
    outf.close();
}  

vector<string> matchlines(string path1, string path2)
{
    vector<string> inpf1 = lstlines(path1);
    vector<string> inpf2 = lstlines(path2);
    vector<string> lst;
    for (int i = 0; i < inpf1.size(); i++)
    {
        if (find(inpf2.begin(), inpf2.end(), inpf1[i])==inpf2.end()) lst.push_back(inpf1[i]);
    }
    return lst;
}

vector<string> lstlines(string path)
{
    ifstream file(path);
    string str;
    vector<string> lst;
    while(getline(file, str)) lst.push_back(str);
    file.close();
    return lst;
}

int filelen(string path)
{
    int res = 0;
    string temp;
    ifstream file(path);
    while(getline(file, temp)) res++;
    file.close();
    return res;
}

void printfile(string path)
{
    cout << "Зміст файлу " << path << endl;
    vector<string> lst = lstlines(path);
    if (lst.size()!=0)
    {
        for (int i = 0; i < lst.size(); i++) cout << lst[i] << endl;
    }
    else cout << "Файл пустий" << endl;
}