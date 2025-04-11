#include "person.h"

Person::Person(int i, QString n, QString s, Date dateOB, QString e, QString p): name(n), surname(s), email(e), password(p), id(i), dateOfBirth(dateOB){}

Person::Person(){
    id = 0;
    name = "";
    surname = "";
    email = "";
    password = "";
}

int Person::Id() const
{
    return id;
}

QString Person::Name() const
{
    return name;
}

QString Person::Surname() const
{
    return surname;
}

QString Person::Email() const
{
    return email;
}

QString Person::Password() const
{
    return password;
}

Date Person::getDate() const
{
    return dateOfBirth;
}

void Person::Id(int i)
{
    id = i;
}
void Person::Name(QString n)
{
    name = n;
}

void Person::Surname(QString s)
{
    surname = s;
}


void Person::Email(QString e)
{
    email = e;
}

void Person::Password(QString p)
{
    password = p;
}

void Person::setDate(Date dateOB)
{
    dateOfBirth = dateOB;
}

Person& Person::operator=(Person const& person)
{
    if (this != &person)
    {
        id = person.id;
        name = person.name;
        surname = person.surname;
        dateOfBirth = person.dateOfBirth;
        email = person.email;
        password = person.password;
    }
    return *this;
}
