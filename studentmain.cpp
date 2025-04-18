#include "studentmain.h"
#include "qmessagebox.h"
#include "ui_studentmain.h"
#include <QInputDialog>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QFileDialog>

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
    std::vector<std::vector<QString>> assignments = QueryFunctions.getStudUpcomAssignments(currentStudent.CourseCode(), currentStudent.Id());
    std::vector<std::vector<QString>> assignmentsComp = QueryFunctions.getStudComplAssignments(currentStudent.Id());
    for(auto&& assignment : assignments){
        ui->SMUpcomingAssignmentsList->addItem(assignment[0] + " | " + assignment[1]);
    }

    for(auto&& assignment : assignmentsComp){
        ui->SMCompletedTasksList->addItem(assignment[1]);
    }

}

void studentMain::getTests(){
    std::vector<std::vector<QString>> tests = QueryFunctions.getStudUpcomTests(currentStudent.CourseCode(), currentStudent.Id());
    std::vector<std::vector<QString>> testsComp = QueryFunctions.getStudComplTests(currentStudent.Id());
    for(auto&& test : tests){
        ui->SMUpcomingTestsList->addItem(test[0] + " | " + test[1]);
    }

    for(auto&& test : testsComp){
        ui->SMCompletedTasksList->addItem(test[1]);
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
void studentMain::on_SMStartSelectedTestButton_clicked(){

}

// SOLVE THE TEST PAGE END

// SEND THE ASSIGNMENT PAGE
QString fileForAssignment;
QListWidgetItem* selectedAssignmentQList;
QString selectedAssignment;
int assignmentID;
void studentMain::on_SMStartSelectedAssignmentButton_clicked(){
    // get assignment data
    if(ui->SMUpcomingAssignmentsList->selectedItems().size() == 0){
        QMessageBox::warning(this, "Sending assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
    }
    else if(ui->SMUpcomingAssignmentsList->selectedItems().size() > 1){
        QMessageBox::warning(this, "Sending assignment", "You can only select one assignment at a time!", QMessageBox::Ok);
    }
    else{
        // check if nothing is selected
        selectedAssignmentQList = ui->SMUpcomingAssignmentsList->currentItem();
        if(selectedAssignmentQList->text().isEmpty()){
            QMessageBox::warning(this, "Starting Assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
        }
        else{
            // display data
            selectedAssignment = selectedAssignmentQList->text();
            assignmentID = selectedAssignment.split("|").first().trimmed().toInt();
            std::vector<QString> assignment = QueryFunctions.getAssignment(assignmentID, selectedAssignment);
            ui->stackedWidget->setCurrentIndex(3);
            ui->SMSTATitleLabel->setText(assignment[1]);
            ui->SMSTADescriptionLabel->setText(assignment[2]);
        }
    }
}

void studentMain::on_SMSTACancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Adding Assignment", "Are you sure you want to cancel adding assignemnt?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->SMSTAFileList->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void studentMain::on_SMSTASendAssignmentButton_clicked(){
    if(ui->SMSTAFileList->count() == 0){
        QMessageBox::warning(this, "Sending assignment error!", "File list is empty!\nPlease add a file to your assignment!", QMessageBox::Ok);
    }
    //send
    QueryFunctions.sendAssignment(assignmentID, currentStudent.Id(), fileForAssignment, currentStudent.CourseCode());
    QMessageBox::information(this, "Sending Assignment", "Assignemnt Send Successfully!", QMessageBox::Ok);
    ui->SMSTAFileList->clear();

    // update assignmentsCompleted and assignmentsUpcoming
    getAssignments();

    ui->stackedWidget->setCurrentIndex(0);
    //delete selectedAssignmentQList;
}

void studentMain::on_SMSTAAddFileButton_clicked(){
    QString filter = "Text File(*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Select assignment file:", "C:\\", filter);

    QList<QListWidgetItem *> list = ui->SMSTAFileList->findItems(fileName, Qt::MatchExactly);  // find all files with fileName name
    if(list.size() == 0){
        ui->SMSTAFileList->addItem(fileName);
        fileForAssignment = fileName;
    }
    else{
        QMessageBox::warning(this, "Adding file error!", "File already in list!", QMessageBox::Ok);
    }
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

void studentMain::on_SMVGBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
// VIEW THE GRADES PAGE END
