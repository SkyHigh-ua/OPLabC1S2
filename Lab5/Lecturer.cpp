#include "Lecturer.h"

Lecturer::Lecturer()
{
    this->fname = "Noname";
    this->date = "01.01.1901";
}

Lecturer::Lecturer(std::string fname, std::string date, std::vector<std::string> disname, std::vector<int> hours)
{
    this->fname = fname;
    this->date = date;
    disciplines dat;
    for (int i = 0; i < disname.size(); i++)
    {
        dat.disname = disname[i];
        dat.hours = hours[i];
        this->dis.push_back(dat);
    }
}

Lecturer::Lecturer(std::string str)
{ 
    std::string fname, date;
    std::vector<std::string> disname;
    std::vector<int> hours;
    int n1 = 0, n2 = str.find(';');
    fname = str.substr(n1,n2-n1);
    n1 = n2+1;
    n2 = str.find(';', n1+1);
    date = str.substr(n1,n2-n1);
    n1 = n2+1;
    n2 = str.find(';', n1+1);
    std::vector<std::string> words;
    while(n2!=-1)
    {
        words.push_back(str.substr(n1,n2-n1));
        n1 = n2+1;
        n2 = str.find(';', n1+1);
    }
    words.push_back(str.substr(n1,str.size()-n1));
    for(int i = 0; i<words.size(); i+=2)
    {
        disname.push_back(words[i]);
    }
    for(int i = 1; i<words.size(); i+=2)
    {
        hours.push_back(stoi(words[i]));
    }    
    this->fname = fname;
    this->date = date;
    disciplines dat;
    for (int i = 0; i < disname.size(); i++)
    {
        dat.disname = disname[i];
        dat.hours = hours[i];
        this->dis.push_back(dat);
    }
} 

float Lecturer::earn()
{
    int hours = 0;
    for (int i = 0; i < this->dis.size(); i++)
    {
        hours += this->dis[i].hours;
    }
    return 100*hours;
}

std::vector<disciplines> Lecturer::GetDis()
{
    return this->dis;
}