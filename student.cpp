#include "student.h"

Student::Student(int id, QString n, QString s, Date dateOB, QString e, QString p, QString cC, int sY) : Person(id, n, s, dateOB, e, p), courseCode(cC), studiesYear(sY){
}

Student::Student(){
    Id(0);
    Name("");
    Surname("");
    Date Date("01.01.2000");
    Email("");
    Password("");
    CourseCode("");
    StudiesYear(1);
}

QString Student::CourseCode(){
    return courseCode;
}

void Student::CourseCode(QString cC){
    courseCode = cC;
}

int Student::StudiesYear()
{
    return studiesYear;
}

void Student::StudiesYear(int sY)
{
    studiesYear = sY;
}

Student& Student::operator=(Student const &stud)
{
    if (this != &stud){
        Person::operator=(stud);
        courseCode = stud.courseCode;
    }
    return *this;
}
