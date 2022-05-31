#include "Student.h"

Student::Student()
{
    this->fname = "Noname";
    this->date = "01.01.1901";
}

Student::Student(std::string fname, std::string date, int grpnum, float avratsc)
{ 
    this->fname = fname;
    this->date = date;
    this->grpnum = grpnum;
    this->avratsc = avratsc;
    if (avratsc > 95) this->scholstat = "Підвищена";
    else if(avratsc > 85) this->scholstat = "Звичайна";
    else this->scholstat = "Немає";
}   

Student::Student(std::string str)
{ 
    std::string fname, date;
    int grpnum;
    float avratsc;
    std::vector<std::string> words;
    int n1 = 0, n2 = str.find(';');
    for(int i=0; i<4; i++)
    {
        words.push_back(str.substr(n1,n2-n1));
        n1 = n2+1;
        n2 = str.find(';', n1+1);
    }
    words.push_back(str.substr(n1,str.size()-n1));
    fname = words[0];
    date = words[1];
    grpnum = stoi(words[2]);
    avratsc = stoi(words[3]);
    this->fname = fname;
    this->date = date;
    this->grpnum = grpnum;
    this->avratsc = avratsc;
    if (avratsc > 95) this->scholstat = "Підвищена";
    else if(avratsc > 85) this->scholstat = "Звичайна";
    else this->scholstat = "Немає";
} 

float Student::earn()
{
    std::string stat = this->scholstat;
    if (stat == "Підвищена") return 2000;
    else if(stat == "Звичайна") return 1000;
    else return 0;
}

int Student::GetGrnum()
{
    return this->grpnum;
}

float Student::GetAvrat()
{
    return this->avratsc;
}

std::string Student::GetStat()
{
    return this->scholstat;
}