#pragma once

#include "student.h"
#include "queryfunctions.h"
#include <QDialog>

namespace Ui {
class studentMain;
}

class studentMain : public QDialog
{
    Q_OBJECT

public:
    explicit studentMain(QWidget *parent = nullptr);
    ~studentMain();

    queryFunctions QueryFunctions;
    void onLogin();
    void getAssignments();
    void getTests();
    Student currentStudent;
signals:
    void backLogin();

private:
    Ui::studentMain *ui;
    void on_changeEmailButton_clicked();
    void on_changePasswordButton_clicked();
    void on_changeNameButton_clicked();
    void on_changeSurnameButton_clicked();
    void on_SMViewGradesButton_clicked();
    void on_SMViewAccountDataButton_clicked();
    void on_SMAccountDetailsBackButton_clicked();


    void on_SMVGBackButton_clicked();

    void on_SMStartSelectedTestButton_clicked();
    void on_SMStartSelectedAssignmentButton_clicked();

    void on_SMSTACancelButton_clicked();
    void on_SMSTASendAssignmentButton_clicked();
    void on_SMSTAAddFileButton_clicked();

};
