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
    std::vector<std::vector<QString>> getStudUpcomAssignments(QString cC, int id);
    std::vector<std::vector<QString>> getStudComplAssignments(int id);
    std::vector<std::vector<QString>> getStudUpcomTests(QString cC, int id);
    std::vector<std::vector<QString>> getStudComplTests(int id);
    std::vector<QString> getAssignment(int assignmentID, QString assignmentTitle);
    void sendAssignment(int assignmentID, int studentID, QString file, QString cC);
    std::vector<QString> getSenderData(int studentID);
    std::vector<QString> getCompletedAssignment(int assignmentID, int studentID);
    void insertGrade(int studentID, int professorID, int assignmentID, int testID, int grade, QString comment);
    void updateCompletedAssignment(int complAssignmentID);
    void insertTest(QString title, QString begDate, QString endDate, QString cC, int profID, QList<std::vector<QString>>questionsAnswers);
    std::vector<std::vector<QString>> getTestQuestions(int testID);
};

#endif // QUERYFUNCTIONS_H
