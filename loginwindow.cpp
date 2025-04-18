#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QWidget>
#include <QRadioButton>

loginWindow::loginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    StudentMain = new studentMain;
    ProfessorMain = new professorMain;

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setUserName("postgres");
    db.setPassword("admin");
    db.setDatabaseName("postgres");
    db.setHostName("localhost");
    db.open();
    QSqlQuery query;
    query.exec("USE postgres");

    //qDebug()<<"Is open" << db.isOpen();
    // qDebug()<<db.drivers();


    connect(ui->registerButton, &QPushButton::clicked, this, &loginWindow::on_registerButton_clicked);
    connect(ui->backToLoginPageButton, &QPushButton::clicked, this, &loginWindow::on_backToLoginPageButton_clicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &loginWindow::on_loginButton_clicked);
    connect(ui->registerToDatabaseButton, &QPushButton::clicked, this, &loginWindow::on_registerToDatabaseButton_clicked);
    connect(ui->passwordRegisterHelpButton, &QPushButton::clicked, this, &loginWindow::on_passwordRegisterHelpButton_clicked);
    connect(StudentMain, &studentMain::backLogin, [=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            Student st;
            StudentMain->currentStudent = st;
            StudentMain->hide();
            this->show();
        }
    });
    connect(ProfessorMain, &professorMain::backLogin, [=](){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Log Out", "Are you sure you want to log out?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){
            Professor pr;
            ProfessorMain->currentProfessor = pr;
            ProfessorMain->hide();
            this->show();
        }
    });

    ui->dateOfBirthRegisterEdit->setDate(QDate::currentDate());

}
loginWindow::~loginWindow()
{
    delete ui;
}


// LOGIN PAGE


QString emailLoginInput, passwordLoginInput;
bool studentStatus, professorStatus;

void loginWindow::on_loginButton_clicked()
{
    emailLoginInput = ui->emailLoginInput->text();
    passwordLoginInput = ui->passwordLoginInput->text();
    if (emailLoginInput.isEmpty() || passwordLoginInput.isEmpty()){
        QMessageBox::warning(this, tr("Login Verification"), tr("Provide all login details!"), QMessageBox::Ok);
    }
    else{
        if(!db.open()){
            QMessageBox::warning(this, tr("Database connection"), tr("Database is not connected!\nPlease try again later."), QMessageBox::Ok);
        }
        else{
            studentStatus = QueryFunctions.checkIfInStudentDatabase(emailLoginInput, passwordLoginInput);
            professorStatus = QueryFunctions.checkIfInProfDatabase(emailLoginInput, passwordLoginInput);
            ui->emailLoginInput->clear();
            ui->passwordLoginInput->clear();
            if(studentStatus){
                QMessageBox::information(this, tr("Login Confirmation?"), tr("Successfully logged in!"), QMessageBox::Ok);
                std::vector<QString> data = QueryFunctions.getStudentData(emailLoginInput, passwordLoginInput);
                /*for(auto&& a:data){
                    qDebug()<<a;
                }*/
                Date d(data[5].toStdString());
                Student st(data[0].toInt(), data[3], data[4], d, data[1], data[2], data[7], data[6].toInt());
                StudentMain->currentStudent = st;
                this->hide();
                StudentMain->show();
                StudentMain->onLogin();
                StudentMain->getAssignments();
                StudentMain->getTests();
                //qDebug()<<st.Id()<<", "<<st.Name()<<", "<<st.Surname();
            }
            else if(professorStatus){
                QMessageBox::information(this, tr("Login Confirmation?"), tr("Successfully logged in!"), QMessageBox::Ok);
                std::vector<QString> data = QueryFunctions.getProfessorData(emailLoginInput, passwordLoginInput);
                /*for(auto&& a:data){
                    qDebug()<<a;
                }*/
                Date d(data[5].toStdString());
                Professor pr(data[0].toInt(), data[3], data[4], d, data[1], data[2], data[7], data[6]);
                ProfessorMain->currentProfessor = pr;
                this->hide();
                ProfessorMain->show();
                ProfessorMain->onLogin();
                ProfessorMain->getAssignments();
            }
            else{
                QMessageBox::warning(this, tr("Login Confirmation?"), tr("Account not in database!\nCheck your details or register a new account!"), QMessageBox::Ok);
            }
        }
    }
}

void loginWindow::on_registerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
// LOGIN PAGE END

// REGISTER PAGE

QString nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, studentMajorRegisterInput, dateOfBirthRegisterInput, professorSpecRegisterInput, professorTitleRegisterInput; // add date of birth, different majors
bool studentRegisterRadioButton, professorRegisterRadioButton;
int studiesYearInput;

void loginWindow::on_registerToDatabaseButton_clicked()
{
    nameRegisterInput = ui->nameRegisterInput->text();
    surnameRegisterInput = ui->surnameRegisterInput->text();
    studentRegisterRadioButton = ui->studentRegisterRadioButton->isChecked();
    professorRegisterRadioButton = ui->professorRegisterRadioButton->isChecked();
    emailRegisterInput = ui->emailRegisterInput->text();
    passwordRegisterInput = ui->passwordRegisterInput->text();
    studentMajorRegisterInput = ui->studentMajorRegisterCombo->currentText().right(6).mid(1, 4); // getting code in brackets + removing brackets
    professorSpecRegisterInput = ui->professorSpecRegisterCombo->currentText().right(6).mid(1, 4); // ^
    professorTitleRegisterInput = ui->professorTitleRegisterCombo->currentText();
    dateOfBirthRegisterInput = ui->dateOfBirthRegisterEdit->text();
    studiesYearInput = ui->studentStudiesYearSpinBox->value();


    if(nameRegisterInput.isEmpty() || surnameRegisterInput.isEmpty() || emailRegisterInput.isEmpty() || passwordRegisterInput.isEmpty() || !(studentRegisterRadioButton || professorRegisterRadioButton)){
        QMessageBox::warning(this, tr("Register Verification"), tr("Provide all register details!"), QMessageBox::Ok);
    }

    if(!QueryFunctions.checkName(nameRegisterInput) || !QueryFunctions.checkName(surnameRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Name or Surname is incorect!"), QMessageBox::Ok);

    if(!QueryFunctions.checkEmail(emailRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Email is incorect!"), QMessageBox::Ok);

    if(!QueryFunctions.checkPassword(passwordRegisterInput))
        QMessageBox::warning(this, tr("Register Verification"), tr("Password is incorect!"), QMessageBox::Ok);

    if(studiesYearInput <= 0 && studentRegisterRadioButton)
        QMessageBox::warning(this, tr("Register Verification"), tr("Year of study cannot be less than 0!"), QMessageBox::Ok);

    if(studiesYearInput > 5 && studentRegisterRadioButton)
        QMessageBox::warning(this, tr("Register Verification"), tr("Year of study cannot more than 5!"), QMessageBox::Ok);

    if(QueryFunctions.checkName(nameRegisterInput) && QueryFunctions.checkName(surnameRegisterInput) && QueryFunctions.checkEmail(emailRegisterInput) && QueryFunctions.checkPassword(passwordRegisterInput) && (studentRegisterRadioButton || professorRegisterRadioButton) && (studiesYearInput > 0 && studiesYearInput <= 5)){
        if(!db.open())
            QMessageBox::warning(this, tr("Database connection"), tr("Database is not connected!\nPlease try again later."), QMessageBox::Ok);
        else{
            if(QueryFunctions.checkIfInStudentDatabase(emailRegisterInput, passwordRegisterInput) || QueryFunctions.checkIfInProfDatabase(emailRegisterInput, passwordRegisterInput)){
                QMessageBox::warning(this, tr("Register Form"), tr("Account already in database!"), QMessageBox::Ok);
            }
            else{
                if(studentRegisterRadioButton){             // add to student table
                    QueryFunctions.insertStudent(nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, dateOfBirthRegisterInput, studentMajorRegisterInput, studiesYearInput);
                }
                if(professorRegisterRadioButton){           // add to professor
                    QueryFunctions.insertProfessor(nameRegisterInput, surnameRegisterInput, emailRegisterInput, passwordRegisterInput, dateOfBirthRegisterInput, professorSpecRegisterInput, professorTitleRegisterInput);
                }
                QMessageBox::information(this, tr("Registring Account"), tr("Account Registered Successfully!"), QMessageBox::Ok);
                // clear input data:
                ui->nameRegisterInput->clear();
                ui->surnameRegisterInput->clear();
                ui->emailRegisterInput->clear();
                ui->passwordRegisterInput->clear();
                QDate date = QDate::currentDate();
                ui->dateOfBirthRegisterEdit->setDate(date);
                ui->studentStudiesYearSpinBox->setValue(0);
                ui->studentRegisterRadioButton->setChecked(false);
                ui->professorRegisterRadioButton->setChecked(false);
                ui->studentMajorRegisterCombo->setCurrentIndex(0);
                ui->professorSpecRegisterCombo->setCurrentIndex(0);
                ui->professorTitleRegisterCombo->setCurrentIndex(0);

                ui->stackedWidget->setCurrentIndex(0);
            }
        }

    }
    else{
        qDebug()<<"Error with data";
    }
}

void loginWindow::on_passwordRegisterHelpButton_clicked()
{
    QMessageBox::information(this, tr("Password Input"), tr("Password must contain:\n - minimum 8 characters\n - minimum 1 uppercase and 1 lowercase letter\n - minimum 1 digit\n - minimum 1 special charater (#?!@$%^&*-)"), QMessageBox::Ok);
}

void loginWindow::on_backToLoginPageButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Back to Login Page", "Are you sure you want to leave?\nAll details will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->nameRegisterInput->clear();
        ui->surnameRegisterInput->clear();
        ui->emailRegisterInput->clear();
        ui->passwordRegisterInput->clear();


        ui->stackedWidget->setCurrentIndex(0);
    }
}

// REGISTER PAGE END

