#ifndef PROFESSORMAIN_H
#define PROFESSORMAIN_H

#include <QDialog>
#include "professor.h"
#include "queryfunctions.h"

namespace Ui {
class professorMain;
}

class professorMain : public QDialog
{
    Q_OBJECT

public:
    explicit professorMain(QWidget *parent = nullptr);
    ~professorMain();

    Professor currentProfessor;
    void onLogin();
    void getAssignments();
    queryFunctions QueryFunctions;
signals:
    void backLogin();

private:
    Ui::professorMain *ui;


    void on_PMChangeEmailButton_clicked();
    void on_PMChangePasswordButton_clicked();
    void on_PMChangeNameButton_clicked();
    void on_PMChangeSurnameButton_clicked();
    void on_PMViewAccountDataButton_clicked();
    void on_PMAccountDetailsBackButton_clicked();

    void on_PMAddNewAssignment_clicked();
    void on_PMAddNewTest_clicked();

    void on_AAAddButton_clicked();
    void on_AACancelButton_clicked();

    void on_ATAddQuestionsButton_clicked();
    void on_ATAddTestButton_clicked();
    void on_ATCancelButton_clicked();
    void on_ATAQAddQuestionsButton_clicked();
    void on_ATAQConfirmQuestionsButton_clicked();
    void on_ATAQCancelButton_clicked();

    void on_PMGradeSelectedAssignmentButton_clicked();
    void on_PMGTACancelButton_clicked();
    void on_PMGTAViewSelectedFileButton_clicked();
    void on_PMGTAGradeTheAssignmentButton_clicked();
    void on_PMGTAVTFBackButton_clicked();
};

#endif // PROFESSORMAIN_H
