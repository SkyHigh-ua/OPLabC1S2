#include "func.h"

void inputfile(string path)
{
    bool val;
    string str, ans;
    customer *cust = new customer;
    ofstream file;
    ifstream f(path, ofstream::binary);
    if (f.is_open())
    {
        if(!f.eof())
        {
            cout << "Очистити файл? Y/N ";
            cin >> ans;
            while(!((ans == "Y" || ans == "y") || (ans == "N" || ans == "n")))
            {
                cout << "Введіть Y або N ";
                cin >> ans;
            }
            if(ans == "Y" || ans == "y") file.open(path, ofstream::binary);
            else if(ans == "N" || ans == "n") file.open(path, ofstream::app | ofstream::binary);
            cin.ignore();
        }
    }
    else file.open(path, ofstream::binary);
    f.close();
    cout << "Введіть данні покупців за шаблоном Прізвище;Стать(M/W);Дата народження(DD.MM.YYYY);Кількість товару" << endl;
    getline(cin, str);
    while(str.find(1) == string::npos) //Ознака кінця введення файлу Ctrl+A
    {
        val = strtostruct(str, &*cust);
        if(validation(*cust, val)) file.write((char*)cust, sizeof(customer));
        getline(cin, str);
    }
    file.close();
}

bool validation(customer cust, bool val)
{
    if(!val)
    {
        cout << "Некоректно введені дані" << endl;
        return false;
    }
    if(cust.sex != 'M' && cust.sex != 'm' && cust.sex != 'W' && cust.sex != 'w')
    {
        cout << "Некоректно введена стать" << endl;
        return false;
    }
    int age = years(cust.age);
    if(age < 16 || age >= 122) 
    {
        if(age >= 0)
        {
            if (age < 16) cout << "Введена дата замала" << endl;
            else cout << "Введена дата завелика" << endl;
        }
        else cout << "Некоректно введена дата" << endl;
        return false;
    }
    if(cust.amt <= 0)
    {
        cout << "Некоректно введена кількість товару" << endl;
        return false;
    }
    return true;
}

bool strtostruct(string str, customer *cust)
{
    vector<string> words;
    int n1 = 0, n2 = str.find(';'), n = 0;
    while(n2!=-1 && n<4)
    {
        words.push_back(str.substr(n1,n2-n1));
        n++;
        n1 = n2+1;
        n2 = str.find(';', n1+1);
    }
    words.push_back(str.substr(n1,str.size()-n1));
    if(n==3)
    {
    cust->surn = words[0];
    cust->sex = words[1][0];
    cust->age = words[2];
    cust->amt = stoi(words[3]);
    return true;
    }
    return false;
}

int years(string date)
{
    int val[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; // Кількість днів у кожному місяці року
    int age, day, mon;
    int t1=date.find("."), t2=date.find(".", t1+1);
    struct tm inpdate;
    day = stoi(date.substr(0,t1));
    mon = stoi(date.substr(t1+1,t2-t1));
    if(day < 1 || day > val[mon] || mon < 1 || mon > 12) return -1; 
    inpdate.tm_mday = day;
    inpdate.tm_mon = mon-1;
    inpdate.tm_year = stoi(date.substr(t2+1,date.size()-t2))-1900;
    inpdate.tm_hour = 0;
    inpdate.tm_min = 0;
    inpdate.tm_sec = 0;
    time_t dt1, dt2 = mktime(&inpdate);
    time(&dt1);
    age = difftime(dt1, dt2)/(60*60*24*365.2425);
    return age;
}

void croutfile(string path1, string path2)
{
    ifstream inpf(path1, ofstream::binary);
    ofstream outf(path2, ofstream::binary);
    customer *cust = new customer;
    string ans;
    int price;
    bool swpr = false;
    cout << "Виводити вартість товарів? Y/N ";
    cin >> ans;
    while(!((ans == "Y" || ans == "y") || (ans == "N" || ans == "n")))
    {
        cout << "Введіть Y або N ";
        cin >> ans;
    }
    if(ans == "Y" || ans == "y") swpr = true;
    while(inpf.read((char*)cust, sizeof(customer))) 
    {
        price = disc(cust->age, cust->amt);
        if(price>250) outf.write((char*)cust, sizeof(customer));
        if(swpr) cout << cust->surn << " - " << price << endl;
    }
    outf.close();
}  

int disc(string date, int amt)
{
    int n=amt*100, age=years(date);
    if(age<60) n-=n*age*0.01;
    else if(age>=95) n-=n*0.99;
    else n-=n*((age*0.01)+0.05);
    return n;
}

vector<customer> lstlines(string path)
{
    ifstream file(path, ofstream::binary);
    customer *cust = new customer;
    vector<customer> lst;
    while (file.read((char*)cust, sizeof(customer))) lst.push_back(*cust);
    file.close();
    return lst;
}

void printfile(string path)
{
    cout << "Зміст файлу " << path << endl;
    vector<customer> lst = lstlines(path);
    if (lst.size()!=0)
    {
        for (int i = 0; i < lst.size(); i++) cout << lst[i].surn << ";" << lst[i].sex << ";" << lst[i].age << ";" << lst[i].amt << endl;
    }
    else cout << "Файл пустий" << endl;
}