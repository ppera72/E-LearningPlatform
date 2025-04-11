#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
private:
    int day, month, year;
public:
    Date(int day, int month, int year);
    Date(std::string date);
    Date();

    int Day() const;
    int Month() const;
    int Year() const;

    void Day(int d);
    void Month(int m);
    void Year(int y);

    std::string wholeDate();
    void correctDate();
    int compareDates(Date diffDate);
};

#endif // DATE_H
