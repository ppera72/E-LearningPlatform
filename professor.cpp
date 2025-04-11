#include "professor.h"

Professor::Professor(int id, QString n, QString s, Date dateOB, QString e, QString p, QString t, QString sSp) : Person(id, n, s, dateOB, e, p), title(t), sciSpec(sSp) {
}

Professor::Professor(){
    Id(0);
    Name("");
    Surname("");
    Date Date("01.01.2000");
    Email("");
    Password("");
    Title("");
    SciSpec("");
}

QString Professor::Title()
{
    return title;
}

QString Professor::SciSpec()
{
    return sciSpec;
}

void Professor::Title(QString t){
    title = t;
}

void Professor::SciSpec(QString s){
    sciSpec = s;
}
Professor& Professor::operator=(Professor const &prof)
{
    if (this != &prof){
        Person::operator=(prof);
        title = prof.title;
        sciSpec = prof.sciSpec;
    }
    return *this;
}
