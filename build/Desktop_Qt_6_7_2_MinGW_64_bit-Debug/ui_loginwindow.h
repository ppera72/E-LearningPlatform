/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QPushButton *registerButton;
    QLabel *emailLoginLabel;
    QLabel *passwordLoginLabel;
    QLineEdit *emailLoginInput;
    QLineEdit *passwordLoginInput;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QWidget *registerWidnow;
    QLineEdit *nameRegisterInput;
    QLineEdit *surnameRegisterInput;
    QLineEdit *emailRegisterInput;
    QLineEdit *passwordRegisterInput;
    QPushButton *registerToDatabaseButton;
    QLabel *fullNameRegisterLabel;
    QLabel *surnameRegisterLabel;
    QLabel *emailRegisterLabel;
    QLabel *passwordRegisterLabel;
    QPushButton *backToLoginPageButton;
    QToolButton *passwordRegisterHelpButton;
    QRadioButton *studentRegisterRadioButton;
    QRadioButton *professorRegisterRadioButton;
    QComboBox *studentMajorRegisterCombo;
    QLabel *studentMajorRegisterLabel;
    QComboBox *professorSpecRegisterCombo;
    QComboBox *professorTitleRegisterCombo;
    QLabel *professorSpecRegisterLabel;
    QLabel *professorTitleRegisterLabel;
    QDateEdit *dateOfBirthRegisterEdit;
    QLabel *dateOfBirthRegisterLabel;
    QSpinBox *studentStudiesYearSpinBox;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName("loginWindow");
        loginWindow->resize(800, 600);
        stackedWidget = new QStackedWidget(loginWindow);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 800, 600));
        stackedWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        registerButton = new QPushButton(loginPage);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(590, 60, 80, 24));
        emailLoginLabel = new QLabel(loginPage);
        emailLoginLabel->setObjectName("emailLoginLabel");
        emailLoginLabel->setGeometry(QRect(270, 270, 49, 16));
        passwordLoginLabel = new QLabel(loginPage);
        passwordLoginLabel->setObjectName("passwordLoginLabel");
        passwordLoginLabel->setGeometry(QRect(250, 310, 61, 20));
        emailLoginInput = new QLineEdit(loginPage);
        emailLoginInput->setObjectName("emailLoginInput");
        emailLoginInput->setGeometry(QRect(330, 270, 191, 24));
        passwordLoginInput = new QLineEdit(loginPage);
        passwordLoginInput->setObjectName("passwordLoginInput");
        passwordLoginInput->setGeometry(QRect(330, 310, 191, 24));
        passwordLoginInput->setEchoMode(QLineEdit::EchoMode::Password);
        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(340, 380, 101, 41));
        exitButton = new QPushButton(loginPage);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(590, 510, 80, 24));
        stackedWidget->addWidget(loginPage);
        registerWidnow = new QWidget();
        registerWidnow->setObjectName("registerWidnow");
        nameRegisterInput = new QLineEdit(registerWidnow);
        nameRegisterInput->setObjectName("nameRegisterInput");
        nameRegisterInput->setGeometry(QRect(220, 90, 181, 24));
        surnameRegisterInput = new QLineEdit(registerWidnow);
        surnameRegisterInput->setObjectName("surnameRegisterInput");
        surnameRegisterInput->setGeometry(QRect(220, 140, 181, 24));
        emailRegisterInput = new QLineEdit(registerWidnow);
        emailRegisterInput->setObjectName("emailRegisterInput");
        emailRegisterInput->setGeometry(QRect(230, 190, 171, 24));
        passwordRegisterInput = new QLineEdit(registerWidnow);
        passwordRegisterInput->setObjectName("passwordRegisterInput");
        passwordRegisterInput->setGeometry(QRect(240, 250, 171, 24));
        passwordRegisterInput->setEchoMode(QLineEdit::EchoMode::Password);
        registerToDatabaseButton = new QPushButton(registerWidnow);
        registerToDatabaseButton->setObjectName("registerToDatabaseButton");
        registerToDatabaseButton->setGeometry(QRect(260, 500, 80, 24));
        fullNameRegisterLabel = new QLabel(registerWidnow);
        fullNameRegisterLabel->setObjectName("fullNameRegisterLabel");
        fullNameRegisterLabel->setGeometry(QRect(128, 100, 61, 20));
        surnameRegisterLabel = new QLabel(registerWidnow);
        surnameRegisterLabel->setObjectName("surnameRegisterLabel");
        surnameRegisterLabel->setGeometry(QRect(128, 150, 61, 20));
        emailRegisterLabel = new QLabel(registerWidnow);
        emailRegisterLabel->setObjectName("emailRegisterLabel");
        emailRegisterLabel->setGeometry(QRect(128, 200, 61, 20));
        passwordRegisterLabel = new QLabel(registerWidnow);
        passwordRegisterLabel->setObjectName("passwordRegisterLabel");
        passwordRegisterLabel->setGeometry(QRect(130, 260, 61, 20));
        backToLoginPageButton = new QPushButton(registerWidnow);
        backToLoginPageButton->setObjectName("backToLoginPageButton");
        backToLoginPageButton->setGeometry(QRect(420, 500, 131, 24));
        passwordRegisterHelpButton = new QToolButton(registerWidnow);
        passwordRegisterHelpButton->setObjectName("passwordRegisterHelpButton");
        passwordRegisterHelpButton->setGeometry(QRect(450, 270, 23, 23));
        studentRegisterRadioButton = new QRadioButton(registerWidnow);
        studentRegisterRadioButton->setObjectName("studentRegisterRadioButton");
        studentRegisterRadioButton->setGeometry(QRect(230, 340, 91, 22));
        professorRegisterRadioButton = new QRadioButton(registerWidnow);
        professorRegisterRadioButton->setObjectName("professorRegisterRadioButton");
        professorRegisterRadioButton->setGeometry(QRect(390, 340, 91, 22));
        studentMajorRegisterCombo = new QComboBox(registerWidnow);
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->addItem(QString());
        studentMajorRegisterCombo->setObjectName("studentMajorRegisterCombo");
        studentMajorRegisterCombo->setEnabled(true);
        studentMajorRegisterCombo->setGeometry(QRect(30, 400, 251, 24));
        studentMajorRegisterLabel = new QLabel(registerWidnow);
        studentMajorRegisterLabel->setObjectName("studentMajorRegisterLabel");
        studentMajorRegisterLabel->setEnabled(true);
        studentMajorRegisterLabel->setGeometry(QRect(50, 370, 91, 20));
        professorSpecRegisterCombo = new QComboBox(registerWidnow);
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->addItem(QString());
        professorSpecRegisterCombo->setObjectName("professorSpecRegisterCombo");
        professorSpecRegisterCombo->setEnabled(true);
        professorSpecRegisterCombo->setGeometry(QRect(320, 400, 251, 24));
        professorTitleRegisterCombo = new QComboBox(registerWidnow);
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->addItem(QString());
        professorTitleRegisterCombo->setObjectName("professorTitleRegisterCombo");
        professorTitleRegisterCombo->setGeometry(QRect(610, 400, 65, 24));
        professorSpecRegisterLabel = new QLabel(registerWidnow);
        professorSpecRegisterLabel->setObjectName("professorSpecRegisterLabel");
        professorSpecRegisterLabel->setGeometry(QRect(320, 370, 141, 16));
        professorTitleRegisterLabel = new QLabel(registerWidnow);
        professorTitleRegisterLabel->setObjectName("professorTitleRegisterLabel");
        professorTitleRegisterLabel->setGeometry(QRect(610, 370, 91, 16));
        dateOfBirthRegisterEdit = new QDateEdit(registerWidnow);
        dateOfBirthRegisterEdit->setObjectName("dateOfBirthRegisterEdit");
        dateOfBirthRegisterEdit->setGeometry(QRect(230, 300, 201, 25));
        dateOfBirthRegisterLabel = new QLabel(registerWidnow);
        dateOfBirthRegisterLabel->setObjectName("dateOfBirthRegisterLabel");
        dateOfBirthRegisterLabel->setGeometry(QRect(100, 310, 81, 16));
        studentStudiesYearSpinBox = new QSpinBox(registerWidnow);
        studentStudiesYearSpinBox->setObjectName("studentStudiesYearSpinBox");
        studentStudiesYearSpinBox->setGeometry(QRect(470, 170, 42, 25));
        stackedWidget->addWidget(registerWidnow);

        retranslateUi(loginWindow);
        QObject::connect(exitButton, &QPushButton::clicked, loginWindow, qOverload<>(&QDialog::close));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QCoreApplication::translate("loginWindow", "Dialog", nullptr));
        registerButton->setText(QCoreApplication::translate("loginWindow", "Register", nullptr));
        emailLoginLabel->setText(QCoreApplication::translate("loginWindow", "Email:", nullptr));
        passwordLoginLabel->setText(QCoreApplication::translate("loginWindow", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("loginWindow", "Login", nullptr));
        exitButton->setText(QCoreApplication::translate("loginWindow", "Exit", nullptr));
        registerToDatabaseButton->setText(QCoreApplication::translate("loginWindow", "Register", nullptr));
        fullNameRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Full Name:", nullptr));
        surnameRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Surname:", nullptr));
        emailRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Email:", nullptr));
        passwordRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Password:", nullptr));
        backToLoginPageButton->setText(QCoreApplication::translate("loginWindow", "Back to Login Page", nullptr));
        passwordRegisterHelpButton->setText(QCoreApplication::translate("loginWindow", "?", nullptr));
        studentRegisterRadioButton->setText(QCoreApplication::translate("loginWindow", "Student", nullptr));
        professorRegisterRadioButton->setText(QCoreApplication::translate("loginWindow", "Professor", nullptr));
        studentMajorRegisterCombo->setItemText(0, QCoreApplication::translate("loginWindow", "Aviation and Astronautics [AvAs]", nullptr));
        studentMajorRegisterCombo->setItemText(1, QCoreApplication::translate("loginWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        studentMajorRegisterCombo->setItemText(2, QCoreApplication::translate("loginWindow", "Chemical Technology [ChTe]", nullptr));
        studentMajorRegisterCombo->setItemText(3, QCoreApplication::translate("loginWindow", "Civil Engineering [CiEn]", nullptr));
        studentMajorRegisterCombo->setItemText(4, QCoreApplication::translate("loginWindow", "Computer Engineering [CoEn]", nullptr));
        studentMajorRegisterCombo->setItemText(5, QCoreApplication::translate("loginWindow", "Electrical Engineering [ElEn]", nullptr));
        studentMajorRegisterCombo->setItemText(6, QCoreApplication::translate("loginWindow", "Finance and Accounting [FiAc]", nullptr));
        studentMajorRegisterCombo->setItemText(7, QCoreApplication::translate("loginWindow", "Logistics [Logi]", nullptr));
        studentMajorRegisterCombo->setItemText(8, QCoreApplication::translate("loginWindow", "Modern Management [MoMa]", nullptr));

        studentMajorRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Student Major:", nullptr));
        professorSpecRegisterCombo->setItemText(0, QCoreApplication::translate("loginWindow", "Aviation and Astronautics [AvAs]", nullptr));
        professorSpecRegisterCombo->setItemText(1, QCoreApplication::translate("loginWindow", "Chemical Engineering and Technology [ChET]", nullptr));
        professorSpecRegisterCombo->setItemText(2, QCoreApplication::translate("loginWindow", "Chemical Technology [ChTe]", nullptr));
        professorSpecRegisterCombo->setItemText(3, QCoreApplication::translate("loginWindow", "Civil Engineering [CiEn]", nullptr));
        professorSpecRegisterCombo->setItemText(4, QCoreApplication::translate("loginWindow", "Computer Engineering [CoEn]", nullptr));
        professorSpecRegisterCombo->setItemText(5, QCoreApplication::translate("loginWindow", "Electrical Engineering [ElEn]", nullptr));
        professorSpecRegisterCombo->setItemText(6, QCoreApplication::translate("loginWindow", "Finance and Accounting [FiAc]", nullptr));
        professorSpecRegisterCombo->setItemText(7, QCoreApplication::translate("loginWindow", "Logistics [Logi]", nullptr));
        professorSpecRegisterCombo->setItemText(8, QCoreApplication::translate("loginWindow", "Modern Management [MoMa]", nullptr));

        professorTitleRegisterCombo->setItemText(0, QCoreApplication::translate("loginWindow", "BSc", nullptr));
        professorTitleRegisterCombo->setItemText(1, QCoreApplication::translate("loginWindow", "Eng.", nullptr));
        professorTitleRegisterCombo->setItemText(2, QCoreApplication::translate("loginWindow", "MSc", nullptr));
        professorTitleRegisterCombo->setItemText(3, QCoreApplication::translate("loginWindow", "PhD", nullptr));
        professorTitleRegisterCombo->setItemText(4, QCoreApplication::translate("loginWindow", "Prof.", nullptr));

        professorSpecRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Professor Specialization:", nullptr));
        professorTitleRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Professor Title:", nullptr));
        dateOfBirthRegisterEdit->setDisplayFormat(QCoreApplication::translate("loginWindow", "dd-MM-yyyy", nullptr));
        dateOfBirthRegisterLabel->setText(QCoreApplication::translate("loginWindow", "Date Of Birth:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
