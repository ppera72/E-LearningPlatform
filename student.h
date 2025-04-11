#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "date.h"
#include <QString>

class Student: public Person
{
private:
    QString courseCode;
    int studiesYear;
public:
    Student(int id, QString n, QString s, Date dateOB, QString e, QString p, QString cC, int sY);
    Student();

    QString CourseCode();
    void CourseCode(QString cC);
    int StudiesYear();
    void StudiesYear(int sY);
    Student& operator=(Student const &stud);
};

#endif // STUDENT_H
