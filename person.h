#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "date.h"

class Person
{
private:
    QString name, surname, email, password;
    int id;
    Date dateOfBirth;
public:
    Person(int id, QString n, QString s, Date dateOB, QString e, QString p);
    Person();

    int Id() const;
    QString Name() const;
    QString Surname() const;
    char Status() const;
    QString Email() const;
    QString Password() const;
    Date getDate() const;

    void Id(int i);
    void Name(QString n);
    void Surname(QString s);
    void Status(char s);
    void Email(QString e);
    void Password(QString p);
    void setDate(Date dateOB);
    Person& operator=(Person const& person);
};

#endif // PERSON_H
