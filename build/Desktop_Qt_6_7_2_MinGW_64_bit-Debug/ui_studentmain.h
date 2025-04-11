/********************************************************************************
** Form generated from reading UI file 'studentmain.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMAIN_H
#define UI_STUDENTMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentMain
{
public:
    QStackedWidget *stackedWidget;
    QWidget *studentMainPage;
    QPushButton *SMLogOutButton;
    QLabel *SMWelcomeLabel;
    QLabel *SMNameLabel;
    QLabel *SMUpcomingAssignmentsLabel;
    QListWidget *SMUpcomingAssignmentsList;
    QListWidget *SMUpcomingTestsList;
    QLabel *SMUpcomingTestsLabel;
    QLabel *SMCompletedTasksLabel;
    QListWidget *SMCompletedTasksList;
    QPushButton *SMStartSelectedAssignmentButton;
    QPushButton *SMStartSelectedTestButton;
    QPushButton *SMViewAccountDataButton;
    QPushButton *SMViewGradesButton;
    QWidget *SMAccountDetailsPage;
    QPushButton *SMChangePasswordButton;
    QPushButton *SMChangeEmailButton;
    QPushButton *SMChangeSurnameButton;
    QPushButton *SMChangeNameButton;
    QPushButton *SMAccountDetailsBackButton;
    QLabel *SMADIDLabel;
    QLabel *SMADCurrentID;
    QLabel *SMADNameLabel;
    QLabel *SMADCurrentName;
    QLabel *SMADSurnameLabel;
    QLabel *SMADCurrentSurname;
    QLabel *SMADDateOfBirthLabel;
    QLabel *SMADCurrentDateOfBirth;
    QLabel *SMADEmailLabel;
    QLabel *SMADCurrentEmail;
    QLabel *SMADCourceCodeLabel;
    QLabel *SMADCurrentCourceCode;
    QLabel *SMADPasswordLabel;
    QLabel *SMADCurrentPassword;
    QWidget *SMSolveTheTestPage;
    QRadioButton *SMSTTAnswer1Button;
    QRadioButton *SMSTTAnswer2Button;
    QRadioButton *SMSTTAnswer3Button;
    QRadioButton *SMSTTAnswer4Button;
    QPushButton *SMSTTNextQuestionButton;
    QLabel *SMSTTQuestionLabel;
    QLabel *SMSTTCorrectAnswersLabel;
    QLabel *SMSTTSlashLabel;
    QLabel *SMSTTAllAnswersLabel;
    QLabel *label_3;
    QWidget *SMSendTheAssignmentPage;
    QLabel *SMSTALabel;
    QLabel *SMSTATitleLabel;
    QLabel *SMSTADescriptionLabel;
    QPushButton *SMSTAAddFileButton;
    QPushButton *SMSTASendAssignmentButton;
    QPushButton *SMSTACancelButton;
    QListWidget *SMSTAFileList;
    QWidget *SMViewGradesPage;
    QTableWidget *SMVGTable;
    QPushButton *SMVGBackButton;

    void setupUi(QDialog *studentMain)
    {
        if (studentMain->objectName().isEmpty())
            studentMain->setObjectName("studentMain");
        studentMain->resize(800, 600);
        stackedWidget = new QStackedWidget(studentMain);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 621));
        stackedWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        studentMainPage = new QWidget();
        studentMainPage->setObjectName("studentMainPage");
        SMLogOutButton = new QPushButton(studentMainPage);
        SMLogOutButton->setObjectName("SMLogOutButton");
        SMLogOutButton->setGeometry(QRect(60, 220, 80, 24));
        SMWelcomeLabel = new QLabel(studentMainPage);
        SMWelcomeLabel->setObjectName("SMWelcomeLabel");
        SMWelcomeLabel->setGeometry(QRect(90, 80, 91, 16));
        QFont font;
        font.setPointSize(14);
        SMWelcomeLabel->setFont(font);
        SMNameLabel = new QLabel(studentMainPage);
        SMNameLabel->setObjectName("SMNameLabel");
        SMNameLabel->setGeometry(QRect(190, 80, 181, 21));
        SMNameLabel->setFont(font);
        SMUpcomingAssignmentsLabel = new QLabel(studentMainPage);
        SMUpcomingAssignmentsLabel->setObjectName("SMUpcomingAssignmentsLabel");
        SMUpcomingAssignmentsLabel->setGeometry(QRect(30, 350, 181, 21));
        QFont font1;
        font1.setPointSize(12);
        SMUpcomingAssignmentsLabel->setFont(font1);
        SMUpcomingAssignmentsList = new QListWidget(studentMainPage);
        SMUpcomingAssignmentsList->setObjectName("SMUpcomingAssignmentsList");
        SMUpcomingAssignmentsList->setGeometry(QRect(30, 380, 331, 111));
        SMUpcomingTestsList = new QListWidget(studentMainPage);
        SMUpcomingTestsList->setObjectName("SMUpcomingTestsList");
        SMUpcomingTestsList->setGeometry(QRect(390, 380, 361, 111));
        SMUpcomingTestsLabel = new QLabel(studentMainPage);
        SMUpcomingTestsLabel->setObjectName("SMUpcomingTestsLabel");
        SMUpcomingTestsLabel->setGeometry(QRect(390, 350, 131, 21));
        SMUpcomingTestsLabel->setFont(font1);
        SMCompletedTasksLabel = new QLabel(studentMainPage);
        SMCompletedTasksLabel->setObjectName("SMCompletedTasksLabel");
        SMCompletedTasksLabel->setGeometry(QRect(470, 70, 221, 31));
        SMCompletedTasksLabel->setFont(font1);
        SMCompletedTasksList = new QListWidget(studentMainPage);
        SMCompletedTasksList->setObjectName("SMCompletedTasksList");
        SMCompletedTasksList->setGeometry(QRect(470, 100, 291, 141));
        SMStartSelectedAssignmentButton = new QPushButton(studentMainPage);
        SMStartSelectedAssignmentButton->setObjectName("SMStartSelectedAssignmentButton");
        SMStartSelectedAssignmentButton->setGeometry(QRect(140, 520, 171, 24));
        SMStartSelectedTestButton = new QPushButton(studentMainPage);
        SMStartSelectedTestButton->setObjectName("SMStartSelectedTestButton");
        SMStartSelectedTestButton->setGeometry(QRect(450, 520, 131, 24));
        SMViewAccountDataButton = new QPushButton(studentMainPage);
        SMViewAccountDataButton->setObjectName("SMViewAccountDataButton");
        SMViewAccountDataButton->setGeometry(QRect(60, 180, 121, 24));
        SMViewGradesButton = new QPushButton(studentMainPage);
        SMViewGradesButton->setObjectName("SMViewGradesButton");
        SMViewGradesButton->setGeometry(QRect(60, 140, 80, 24));
        stackedWidget->addWidget(studentMainPage);
        SMAccountDetailsPage = new QWidget();
        SMAccountDetailsPage->setObjectName("SMAccountDetailsPage");
        SMChangePasswordButton = new QPushButton(SMAccountDetailsPage);
        SMChangePasswordButton->setObjectName("SMChangePasswordButton");
        SMChangePasswordButton->setGeometry(QRect(620, 110, 111, 41));
        SMChangeEmailButton = new QPushButton(SMAccountDetailsPage);
        SMChangeEmailButton->setObjectName("SMChangeEmailButton");
        SMChangeEmailButton->setGeometry(QRect(500, 110, 111, 41));
        SMChangeSurnameButton = new QPushButton(SMAccountDetailsPage);
        SMChangeSurnameButton->setObjectName("SMChangeSurnameButton");
        SMChangeSurnameButton->setGeometry(QRect(620, 160, 111, 41));
        SMChangeNameButton = new QPushButton(SMAccountDetailsPage);
        SMChangeNameButton->setObjectName("SMChangeNameButton");
        SMChangeNameButton->setGeometry(QRect(500, 160, 111, 41));
        SMAccountDetailsBackButton = new QPushButton(SMAccountDetailsPage);
        SMAccountDetailsBackButton->setObjectName("SMAccountDetailsBackButton");
        SMAccountDetailsBackButton->setGeometry(QRect(580, 510, 80, 24));
        SMADIDLabel = new QLabel(SMAccountDetailsPage);
        SMADIDLabel->setObjectName("SMADIDLabel");
        SMADIDLabel->setGeometry(QRect(40, 160, 49, 16));
        SMADIDLabel->setFont(font1);
        SMADCurrentID = new QLabel(SMAccountDetailsPage);
        SMADCurrentID->setObjectName("SMADCurrentID");
        SMADCurrentID->setGeometry(QRect(140, 160, 181, 21));
        SMADCurrentID->setFont(font1);
        SMADNameLabel = new QLabel(SMAccountDetailsPage);
        SMADNameLabel->setObjectName("SMADNameLabel");
        SMADNameLabel->setGeometry(QRect(40, 200, 49, 16));
        SMADNameLabel->setFont(font1);
        SMADCurrentName = new QLabel(SMAccountDetailsPage);
        SMADCurrentName->setObjectName("SMADCurrentName");
        SMADCurrentName->setGeometry(QRect(140, 200, 241, 21));
        SMADCurrentName->setFont(font1);
        SMADSurnameLabel = new QLabel(SMAccountDetailsPage);
        SMADSurnameLabel->setObjectName("SMADSurnameLabel");
        SMADSurnameLabel->setGeometry(QRect(40, 250, 71, 16));
        SMADSurnameLabel->setFont(font1);
        SMADCurrentSurname = new QLabel(SMAccountDetailsPage);
        SMADCurrentSurname->setObjectName("SMADCurrentSurname");
        SMADCurrentSurname->setGeometry(QRect(130, 250, 251, 21));
        SMADCurrentSurname->setFont(font1);
        SMADDateOfBirthLabel = new QLabel(SMAccountDetailsPage);
        SMADDateOfBirthLabel->setObjectName("SMADDateOfBirthLabel");
        SMADDateOfBirthLabel->setGeometry(QRect(40, 300, 91, 16));
        SMADDateOfBirthLabel->setFont(font1);
        SMADCurrentDateOfBirth = new QLabel(SMAccountDetailsPage);
        SMADCurrentDateOfBirth->setObjectName("SMADCurrentDateOfBirth");
        SMADCurrentDateOfBirth->setGeometry(QRect(170, 300, 231, 21));
        SMADCurrentDateOfBirth->setFont(font1);
        SMADEmailLabel = new QLabel(SMAccountDetailsPage);
        SMADEmailLabel->setObjectName("SMADEmailLabel");
        SMADEmailLabel->setGeometry(QRect(40, 350, 49, 16));
        SMADEmailLabel->setFont(font1);
        SMADCurrentEmail = new QLabel(SMAccountDetailsPage);
        SMADCurrentEmail->setObjectName("SMADCurrentEmail");
        SMADCurrentEmail->setGeometry(QRect(140, 350, 271, 21));
        SMADCurrentEmail->setFont(font1);
        SMADCourceCodeLabel = new QLabel(SMAccountDetailsPage);
        SMADCourceCodeLabel->setObjectName("SMADCourceCodeLabel");
        SMADCourceCodeLabel->setGeometry(QRect(40, 430, 101, 16));
        SMADCourceCodeLabel->setFont(font1);
        SMADCurrentCourceCode = new QLabel(SMAccountDetailsPage);
        SMADCurrentCourceCode->setObjectName("SMADCurrentCourceCode");
        SMADCurrentCourceCode->setGeometry(QRect(170, 430, 191, 21));
        SMADCurrentCourceCode->setFont(font1);
        SMADPasswordLabel = new QLabel(SMAccountDetailsPage);
        SMADPasswordLabel->setObjectName("SMADPasswordLabel");
        SMADPasswordLabel->setGeometry(QRect(40, 390, 71, 16));
        SMADPasswordLabel->setFont(font1);
        SMADCurrentPassword = new QLabel(SMAccountDetailsPage);
        SMADCurrentPassword->setObjectName("SMADCurrentPassword");
        SMADCurrentPassword->setGeometry(QRect(150, 390, 211, 21));
        SMADCurrentPassword->setFont(font1);
        stackedWidget->addWidget(SMAccountDetailsPage);
        SMSolveTheTestPage = new QWidget();
        SMSolveTheTestPage->setObjectName("SMSolveTheTestPage");
        SMSTTAnswer1Button = new QRadioButton(SMSolveTheTestPage);
        SMSTTAnswer1Button->setObjectName("SMSTTAnswer1Button");
        SMSTTAnswer1Button->setGeometry(QRect(270, 280, 351, 22));
        SMSTTAnswer1Button->setFont(font1);
        SMSTTAnswer2Button = new QRadioButton(SMSolveTheTestPage);
        SMSTTAnswer2Button->setObjectName("SMSTTAnswer2Button");
        SMSTTAnswer2Button->setGeometry(QRect(270, 340, 461, 22));
        SMSTTAnswer2Button->setFont(font1);
        SMSTTAnswer3Button = new QRadioButton(SMSolveTheTestPage);
        SMSTTAnswer3Button->setObjectName("SMSTTAnswer3Button");
        SMSTTAnswer3Button->setGeometry(QRect(270, 390, 491, 22));
        SMSTTAnswer3Button->setFont(font1);
        SMSTTAnswer4Button = new QRadioButton(SMSolveTheTestPage);
        SMSTTAnswer4Button->setObjectName("SMSTTAnswer4Button");
        SMSTTAnswer4Button->setGeometry(QRect(270, 440, 491, 22));
        SMSTTAnswer4Button->setFont(font1);
        SMSTTNextQuestionButton = new QPushButton(SMSolveTheTestPage);
        SMSTTNextQuestionButton->setObjectName("SMSTTNextQuestionButton");
        SMSTTNextQuestionButton->setGeometry(QRect(70, 510, 141, 24));
        SMSTTQuestionLabel = new QLabel(SMSolveTheTestPage);
        SMSTTQuestionLabel->setObjectName("SMSTTQuestionLabel");
        SMSTTQuestionLabel->setGeometry(QRect(100, 170, 571, 71));
        SMSTTQuestionLabel->setFont(font);
        SMSTTQuestionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SMSTTCorrectAnswersLabel = new QLabel(SMSolveTheTestPage);
        SMSTTCorrectAnswersLabel->setObjectName("SMSTTCorrectAnswersLabel");
        SMSTTCorrectAnswersLabel->setGeometry(QRect(480, 70, 61, 31));
        SMSTTCorrectAnswersLabel->setFont(font);
        SMSTTSlashLabel = new QLabel(SMSolveTheTestPage);
        SMSTTSlashLabel->setObjectName("SMSTTSlashLabel");
        SMSTTSlashLabel->setGeometry(QRect(560, 70, 61, 31));
        SMSTTSlashLabel->setFont(font);
        SMSTTSlashLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        SMSTTAllAnswersLabel = new QLabel(SMSolveTheTestPage);
        SMSTTAllAnswersLabel->setObjectName("SMSTTAllAnswersLabel");
        SMSTTAllAnswersLabel->setGeometry(QRect(630, 70, 61, 31));
        SMSTTAllAnswersLabel->setFont(font);
        label_3 = new QLabel(SMSolveTheTestPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(700, 70, 51, 31));
        label_3->setFont(font);
        stackedWidget->addWidget(SMSolveTheTestPage);
        SMSendTheAssignmentPage = new QWidget();
        SMSendTheAssignmentPage->setObjectName("SMSendTheAssignmentPage");
        SMSTALabel = new QLabel(SMSendTheAssignmentPage);
        SMSTALabel->setObjectName("SMSTALabel");
        SMSTALabel->setGeometry(QRect(310, 60, 171, 21));
        SMSTALabel->setFont(font1);
        SMSTATitleLabel = new QLabel(SMSendTheAssignmentPage);
        SMSTATitleLabel->setObjectName("SMSTATitleLabel");
        SMSTATitleLabel->setGeometry(QRect(30, 140, 341, 21));
        SMSTATitleLabel->setFont(font1);
        SMSTATitleLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        SMSTADescriptionLabel = new QLabel(SMSendTheAssignmentPage);
        SMSTADescriptionLabel->setObjectName("SMSTADescriptionLabel");
        SMSTADescriptionLabel->setGeometry(QRect(20, 220, 391, 101));
        SMSTADescriptionLabel->setFont(font1);
        SMSTADescriptionLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        SMSTAAddFileButton = new QPushButton(SMSendTheAssignmentPage);
        SMSTAAddFileButton->setObjectName("SMSTAAddFileButton");
        SMSTAAddFileButton->setGeometry(QRect(580, 290, 80, 24));
        SMSTASendAssignmentButton = new QPushButton(SMSendTheAssignmentPage);
        SMSTASendAssignmentButton->setObjectName("SMSTASendAssignmentButton");
        SMSTASendAssignmentButton->setGeometry(QRect(140, 510, 131, 24));
        SMSTACancelButton = new QPushButton(SMSendTheAssignmentPage);
        SMSTACancelButton->setObjectName("SMSTACancelButton");
        SMSTACancelButton->setGeometry(QRect(540, 510, 80, 24));
        SMSTAFileList = new QListWidget(SMSendTheAssignmentPage);
        SMSTAFileList->setObjectName("SMSTAFileList");
        SMSTAFileList->setGeometry(QRect(490, 180, 271, 91));
        stackedWidget->addWidget(SMSendTheAssignmentPage);
        SMViewGradesPage = new QWidget();
        SMViewGradesPage->setObjectName("SMViewGradesPage");
        SMVGTable = new QTableWidget(SMViewGradesPage);
        SMVGTable->setObjectName("SMVGTable");
        SMVGTable->setGeometry(QRect(60, 100, 661, 411));
        SMVGBackButton = new QPushButton(SMViewGradesPage);
        SMVGBackButton->setObjectName("SMVGBackButton");
        SMVGBackButton->setGeometry(QRect(590, 550, 80, 24));
        stackedWidget->addWidget(SMViewGradesPage);

        retranslateUi(studentMain);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(studentMain);
    } // setupUi

    void retranslateUi(QDialog *studentMain)
    {
        studentMain->setWindowTitle(QCoreApplication::translate("studentMain", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        stackedWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        SMLogOutButton->setText(QCoreApplication::translate("studentMain", "Log Out", nullptr));
        SMWelcomeLabel->setText(QCoreApplication::translate("studentMain", "Welcome ", nullptr));
        SMNameLabel->setText(QString());
        SMUpcomingAssignmentsLabel->setText(QCoreApplication::translate("studentMain", "Upcoming Assignments:", nullptr));
        SMUpcomingTestsLabel->setText(QCoreApplication::translate("studentMain", "Upcoming Tests:", nullptr));
        SMCompletedTasksLabel->setText(QCoreApplication::translate("studentMain", "Completed Assignments/Tests:", nullptr));
        SMStartSelectedAssignmentButton->setText(QCoreApplication::translate("studentMain", "Start Seleced Assignment", nullptr));
        SMStartSelectedTestButton->setText(QCoreApplication::translate("studentMain", "Start Selected Test", nullptr));
        SMViewAccountDataButton->setText(QCoreApplication::translate("studentMain", "View Account Data", nullptr));
        SMViewGradesButton->setText(QCoreApplication::translate("studentMain", "View Grades", nullptr));
        SMChangePasswordButton->setText(QCoreApplication::translate("studentMain", "Change Password", nullptr));
        SMChangeEmailButton->setText(QCoreApplication::translate("studentMain", "Change Email", nullptr));
        SMChangeSurnameButton->setText(QCoreApplication::translate("studentMain", "Change Surname", nullptr));
        SMChangeNameButton->setText(QCoreApplication::translate("studentMain", "Change Name", nullptr));
        SMAccountDetailsBackButton->setText(QCoreApplication::translate("studentMain", "Back", nullptr));
        SMADIDLabel->setText(QCoreApplication::translate("studentMain", "ID:", nullptr));
        SMADCurrentID->setText(QString());
        SMADNameLabel->setText(QCoreApplication::translate("studentMain", "Name:", nullptr));
        SMADCurrentName->setText(QString());
        SMADSurnameLabel->setText(QCoreApplication::translate("studentMain", "Surname:", nullptr));
        SMADCurrentSurname->setText(QString());
        SMADDateOfBirthLabel->setText(QCoreApplication::translate("studentMain", "Date of Birth:", nullptr));
        SMADCurrentDateOfBirth->setText(QString());
        SMADEmailLabel->setText(QCoreApplication::translate("studentMain", "Email:", nullptr));
        SMADCurrentEmail->setText(QString());
        SMADCourceCodeLabel->setText(QCoreApplication::translate("studentMain", "Cource Code:", nullptr));
        SMADCurrentCourceCode->setText(QString());
        SMADPasswordLabel->setText(QCoreApplication::translate("studentMain", "Password:", nullptr));
        SMADCurrentPassword->setText(QString());
        SMSTTAnswer1Button->setText(QString());
        SMSTTAnswer2Button->setText(QString());
        SMSTTAnswer3Button->setText(QString());
        SMSTTAnswer4Button->setText(QString());
        SMSTTNextQuestionButton->setText(QCoreApplication::translate("studentMain", "Next Question", nullptr));
        SMSTTQuestionLabel->setText(QString());
        SMSTTCorrectAnswersLabel->setText(QString());
        SMSTTSlashLabel->setText(QCoreApplication::translate("studentMain", "/", nullptr));
        SMSTTAllAnswersLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("studentMain", "PTS.", nullptr));
        SMSTALabel->setText(QCoreApplication::translate("studentMain", "Send Assignment", nullptr));
        SMSTATitleLabel->setText(QString());
        SMSTADescriptionLabel->setText(QString());
        SMSTAAddFileButton->setText(QCoreApplication::translate("studentMain", "Add File", nullptr));
        SMSTASendAssignmentButton->setText(QCoreApplication::translate("studentMain", "Send Assignment", nullptr));
        SMSTACancelButton->setText(QCoreApplication::translate("studentMain", "Cancel", nullptr));
        SMVGBackButton->setText(QCoreApplication::translate("studentMain", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentMain: public Ui_studentMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMAIN_H
