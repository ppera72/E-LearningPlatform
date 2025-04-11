#include "professormain.h"
#include "qmessagebox.h"
#include "ui_professormain.h"
#include <QDebug>

professorMain::professorMain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::professorMain)
{
    ui->setupUi(this);

    connect(ui->PMAddNewAssignmentButton, &QPushButton::clicked, this, &professorMain::on_PMAddNewAssignment_clicked);
    connect(ui->PMAddNewTestButton, &QPushButton::clicked, this, &professorMain::on_PMAddNewTest_clicked);
    connect(ui->AAAddButton, &QPushButton::clicked, this, &professorMain::on_AAAddButton_clicked);
    connect(ui->AACancelButton, &QPushButton::clicked, this, &professorMain::on_AACancelButton_clicked);

    connect(ui->ATAddQuestionsButton, &QPushButton::clicked, this, &professorMain::on_ATAddQuestionsButton_clicked);
    connect(ui->ATAddTestButton, &QPushButton::clicked, this, &professorMain::on_ATAddTestButton_clicked);
    connect(ui->ATCancelButton, &QPushButton::clicked, this, &professorMain::on_ATCancelButton_clicked);
    connect(ui->ATAQAddQuestionsButton, &QPushButton::clicked, this, &professorMain::on_ATAQAddQuestionsButton_clicked);
    connect(ui->ATAQConfirmQuestionsButton, &QPushButton::clicked, this, &professorMain::on_ATAQConfirmQuestionsButton_clicked);
    connect(ui->ATAQCancelButton, &QPushButton::clicked, this, &professorMain::on_ATAQCancelButton_clicked);

    connect(ui->PMGradeSelectedAssignmentButton, &QPushButton::clicked, this, &professorMain::on_PMGradeSelectedAssignmentButton_clicked);
    connect(ui->PMGTACancelButton, &QPushButton::clicked, this, &professorMain::on_PMGTACancelButton_clicked);
    connect(ui->PMGTAViewSelectedFileButton, &QPushButton::clicked, this, &professorMain::on_PMGTAViewSelectedFileButton_clicked);
    connect(ui->PMGTAGradeTheAssignmentButton, &QPushButton::clicked, this, &professorMain::on_PMGTAGradeTheAssignmentButton_clicked);
    connect(ui->PMGTAVTFBackButton, &QPushButton::clicked, this, &professorMain::on_PMGTAVTFBackButton_clicked);
    connect(ui->PMAccountDetailsBackButton, &QPushButton::clicked, this, &professorMain::on_PMAccountDetailsBackButton_clicked);
    connect(ui->PMViewAccountDataButton, &QPushButton::clicked, this, &professorMain::on_PMViewAccountDataButton_clicked);

    connect(ui->PMLogOutButton, &QPushButton::clicked, [=](){
        emit this->backLogin();
    });

}

professorMain::~professorMain()
{
    delete ui;
}

void professorMain::onLogin(){
    ui->PMNameLabel->setText(currentProfessor.Name());
    ui->AABeginDateDateEdit->setDate(QDate::currentDate());
    ui->AAEndDateDateEdit->setDate(QDate::currentDate());
    ui->ATBeginDateDateEdit->setDate(QDate::currentDate());
    ui->ATEndDateDateEdit->setDate(QDate::currentDate());

}

void professorMain::getAssignments(){
    std::vector<std::vector<QString>> assignments = QueryFunctions.getProfAssignments(currentProfessor.SciSpec());
    for(auto&& assignment : assignments){
        ui->PMAssignmentsToGradeList->addItem(assignment[1]);
    }
}

// MAIN PAGE


void professorMain::on_PMViewAccountDataButton_clicked()
{
    ui->PMADCurrentID->setText(QString::number(currentProfessor.Id()));
    ui->PMADCurrentName->setText(currentProfessor.Name());
    ui->PMADCurrentSurname->setText(currentProfessor.Surname());
    ui->PMADCurrentDateOfBirth->setText(QString::fromStdString(currentProfessor.getDate().wholeDate()));
    ui->PMADCurrentEmail->setText(currentProfessor.Email());
    ui->PMADCurrentPassword->setText(currentProfessor.Password());
    ui->PMADCurrentTitle->setText(currentProfessor.Title());
    ui->PMADCurrentSciSpec->setText(currentProfessor.SciSpec());

    ui->stackedWidget->setCurrentIndex(1);
}

void professorMain::on_PMAddNewAssignment_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void professorMain::on_PMAddNewTest_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void professorMain::on_PMGradeSelectedAssignmentButton_clicked()
{

}

// MAIN PAGE END

// ACCOUNT DETAILS PAGE
void professorMain::on_PMChangeEmailButton_clicked()
{

}

void professorMain::on_PMChangePasswordButton_clicked()
{

}

void professorMain::on_PMChangeNameButton_clicked()
{

}

void professorMain::on_PMChangeSurnameButton_clicked()
{

}

void professorMain::on_PMAccountDetailsBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// ACCOUNT DETAILS PAGE END

// ADD NEW TEST PAGE
void professorMain::on_ATAddQuestionsButton_clicked()
{

}

void professorMain::on_ATAddTestButton_clicked()
{

}

void professorMain::on_ATCancelButton_clicked()
{

}

void professorMain::on_ATAQAddQuestionsButton_clicked()
{

}

void professorMain::on_ATAQConfirmQuestionsButton_clicked()
{

}

void professorMain::on_ATAQCancelButton_clicked()
{

}


// ADD NEW TEST PAGE END

// ADD NEW ASSIGNMENT PAGE
void professorMain::on_AAAddButton_clicked(){
    QString AATitle, AADesc, AACourceCode, AABeginDate, AAEndDate;
    AATitle = ui->AATitleInput->text();
    AADesc = ui->AADesctiptionInput->text();
    AACourceCode = ui->AACourceCodeCombo->currentText().right(6).mid(1, 4);
    Date BeginDate = ui->AABeginDateDateEdit->text().toStdString();
    Date EndDate = ui->AAEndDateDateEdit->text().toStdString();
    AABeginDate = ui->AABeginDateDateEdit->text();
    AAEndDate = ui->AAEndDateDateEdit->text();

    //qDebug()<<AATitle<<", "<<AADesc<<", "<<AACourceCode<<", "<<AABeginDate.wholeDate()<<", "<<AAEndDate.wholeDate();

    if(AATitle.isEmpty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }
    else if(AADesc.isEmpty()){
        QMessageBox::warning(this, "Adding Assignment", "Title of assignment is empty!\nPlease fill it!", QMessageBox::Ok);
    }

    else if(EndDate.compareDates(BeginDate) == 1 || EndDate.compareDates(BeginDate) == 0){
        QMessageBox::warning(this, "Adding Assignment", "End Date of assignment cannot be earlier than Begin Date!", QMessageBox::Ok);
    }

    if(!AATitle.isEmpty() && !AADesc.isEmpty() && EndDate.compareDates(BeginDate) == -1){
        QueryFunctions.insertAssignment(AATitle, AADesc, AACourceCode, AABeginDate, AAEndDate);
        //qDebug()<<AATitle<<", "<<AADesc<<", "<<AACourceCode<<", "<<AABeginDate<<", "<<AAEndDate;

        ui->AATitleInput->clear();
        ui->AADesctiptionInput->clear();
        QMessageBox::information(this, "Assignment Confirm", "Assignment added successfully!", QMessageBox::Ok);
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void professorMain::on_AACancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Assignment", "Are you sure you want to cancel adding assignment?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->AATitleInput->clear();
        ui->AADesctiptionInput->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
}
// ADD NEW ASSIGNMENT PAGE END

// GRADE THE ASSIGNMENT PAGE
void professorMain::on_PMGTACancelButton_clicked()
{

}

void professorMain::on_PMGTAViewSelectedFileButton_clicked()
{

}

void professorMain::on_PMGTAGradeTheAssignmentButton_clicked()
{

}

void professorMain::on_PMGTAVTFBackButton_clicked()
{

}

// GRADE THE ASSIGNMENT PAGE END

