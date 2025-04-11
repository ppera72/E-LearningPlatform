#include "date.h"
#include <vector>
#include <sstream>
#include <iomanip>
#include <QDebug>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { correctDate();}

Date::Date(std::string date){
    std::vector<int> dateOB;

    dateOB.push_back(stoi(date.substr(0, 2)));
    dateOB.push_back(stoi(date.substr(3, 5)));
    dateOB.push_back(stoi(date.substr(6, 10)));

    day = dateOB[0];
    month = dateOB[1];
    year = dateOB[2];

    correctDate();
}

Date::Date(){}


int Date::Day() const
{
    return day;
}

int Date::Month() const
{
    return month;
}

int Date::Year() const
{
    return year;
}

void Date::Day(int d)
{
    day = d;
}

void Date::Month(int m)
{
    month = m;
}

void Date::Year(int y)
{
    year = y;
}

void Date::correctDate()
{
    bool isLeap = false;
    int maxDaysOfMonth[] = {31, 29, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        isLeap = true;

    if (month == 2) {
        if (!isLeap && day == 29)
            day = 28;
    }
    if (day >= 32)
        day = maxDaysOfMonth[month - 1];
    else if (day <= 0)
        day = 1;

    if (month > 12)
        month = 12;
    else if (month < 1)
        month = 1;
}

int Date::compareDates(Date diffDate)
{
    if(diffDate.Year() < this->Year())
        return -1;
    else if(diffDate.Year() > this->Year())
        return 1;
    else if(diffDate.Month() < this->Month())
        return -1;
    else if(diffDate.Month() > this->Month())
        return 1;
    else if(diffDate.Day() < this->Day())
        return -1;
    else if(diffDate.Day() > this->Day())
        return 1;

    return 0;
}



std::string Date::wholeDate(){
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << day << "-"<< std::setfill('0') << std::setw(2) << month << "-" << Year();
    std::string help = oss.str();
    return help;
}
