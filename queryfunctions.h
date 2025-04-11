#ifndef QUERYFUNCTIONS_H
#define QUERYFUNCTIONS_H

#include <QString>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>

class queryFunctions
{
private:
    QString tableNameData, tableNameAccount, tableID, tableEmail, tablePassword, tableUserSurname, tableUserName;
public:
    queryFunctions();
    void checkTableNames(bool st);
    bool checkEmail(QString email);
    bool checkPassword(QString password);
    bool checkName(QString name);

    bool student, professor;
    void changeEmail(QString email, bool st, QString oldEmail);
    void changePassword(QString pass, bool st, QString oldPass);
    void changeName(QString pass, bool st, QString oldName);
    void changeSurname(QString pass, bool st, QString oldSurname);
    std::vector<QString> getStudentData(QString email, QString pass);
    std::vector<QString> getProfessorData(QString email, QString pass);
    void insertStudent(QString name, QString surname, QString email, QString pass, QString date, QString major, int stuYear);
    void insertProfessor(QString name, QString surname, QString email, QString pass, QString date, QString spec, QString title);
    bool checkIfInStudentDatabase(QString emailToCheck, QString passwordToCheck);
    bool checkIfInProfDatabase(QString emailToCheck, QString passwordToCheck);
    std::vector<std::vector<QString>> getStudentGrades(int id);
    void insertAssignment(QString title, QString desc, QString cC, QString begDate, QString endDate);
    std::vector<std::vector<QString>> getProfAssignments(QString cC);
    std::vector<std::vector<QString>> getStudUpcomAssignments(QString cC);
    std::vector<std::vector<QString>> getStudComplAssignments(QString cC);
};

#endif // QUERYFUNCTIONS_H
