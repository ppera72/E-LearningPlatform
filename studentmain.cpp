#include "studentmain.h"
#include "qmessagebox.h"
#include "ui_studentmain.h"
#include <QInputDialog>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>

studentMain::studentMain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentMain)
{
    ui->setupUi(this);

    connect(ui->SMChangeEmailButton, &QPushButton::clicked, this, &studentMain::on_changeEmailButton_clicked);
    connect(ui->SMChangePasswordButton, &QPushButton::clicked, this, &studentMain::on_changePasswordButton_clicked);
    connect(ui->SMChangeNameButton, &QPushButton::clicked, this, &studentMain::on_changeNameButton_clicked);
    connect(ui->SMChangeSurnameButton, &QPushButton::clicked, this, &studentMain::on_changeSurnameButton_clicked);
    connect(ui->SMViewGradesButton, &QPushButton::clicked, this, &studentMain::on_SMViewGradesButton_clicked);
    connect(ui->SMViewAccountDataButton, &QPushButton::clicked, this, &studentMain::on_SMViewAccountDataButton_clicked);
    connect(ui->SMAccountDetailsBackButton, &QPushButton::clicked, this, &studentMain::on_SMAccountDetailsBackButton_clicked);
    connect(ui->SMStartSelectedTestButton, &QPushButton::clicked, this, &studentMain::on_SMStartSelectedTestButton_clicked);
    connect(ui->SMStartSelectedAssignmentButton, &QPushButton::clicked, this, &studentMain::on_SMStartSelectedAssignmentButton_clicked);

    connect(ui->SMSTACancelButton, &QPushButton::clicked, this, &studentMain::on_SMSTACancelButton_clicked);
    connect(ui->SMSTASendAssignmentButton, &QPushButton::clicked, this, &studentMain::on_SMSTASendAssignmentButton_clicked);
    connect(ui->SMSTAAddFileButton, &QPushButton::clicked, this, &studentMain::on_SMSTAAddFileButton_clicked);
    connect(ui->SMAccountDetailsBackButton, &QPushButton::clicked, this, &studentMain::on_SMAccountDetailsBackButton_clicked);
    connect(ui->SMViewGradesButton, &QPushButton::clicked, this, &studentMain::on_SMViewGradesButton_clicked);
    connect(ui->SMViewAccountDataButton, &QPushButton::clicked, this, &studentMain::on_SMViewAccountDataButton_clicked);
    connect(ui->SMVGBackButton, &QPushButton::clicked, this, &studentMain::on_SMVGBackButton_clicked);


    connect(ui->SMLogOutButton, &QPushButton::clicked, [=](){
        emit this->backLogin();
    });
}

studentMain::~studentMain()
{
    delete ui;
}

// MAIN LOGIN PAGE
void studentMain::onLogin(){
    ui->SMNameLabel->setText(currentStudent.Name());
}

void studentMain::getAssignments(){
    std::vector<std::vector<QString>> assignments = QueryFunctions.getStudUpcomAssignments(currentStudent.CourseCode());
    std::vector<std::vector<QString>> assignmentsComp = QueryFunctions.getStudComplAssignments(currentStudent.Id());
    for(auto&& assignment : assignments){
        ui->SMUpcomingAssignmentsList->addItem(assignment[1] + ", End Date: " + assignment[4]);
    }

    for(auto&& assignment : assignmentsComp){
        ui->SMCompletedTasksList->addItem(assignment[1]);
    }

}

void studentMain::on_SMViewAccountDataButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->SMADCurrentName->setText(currentStudent.Name());
    ui->SMADCurrentSurname->setText(currentStudent.Surname());
    ui->SMADCurrentEmail->setText(currentStudent.Email());
    ui->SMADCurrentPassword->setText(currentStudent.Password());
    ui->SMADCurrentDateOfBirth->setText(QString::fromStdString(currentStudent.getDate().wholeDate()));
    ui->SMADCurrentID->setText(QString::number(currentStudent.Id()));
    ui->SMADCurrentCourceCode->setText(currentStudent.CourseCode());
}

// MAIN LOGIN PAGE END

// ACCOUNT DETAILS PAGE
void studentMain::on_changeEmailButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid email!"), tr("Your new email:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeEmail(text, true, currentStudent.Email());
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changePasswordButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid password!"), tr("Your new password:"), QLineEdit::Password, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changePassword(text, true, currentStudent.Password());
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changeNameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid name!"), tr("Your new name:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeName(text, true, currentStudent.Name());
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_changeSurnameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid surname!"), tr("Your new surname:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeSurname(text, true, currentStudent.Surname());
    }
    else{
        qDebug()<<"*wrong choice buzzer*";
    }
}

void studentMain::on_SMAccountDetailsBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

// ACCOUNT DETAILS PAGE END

// SOLVE THE TEST PAGE
void studentMain::on_SMStartSelectedTestButton_clicked()
{

}

// SOLVE THE TEST PAGE END

// SEND THE ASSIGNMENT PAGE
void studentMain::on_SMStartSelectedAssignmentButton_clicked(){
    QListWidgetItem* selectedAssignment;
    QString fileForAssignment;
    // get assignment data
    if(ui->SMUpcomingAssignmentsList->selectedItems().size() == 0){
        QMessageBox::warning(this, "Sending assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
    }
    else if(ui->SMUpcomingAssignmentsList->selectedItems().size() > 1){
        QMessageBox::warning(this, "Sending assignment", "You can only select one assignment at a time!", QMessageBox::Ok);
    }
    else{
        // check if nothing is selected
        selectedAssignment = ui->SMUpcomingAssignmentsList->currentItem();
        if(selectedAssignment->text().isEmpty()){
            QMessageBox::warning(this, "Starting Assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
        }
        else{


            // display data
            ui->stackedWidget->setCurrentIndex(10);
            //ui->SMSTATitleLabel->setText(QString::fromStdString(helpAssignmentVec[1]));
            //ui->SMSTADescriptionLabel->setText(QString::fromStdString(helpAssignmentVec[2]));
        }
    }
}

void studentMain::on_SMSTACancelButton_clicked()
{

}

void studentMain::on_SMSTASendAssignmentButton_clicked()
{

}

void studentMain::on_SMSTAAddFileButton_clicked()
{

}
// SEND THE ASSIGNMENT PAGE END

// VIEW THE GRADES PAGE
void studentMain::on_SMViewGradesButton_clicked(){
    /*ui->stackedWidget->setCurrentIndex(13); // change to grades page
    ui->SMVGTable->setRowCount(UserData.studentGrades.size()); // set row count as count of grades
    ui->SMVGTable->setColumnCount(4);

    QStringList headers = {"Student ID", "Title of Assignment/Test", "Grade", "Description"}; // headers
    ui->SMVGTable->setHorizontalHeaderLabels(headers); // set headers

    writeToStudGradesTable(); //
    ui->SMVGTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);*/
    std::vector<std::vector<QString>> grades = QueryFunctions.getStudentGrades(currentStudent.Id());
    ui->SMVGTable->setRowCount(grades.size());
    ui->SMVGTable->setColumnCount(5);
    QStringList headers = {"Student ID", "Professor ID",  "Assignment ID", "Test ID", "Grade"}; // headers // maybe add desc
    ui->SMVGTable->setHorizontalHeaderLabels(headers);

    for(unsigned long long i = 0; i < grades.size(); i++){
        for(unsigned long long j = 0; j < 5 && j < grades[i].size();++j){
            ui->SMVGTable->setItem(i, j, new QTableWidgetItem(grades[i][j]));
        }
    }

    ui->SMVGTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stackedWidget->setCurrentIndex(4);
}

void studentMain::on_SMVGBackButton_clicked()
{

}
// VIEW THE GRADES PAGE END
