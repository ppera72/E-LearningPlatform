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
float studentMain::assignAGrade(int corrAns, int numOfQ){
    int procent = (float)corrAns / numOfQ * 100;
    float retValue;
    switch(procent){
    case 0 ... 50:
        retValue = 2.0;
        break;
    case 51 ... 60:
        retValue = 3.0;
        break;
    case 61 ... 70:
        retValue = 3.5;
        break;
    case 71 ... 80:
        retValue = 4.0;
        break;
    case 81 ... 90:
        retValue = 4.5;
        break;
    case 91 ... 100:
        retValue = 5.0;
        break;
    default:
        retValue = 2.0;
        break;
    }
    return retValue;
}

void studentMain::onLogin(){
    ui->SMNameLabel->setText(currentStudent.Name());
    ui->SMUpcomingAssignmentsList->clear();
    ui->SMUpcomingTestsList->clear();
    ui->SMCompletedTasksList->clear();
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
        ui->SMUpcomingTestsList->addItem(test[0] + " | " + test[1] + " | From:" + test[5]);
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
    if (ok && !text.isEmpty() && !QueryFunctions.checkIfInStudentDatabase(text, currentStudent.Password()) && !QueryFunctions.checkIfInProfDatabase(text, currentStudent.Password())){
        QueryFunctions.changeEmail(text, true, currentStudent.Email(), currentStudent.Id());
        currentStudent.Email(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void studentMain::on_changePasswordButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid password!"), tr("Your new password:"), QLineEdit::Password, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changePassword(text, true, currentStudent.Password(), currentStudent.Id());
        currentStudent.Password(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void studentMain::on_changeNameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid name!"), tr("Your new name:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeName(text, true, currentStudent.Name(), currentStudent.Id());
        currentStudent.Name(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void studentMain::on_changeSurnameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid surname!"), tr("Your new surname:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeSurname(text, true, currentStudent.Surname(), currentStudent.Id());
        currentStudent.Surname(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void studentMain::on_SMAccountDetailsBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}

// ACCOUNT DETAILS PAGE END

// SOLVE THE TEST PAGE
QListWidgetItem* testQList;
QString selectedTest;
void studentMain::on_SMStartSelectedTestButton_clicked(){
    int testQuestionNumber = 0, correctAnswersScore = 0;
    int testID, profID;
    testQList = ui->SMUpcomingTestsList->currentItem();
    if(testQList->text().isEmpty()){
        QMessageBox::warning(this, "Starting Test", "No test has been selected!\nPlease select test!", QMessageBox::Ok);
    }
    else{
        //get data
        selectedTest = testQList->text().section("|", 1, 1).trimmed();
        profID = testQList->text().section("From:", 1).trimmed().toInt();
        testID = testQList->text().split("|").first().trimmed().toInt();
        std::vector<std::vector<QString>> testQuestions = QueryFunctions.getTestQuestions(testID);

        //solving
        ui->stackedWidget->setCurrentIndex(2);
        ui->SMSTTAllAnswersLabel->setText(QString::number(testQuestions.size()));

        for(auto&& test : testQuestions){
            ui->SMSTTCorrectAnswersLabel->setText(QString::number(testQuestionNumber + 1));

            QEventLoop loop;
            std::vector<QString> answers = {test[2], test[3], test[4], test[5]};
            ui->SMSTTQuestionLabel->setText(test[1]);

            QRadioButton* ansButtons[] = {ui->SMSTTAnswer1Button, ui->SMSTTAnswer2Button, ui->SMSTTAnswer3Button, ui->SMSTTAnswer4Button};
            std::srand(std::time(nullptr));
            std::random_shuffle(answers.begin(), answers.end());  // shuffle answers
            for (int i = 0; i < 4; ++i) {
                ansButtons[i]->setText(answers[i]);
            }

            QObject::connect(ui->SMSTTNextQuestionButton, &QPushButton::clicked, &loop, &QEventLoop::quit);  // wait for nextQuestionButton
            loop.exec();

            for(int i = 0; i < 4; i++){  // check answer
                if(ansButtons[i]->isChecked()){
                    if(ansButtons[i]->text() == test[2]){
                        correctAnswersScore += 1;
                        break;
                    }
                }
                ansButtons[i]->setChecked(false);
            }
            testQuestionNumber += 1;
        }
        float grade = assignAGrade(correctAnswersScore, testQuestions.size());

        QString messBoxMessage = "You've completed this test\nYou've scored: " + QString::number(correctAnswersScore) + " / " + QString::number(testQuestions.size()) + " and got: \n" + QString::number(grade);
        QMessageBox::information(this, "Test Completed!", messBoxMessage, QMessageBox::Ok);

        // insert grade
        QueryFunctions.insertGrade(currentStudent.Id(), profID, 0, testID, grade, "");

        // insert to completedTests
        QueryFunctions.insertCompletedTest(currentStudent.Id(), testID);

        ui->SMUpcomingAssignmentsList->clear();
        ui->SMUpcomingTestsList->clear();
        ui->SMCompletedTasksList->clear();
        getAssignments();
        getTests();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

// SOLVE THE TEST PAGE END

// SEND THE ASSIGNMENT PAGE
QString assignmentFile;
QListWidgetItem* selectedAssQList;
QString selectedAss;
int assID;
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
        selectedAssQList = ui->SMUpcomingAssignmentsList->currentItem();
        if(selectedAssQList->text().isEmpty()){
            QMessageBox::warning(this, "Starting Assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
        }
        else{
            // display data
            selectedAss = selectedAssQList->text().section("|", 1, 1).trimmed();
            assID = selectedAssQList->text().split("|").first().trimmed().toInt();
            std::vector<QString> assignment = QueryFunctions.getAssignment(assID, selectedAss);
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
    QueryFunctions.sendAssignment(assID, currentStudent.Id(), assignmentFile, currentStudent.CourseCode());
    //qDebug()<<"post sendAssignment";
    QMessageBox::information(this, "Sending Assignment", "Assignemnt Send Successfully!", QMessageBox::Ok);
    ui->SMSTAFileList->clear();

    // update assignmentsCompleted and assignmentsUpcoming
    ui->SMUpcomingAssignmentsList->clear();
    ui->SMUpcomingTestsList->clear();
    ui->SMCompletedTasksList->clear();
    getAssignments();
    getTests();

    ui->stackedWidget->setCurrentIndex(0);
    //delete selectedAssignmentQList;
}

void studentMain::on_SMSTAAddFileButton_clicked(){
    QString filter = "Text File(*.txt)";
    QString fileName = QFileDialog::getOpenFileName(this, "Select assignment file:", "C:\\", filter);

    QList<QListWidgetItem *> list = ui->SMSTAFileList->findItems(fileName, Qt::MatchExactly);  // find all files with fileName name
    if(list.size() == 0){
        ui->SMSTAFileList->addItem(fileName);
        assignmentFile = fileName;
    }
    else{
        QMessageBox::warning(this, "Adding file error!", "File already in list!", QMessageBox::Ok);
    }
}
// SEND THE ASSIGNMENT PAGE END

// VIEW THE GRADES PAGE
void studentMain::on_SMViewGradesButton_clicked(){
    std::vector<std::vector<QString>> grades = QueryFunctions.getStudentGrades(currentStudent.Id());
    ui->SMVGTable->setRowCount(grades.size());
    ui->SMVGTable->setColumnCount(6);
    QStringList headers = {"Student ID", "Professor ID",  "Assignment ID", "Test ID", "Grade", "Comment"}; // headers // maybe add desc
    ui->SMVGTable->setHorizontalHeaderLabels(headers);

    for(unsigned long long i = 0; i < grades.size(); i++){
        for(unsigned long long j = 0; j < 6 && j < grades[i].size();++j){
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
