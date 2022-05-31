#include "func.h"

Student *crstud(int *n)
{
    int num;
    std::string str;
    std::cout << "Введіть кількість студентів - ";
    std::cin >> num;
    while(num<=0)
    {
        std::cout << "Введіть дійсне число - ";
        std::cin >> num;
    }
    *n = num;
    Student *res = new Student[num];
    std::cout << "Введіть студентів за форматом - Ім'я;Дата народження(DD.MM.YYYY);Номер групи;Середній рейтинговий бал" << std::endl;
    std::cin.ignore();
    for (int i = 0; i < num; i++)
    {
        std::getline(std::cin, str);
        if (valstud(str)) 
        {
            Student temp(str);
            res[i]= temp;
        }
        else i--;
    }
    return res;
}

bool valstud(std::string str)
{
    std::vector<std::string> words;
    int n1 = 0, n2 = str.find(';'), n=0;
    while(n2!=-1 && n<4)
    {
        words.push_back(str.substr(n1,n2-n1));
        n++;
        n1 = n2+1;
        n2 = str.find(';', n1+1);
    }
    words.push_back(str.substr(n1,str.size()-n1));
    if(n!=3)
    {
        std::cout << "Некоректно введені дані" << std::endl;
        return false;
    }
    if(!dateval(words[1])) 
    {
        std::cout << "Некоректно введена дата" << std::endl;
        return false;
    }
    if(!isnum(words[2]))
    {
        std::cout << "Некоректно вказаний номер групи" << std::endl;
        return false;
    }
    if(!isnum(words[3]))
    {
        std::cout << "Некоректно введений середній бал" << std::endl;
        return false;
    }
    if(stoi(words[3])<0 || stoi(words[3])>100)
    {
        std::cout << "Некоректно введений середній бал" << std::endl;
        return false;
    }
    return true;
}

Lecturer *crlect(int *m)
{
    int num;
    std::string str;
    std::cout << "Введіть кількість викладачів - ";
    std::cin >> num;
    while(num<=0)
    {
        std::cout << "Введіть дійсне число - ";
        std::cin >> num;
    }
    *m = num;
    Lecturer *res = new Lecturer[num];
    std::cout << "Введіть викладачів за форматом - Ім'я;Дата народження(DD.MM.YYYY);Назва дисципліни;Кількість годин" << std::endl;
    std::cin.ignore();
    for (int i = 0; i < num; i++)
    {
        std::getline(std::cin, str);
        if (vallec(str)) 
        {
            Lecturer temp(str);
            res[i]= temp;
        }
        else i--;
    }
    return res;
}

bool vallec(std::string str)
{
    std::vector<std::string> words;
    int n1 = 0, n2 = str.find(';');
    while(n2!=-1)
    {
        words.push_back(str.substr(n1,n2-n1));
        n1 = n2+1;
        n2 = str.find(';', n1+1);
    }
    words.push_back(str.substr(n1,str.size()-n1));
    if(words.size()%2!=0)
    {
        std::cout << "Некоректно введені дані" << std::endl;
        return false;
    }
    if(!dateval(words[1])) 
    {
        std::cout << "Некоректно введена дата" << std::endl;
        return false;
    }
    for (int i = 3; i < words.size(); i+=2)
    {
        if(!isnum(words[i]))
        {
            std::cout << "Некоректно введена кількість годин" << std::endl;
            return false;
        }
    }
    return true;
}

bool dateval(std::string date)
{
    for (int i = 0; i < date.size(); i++) if (date[i]!='.' && !isdigit(date[i])) return false;
    int t1=date.find("."), t2=date.find(".", t1+1);
    if (t1==std::string::npos) return false;
    int day, mon, year;
    day = stoi(date.substr(0,t1));
    mon = stoi(date.substr(t1+1,t2-t1));
    year = stoi(date.substr(t2+1,date.size()-t2));
    if(day < 1 || mon < 1 || mon > 12 || year <= 1900) return false; 
    int val[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; // Кількість днів у кожному місяці року
    if(mon == 2 && (year%400==0)||((year%4==0)&&(year%100!=0)) && day > 29) return false;
    if(day > val[mon]) return false;
    return true;
}

bool isnum(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if(!std::isdigit(str[i]) && str[i]!='.')
        {
            return false;
        }
    }
    return true;
}

void print(Student *studs, int n)
{
    std::cout << "Список студентів:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << studs[i] << std::endl;
    }
}

void print(Lecturer *lects, int m)
{
    std::cout << "Список викладачів:" << std::endl;
    for (int i = 0; i < m; i++)
    {
        std::cout << lects[i] << std::endl;
    }
}

void calcsc(Student *studs, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Розмір місячної стипендії студента " << studs[i].GetName() << " - " << studs[i].earn() << "(" << studs[i].GetStat() << ")" << std::endl;
    }
}

void calcpay(Lecturer *lects, int m)
{
    std::vector<float> nums;
    for (int i = 0; i < m; i++)
    {
        nums.push_back(lects[i].earn());
        std::cout << "Розмір місячної заробіньої плати викладача " << lects[i].GetName() << " - " << nums[i] << std::endl;
    }
    int maxindx = distance(nums.begin(), max_element(nums.begin(), nums.end()));
    std::cout << "Найбільшу заробітню плату має викладач " << lects[maxindx].GetName() << "(" << lects[maxindx].years() << ") - " << nums[maxindx] << std::endl;
}

std::ostream& operator<< (std::ostream &out, Student stud)
{
    return out << stud.GetName() << ";" << stud.GetDate() << ";" << stud.GetGrnum() << ";" << stud.GetAvrat();
}

std::ostream& operator<< (std::ostream &out, Lecturer lect)
{
    out << lect.GetName() << ";" << lect.GetDate();
    std::vector<disciplines> dis = lect.GetDis();
    for (int i = 0; i < dis.size(); i++)
    {
        out << ";";
        out << dis[i].disname << ";" << dis[i].hours;
    }
    return out;
}