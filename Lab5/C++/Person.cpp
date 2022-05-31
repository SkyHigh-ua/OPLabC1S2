#include "Person.h"

int Person::years()
{
    std::string date = this->date;
    int age, day, mon, year;
    int t1=date.find("."), t2=date.find(".", t1+1);
    struct tm inpdate;
    day = stoi(date.substr(0,t1));
    mon = stoi(date.substr(t1+1,t2-t1));
    year = stoi(date.substr(t2+1,date.size()-t2));
    inpdate.tm_mday = day;
    inpdate.tm_mon = mon-1;
    inpdate.tm_year = year-1900;
    inpdate.tm_hour = 0;
    inpdate.tm_min = 0;
    inpdate.tm_sec = 0;
    time_t dt1, dt2 = mktime(&inpdate);
    time(&dt1);
    age = difftime(dt1, dt2)/(60*60*24*365.2425);
    return age;
}

int Person::years(std::string date)
{
    int age, day, mon, year;
    int t1=date.find("."), t2=date.find(".", t1+1);
    struct tm inpdate;
    day = stoi(date.substr(0,t1));
    mon = stoi(date.substr(t1+1,t2-t1));
    year = stoi(date.substr(t2+1,date.size()-t2));
    inpdate.tm_mday = day;
    inpdate.tm_mon = mon-1;
    inpdate.tm_year = year-1900;
    inpdate.tm_hour = 0;
    inpdate.tm_min = 0;
    inpdate.tm_sec = 0;
    time_t dt1, dt2 = mktime(&inpdate);
    time(&dt1);
    age = difftime(dt1, dt2)/(60*60*24*365.2425);
    return age;
}

std::string Person::GetName()
{
    return this->fname;
}

std::string Person::GetDate()
{
    return this->date;
}