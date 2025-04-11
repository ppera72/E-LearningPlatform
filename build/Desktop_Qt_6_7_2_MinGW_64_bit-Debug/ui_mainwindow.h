/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *mainPageStudent;
    QLabel *label;
    QLabel *testLabel1;
    QPushButton *testButton;
    QLabel *testLabel2;
    QLabel *studentPageLabel;
    QWidget *mainPageProfessor;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -20, 800, 600));
        stackedWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        mainPageStudent = new QWidget();
        mainPageStudent->setObjectName("mainPageStudent");
        label = new QLabel(mainPageStudent);
        label->setObjectName("label");
        label->setGeometry(QRect(280, 120, 291, 81));
        testLabel1 = new QLabel(mainPageStudent);
        testLabel1->setObjectName("testLabel1");
        testLabel1->setGeometry(QRect(250, 220, 151, 51));
        testButton = new QPushButton(mainPageStudent);
        testButton->setObjectName("testButton");
        testButton->setGeometry(QRect(260, 400, 80, 24));
        testLabel2 = new QLabel(mainPageStudent);
        testLabel2->setObjectName("testLabel2");
        testLabel2->setGeometry(QRect(250, 290, 151, 51));
        studentPageLabel = new QLabel(mainPageStudent);
        studentPageLabel->setObjectName("studentPageLabel");
        studentPageLabel->setGeometry(QRect(570, 130, 101, 16));
        stackedWidget->addWidget(mainPageStudent);
        mainPageProfessor = new QWidget();
        mainPageProfessor->setObjectName("mainPageProfessor");
        label_2 = new QLabel(mainPageProfessor);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 140, 171, 61));
        stackedWidget->addWidget(mainPageProfessor);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "MAIN WINDOW", nullptr));
        testLabel1->setText(QString());
        testButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        testLabel2->setText(QString());
        studentPageLabel->setText(QCoreApplication::translate("MainWindow", "student page", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "prof page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
