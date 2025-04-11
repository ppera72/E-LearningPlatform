#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include "date.h"

class Professor: public Person
{
private:
    QString title;
    QString sciSpec;
public:
    Professor(int id, QString n, QString s, Date dateOB, QString e, QString p, QString t, QString sSp);
    Professor();

    QString Title();
    QString SciSpec();

    void Title(QString t);
    void SciSpec(QString s);
    Professor& operator=(Professor const &prof);
};

#endif // PROFESSOR_H
