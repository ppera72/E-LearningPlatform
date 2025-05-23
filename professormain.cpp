#include "professormain.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "ui_professormain.h"
#include <QDebug>
#include <QInputDialog>

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

    connect(ui->PMChangeEmailButton, &QPushButton::clicked, this, &professorMain::on_PMChangeEmailButton_clicked);
    connect(ui->PMChangePasswordButton, &QPushButton::clicked, this, &professorMain::on_PMChangePasswordButton_clicked);
    connect(ui->PMChangeNameButton, &QPushButton::clicked, this, &professorMain::on_PMChangeNameButton_clicked);
    connect(ui->PMChangeSurnameButton, &QPushButton::clicked, this, &professorMain::on_PMChangeSurnameButton_clicked);

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
    ui->PMAssignmentsToGradeList->clear();
}

void professorMain::getAssignments(){
    std::vector<std::vector<QString>> assignments = QueryFunctions.getProfAssignments(currentProfessor.SciSpec());
    for(auto&& assignment : assignments){
        ui->PMAssignmentsToGradeList->addItem(assignment[0] + " | " + assignment[1] + " | " + assignment[6]);
    }
}

// MAIN PAGE
void professorMain::on_PMViewAccountDataButton_clicked(){
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

void professorMain::on_PMAddNewAssignment_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void professorMain::on_PMAddNewTest_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}


QString fileForAssignment;
QListWidgetItem* selectedAssignmentQList;
QString selectedAssignment;
int assignmentID;
void professorMain::on_PMGradeSelectedAssignmentButton_clicked(){
    // get assignment data
    if(ui->PMAssignmentsToGradeList->selectedItems().size() == 0){
        QMessageBox::warning(this, "Grading assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
    }
    else if(ui->PMAssignmentsToGradeList->selectedItems().size() > 1){
        QMessageBox::warning(this, "Grading assignment", "You can only grade one assignment at a time!", QMessageBox::Ok);
    }
    else{
        selectedAssignmentQList = ui->PMAssignmentsToGradeList->currentItem();
        if(selectedAssignmentQList->text().isEmpty()){
            QMessageBox::warning(this, "Grading Assignment", "No assignment has been selected!\nPlease select assignment!", QMessageBox::Ok);
        }
        else{
            // display data
            selectedAssignment = selectedAssignmentQList->text();
            assignmentID = selectedAssignment.split("|").first().trimmed().toInt();
            int senderID = selectedAssignment.split("|").last().trimmed().toInt(); // trim selectedAssignment
            selectedAssignment = selectedAssignment.section("|", 1, 1).trimmed();
            std::vector<QString> assignment = QueryFunctions.getAssignment(assignmentID, selectedAssignment);
            std::vector<QString> senderData = QueryFunctions.getSenderData(senderID);
            std::vector<QString> completedAssignment = QueryFunctions.getCompletedAssignment(assignmentID, senderID);

            ui->PMGTAListOfFiles->addItem(completedAssignment[3]);
            ui->PMGTATitleDataLabel->setText(assignment[1]);
            ui->PMGTASenderDataLabel->setText(senderData[1] + " " + senderData[2] + ", ID: " + senderData[0]);

            ui->stackedWidget->setCurrentIndex(5);
        }
    }
}

// MAIN PAGE END

// ACCOUNT DETAILS PAGE
void professorMain::on_PMChangeEmailButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid email!"), tr("Your new email:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty() && !QueryFunctions.checkIfInStudentDatabase(text, currentProfessor.Password()) && !QueryFunctions.checkIfInProfDatabase(text, currentProfessor.Password())){
        QueryFunctions.changeEmail(text, false, currentProfessor.Email(), currentProfessor.Id());
        currentProfessor.Email(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void professorMain::on_PMChangePasswordButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid password!"), tr("Your new password:"), QLineEdit::Password, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changePassword(text, false, currentProfessor.Password(), currentProfessor.Id());
        currentProfessor.Password(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void professorMain::on_PMChangeNameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid name!"), tr("Your new name:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeName(text, false, currentProfessor.Name(), currentProfessor.Id());
        currentProfessor.Name(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void professorMain::on_PMChangeSurnameButton_clicked(){
    bool ok;
    QString text = QInputDialog::getText(this, tr("Input a valid surname!"), tr("Your new surname:"), QLineEdit::Normal, QString(), &ok);
    if (ok && !text.isEmpty()){
        QueryFunctions.changeSurname(text, false, currentProfessor.Surname(), currentProfessor.Id());
        currentProfessor.Surname(text);
    }
    else{
        QMessageBox::warning(this, "Account Change", "Error in changing data!", QMessageBox::Ok);
    }
}

void professorMain::on_PMAccountDetailsBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
// ACCOUNT DETAILS PAGE END

// ADD NEW TEST PAGE
QList<std::vector<QString>> ATQuestions, ATAQQuestions;

void professorMain::on_ATAddQuestionsButton_clicked(){
    ui->stackedWidget->setCurrentIndex(3);

}

void professorMain::on_ATAddTestButton_clicked(){
    QString ATTitle, ATBeginDate, ATEndDate, ATCourceCode;
    ATTitle = ui->ATTitleInput->text();
    Date BeginDate = ui->ATBeginDateDateEdit->text().toStdString();
    Date EndDate = ui->ATEndDateDateEdit->text().toStdString();
    QString begDate = ui->ATBeginDateDateEdit->text();
    QString endDate = ui->ATEndDateDateEdit->text();
    QDate bDate = QDate::fromString(begDate, "dd-MM-yyyy");
    QDate eDate = QDate::fromString(endDate, "dd-MM-yyyy");
    ATBeginDate = bDate.toString("yyyy-MM-dd");
    ATEndDate = eDate.toString("yyyy-MM-dd");
    ATCourceCode = ui->ATCourceCodeCombo->currentText().right(6).mid(1, 4);

    if(ATTitle.isEmpty()){
        QMessageBox::warning(this, "Adding Test", "Title of test is empty!\nPlease fill it!", QMessageBox::Ok);
    }

    else if(EndDate.compareDates(BeginDate) == 1 || EndDate.compareDates(BeginDate) == 0){
        QMessageBox::warning(this, "Adding Test", "End Date of test cannot be earlier than Begin Date!", QMessageBox::Ok);
    }

    else if(ATQuestions.empty()){
        QMessageBox::warning(this, "Adding Test", "Test does not contain any questions!\nPlease add them using ""Add Questions"" button!", QMessageBox::Ok);
    }

    if(!ATQuestions.empty() && !ATTitle.isEmpty() && EndDate.compareDates(BeginDate) == -1){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Adding Test", "Are you sure you want to add test?", QMessageBox::Yes|QMessageBox::No);
        if(reply == QMessageBox::Yes){

            // add to Test + Test Questions
            QueryFunctions.insertTest(ATTitle, ATBeginDate, ATEndDate, ATCourceCode, currentProfessor.Id(), ATQuestions);

            ui->ATTitleInput->clear();
            ui->ATQuestionsList->clear();
            ui->ATAQQuestionsList->clear();
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
}

void professorMain::on_ATCancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Test", "Are you sure you want to cancel adding test?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->ATTitleInput->clear();
        ui->ATQuestionsList->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void professorMain::on_ATAQAddQuestionsButton_clicked(){
    ATQuestions.clear();
    int ATAQNumberOfQuestions = ui->ATAQNumberOfQuestionsSpinBox->value();
    if(ATAQNumberOfQuestions <= 0){
        QMessageBox::warning(this, "Adding Questions", "Number of questions cannot be less than 1!\nPlease choose another number!", QMessageBox::Ok);
    }
    else{
        for(int i = 0; i < ATAQNumberOfQuestions; i++){
            bool okQ, okCA, okWA1, okWA2, okWA3;
            std::vector<QString> questionAnswers;
            QString quesNum = tr("Question %1").arg(i + 1);
            QString question = QInputDialog::getText(this, tr("Question"), quesNum, QLineEdit::Normal,"Question", &okQ);
            if (okQ && !question.isEmpty())
            {
                questionAnswers.push_back(question);
                ui->ATAQQuestionsList->addItem(question);
            }

            QString correctAnswer = QInputDialog::getText(this, tr("Correct Answer"),tr("Answer: "), QLineEdit::Normal,"Correct Answer", &okCA);
            if (okCA && !correctAnswer.isEmpty())
                questionAnswers.push_back(correctAnswer);

            QString wrongAnswer1 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 1:"), QLineEdit::Normal,"Wrong Answer", &okWA1);
            if (okWA1 && !wrongAnswer1.isEmpty())
                questionAnswers.push_back(wrongAnswer1);

            QString wrongAnswer2 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 2:"), QLineEdit::Normal,"Wrong Answer", &okWA2);
            if (okWA2 && !wrongAnswer2.isEmpty())
                questionAnswers.push_back(wrongAnswer2);

            QString wrongAnswer3 = QInputDialog::getText(this, tr("Wrong Answer"),tr("Wrong Answer 3:"), QLineEdit::Normal,"Wrong Answer", &okWA3);
            if (okWA3 && !wrongAnswer3.isEmpty())
                questionAnswers.push_back(wrongAnswer3);

            ATAQQuestions.append(questionAnswers);
        }
    }
}

void professorMain::on_ATAQConfirmQuestionsButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Add Test Questions", "Are you sure you want to add questions to test?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        for(auto&& q : ATAQQuestions){
            ATQuestions.append(q);
            ui->ATQuestionsList->addItem(q[0]);
        }
        ATAQQuestions.clear();
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void professorMain::on_ATAQCancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Test Questions", "Are you sure you want to cancel adding questions to test?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->ATAQNumberOfQuestionsSpinBox->setValue(0);
        ui->ATAQQuestionsList->clear();
        ui->stackedWidget->setCurrentIndex(2);
    }
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
    QString begDate = ui->AABeginDateDateEdit->text();
    QString endDate = ui->AAEndDateDateEdit->text();
    QDate bDate = QDate::fromString(begDate, "dd-MM-yyyy");
    QDate eDate = QDate::fromString(endDate, "dd-MM-yyyy");
    AABeginDate = bDate.toString("yyyy-MM-dd");
    AAEndDate = eDate.toString("yyyy-MM-dd");

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
void professorMain::on_PMGTACancelButton_clicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel Grading Assignment", "Are you sure you want to cancel grading the assignemnt?\nAll the data will be lost!", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        ui->stackedWidget->setCurrentIndex(0);

    }
}

void professorMain::on_PMGTAViewSelectedFileButton_clicked(){
    QListWidgetItem* selectedFile = ui->PMGTAListOfFiles->currentItem();
    if(ui->PMGTAListOfFiles->selectedItems().size() == 0){
        QMessageBox::warning(this, "Selecting File", "No file has been selected!", QMessageBox::Ok);
    }
    else if(ui->PMGTAListOfFiles->selectedItems().size() > 1){
        QMessageBox::warning(this, "Selecting Files", "Only one file can be selected at a certain time!", QMessageBox::Ok);
    }
    else{
        ui->stackedWidget->setCurrentIndex(6);
        QString selFileStr = selectedFile->text();
        QFile file(selFileStr);

        if (!file.exists()) {
            QMessageBox::warning(this, "File Error", "Selected file does not exist!", QMessageBox::Ok);
            return;
        }

        if(!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this, "File Error", "File is empty!", QMessageBox::Ok);
            return;
        }
        QTextStream in(&file);
        QString text = in.readAll();
        ui->plainTextEdit->setPlainText(text);

        file.close();
    }
}

void professorMain::on_PMGTAGradeTheAssignmentButton_clicked(){
    QString grade = ui->PMGTAGradeCombo->currentText();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Grading Assignment", "You're grading this assignment with grade: " + grade + ".\nAre you sure?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        selectedAssignment = selectedAssignmentQList->text();
        assignmentID = selectedAssignment.split("|").first().trimmed().toInt();
        int senderID = selectedAssignment.split("|").last().trimmed().toInt();
        selectedAssignment = selectedAssignment.section("|", 1, 1).trimmed();
        std::vector<QString> assignment = QueryFunctions.getAssignment(assignmentID, selectedAssignment);
        std::vector<QString> completedAssignment = QueryFunctions.getCompletedAssignment(assignmentID, senderID);
        int gradedAssignmentID = completedAssignment[0].toInt();

        // send to StudentGrades
        QString comment = ui->PMGTAFeedbackComment->text();
        QueryFunctions.insertGrade(senderID, currentProfessor.Id(), assignment[0].toInt(), 0, grade.toFloat(), comment);


        // update completedAssignments
        QueryFunctions.updateCompletedAssignment(gradedAssignmentID);
        ui->PMAssignmentsToGradeList->clear();
        getAssignments();
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void professorMain::on_PMGTAVTFBackButton_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
}

// GRADE THE ASSIGNMENT PAGE END

