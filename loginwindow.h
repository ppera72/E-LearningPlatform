#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "studentmain.h"
#include "professormain.h"
#include "queryfunctions.h"
#include "student.h"
#include "professor.h"
#include "qsqldatabase.h"
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QtCore>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QSqlError>


namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

    studentMain* StudentMain;
    professorMain* ProfessorMain;
    QSqlDatabase db;
    queryFunctions QueryFunctions;
    Student st;
    Professor pr;


private:
    Ui::loginWindow *ui;



    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_backToLoginPageButton_clicked();

    void on_registerToDatabaseButton_clicked();



    void on_passwordRegisterHelpButton_clicked();
};

#endif // LOGINWINDOW_H
