/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_registerWindow
{
public:
    QLineEdit *nameRegisterInput;
    QLineEdit *surnameRegisterInput;
    QLineEdit *emailRegisterInput;
    QLineEdit *passwordRegisterInput;
    QComboBox *subjectRegisterCombo;
    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *emailLabel;
    QLabel *passwordLabel;
    QLabel *subjectLabel;
    QLabel *toGownoLabel;
    QLineEdit *studentDebilRegisterInput;
    QPushButton *registerButton;
    QPushButton *backToLoginButton;

    void setupUi(QDialog *registerWindow)
    {
        if (registerWindow->objectName().isEmpty())
            registerWindow->setObjectName("registerWindow");
        registerWindow->resize(800, 600);
        nameRegisterInput = new QLineEdit(registerWindow);
        nameRegisterInput->setObjectName("nameRegisterInput");
        nameRegisterInput->setGeometry(QRect(310, 170, 113, 24));
        surnameRegisterInput = new QLineEdit(registerWindow);
        surnameRegisterInput->setObjectName("surnameRegisterInput");
        surnameRegisterInput->setGeometry(QRect(310, 210, 113, 24));
        emailRegisterInput = new QLineEdit(registerWindow);
        emailRegisterInput->setObjectName("emailRegisterInput");
        emailRegisterInput->setGeometry(QRect(310, 290, 113, 24));
        passwordRegisterInput = new QLineEdit(registerWindow);
        passwordRegisterInput->setObjectName("passwordRegisterInput");
        passwordRegisterInput->setGeometry(QRect(310, 330, 113, 24));
        passwordRegisterInput->setLayoutDirection(Qt::RightToLeft);
        passwordRegisterInput->setEchoMode(QLineEdit::Password);
        subjectRegisterCombo = new QComboBox(registerWindow);
        subjectRegisterCombo->addItem(QString());
        subjectRegisterCombo->setObjectName("subjectRegisterCombo");
        subjectRegisterCombo->setGeometry(QRect(310, 390, 131, 24));
        nameLabel = new QLabel(registerWindow);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(240, 170, 61, 20));
        surnameLabel = new QLabel(registerWindow);
        surnameLabel->setObjectName("surnameLabel");
        surnameLabel->setGeometry(QRect(250, 210, 51, 20));
        emailLabel = new QLabel(registerWindow);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(260, 290, 49, 16));
        passwordLabel = new QLabel(registerWindow);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(240, 330, 51, 20));
        subjectLabel = new QLabel(registerWindow);
        subjectLabel->setObjectName("subjectLabel");
        subjectLabel->setGeometry(QRect(250, 390, 49, 16));
        toGownoLabel = new QLabel(registerWindow);
        toGownoLabel->setObjectName("toGownoLabel");
        toGownoLabel->setGeometry(QRect(28, 250, 271, 20));
        studentDebilRegisterInput = new QLineEdit(registerWindow);
        studentDebilRegisterInput->setObjectName("studentDebilRegisterInput");
        studentDebilRegisterInput->setGeometry(QRect(310, 250, 113, 24));
        registerButton = new QPushButton(registerWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(250, 480, 80, 24));
        backToLoginButton = new QPushButton(registerWindow);
        backToLoginButton->setObjectName("backToLoginButton");
        backToLoginButton->setGeometry(QRect(410, 480, 121, 24));

        retranslateUi(registerWindow);

        QMetaObject::connectSlotsByName(registerWindow);
    } // setupUi

    void retranslateUi(QDialog *registerWindow)
    {
        registerWindow->setWindowTitle(QCoreApplication::translate("registerWindow", "Dialog", nullptr));
        subjectRegisterCombo->setItemText(0, QCoreApplication::translate("registerWindow", "Computer Science", nullptr));

        nameLabel->setText(QCoreApplication::translate("registerWindow", "Full Name:", nullptr));
        surnameLabel->setText(QCoreApplication::translate("registerWindow", "Surname:", nullptr));
        emailLabel->setText(QCoreApplication::translate("registerWindow", "Email:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("registerWindow", "Password:", nullptr));
        subjectLabel->setText(QCoreApplication::translate("registerWindow", "Subject:", nullptr));
        toGownoLabel->setText(QCoreApplication::translate("registerWindow", "jaka\305\233 nazwa o to czy student debil czy wy\305\274szy status", nullptr));
        registerButton->setText(QCoreApplication::translate("registerWindow", "Register", nullptr));
        backToLoginButton->setText(QCoreApplication::translate("registerWindow", "Back to Login Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerWindow: public Ui_registerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
