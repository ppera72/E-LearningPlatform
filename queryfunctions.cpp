#include "queryfunctions.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QtSql/QSqlDatabase>

queryFunctions::queryFunctions() {}

bool queryFunctions::checkEmail(QString email){
    static QRegularExpression regex("^[a-zA-Z.0-9]+@([a-zA-Z]+.)+[a-zA-Z0-9]{2,4}$"); // characters/numbers @ 2-4*(characters/numbers with dots between)
    if(regex.match(email).hasMatch())
        return true;
    return false;
}

bool queryFunctions::checkPassword(QString password){
    static QRegularExpression regex("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");  // min. 8 characters, 1 uppercase, 1 lowercase, 1 digit, 1 special character
    if(regex.match(password).hasMatch())
        return true;
    return false;
}

bool queryFunctions::checkName(QString name){
    static QRegularExpression regex("^[a-zA-ZśàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžæŚÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð ,.'-]+$");
    if(regex.match(name).hasMatch())
        return true;
    return false;
}

void queryFunctions::checkTableNames(bool st){
    if(st){
        tableNameData = "studentLoginData";
        tableNameAccount = "studentData";
        tableID = "id_stud";
        tableEmail = "studentEmail";
        tablePassword = "studentPassword";
        tableUserName = "studentName";
        tableUserSurname = "studentSurname";
    }
    else{
        tableNameData = "professorLoginData";
        tableNameAccount = "professorData";
        tableID = "id_prof";
        tableEmail = "professorEmail";
        tablePassword = "professorPassword";
        tableUserName = "professorName";
        tableUserSurname = "professorSurname";
    }
}

void queryFunctions::changeName(QString name, bool st, QString oldName){

}

void queryFunctions::changeSurname(QString surname, bool st, QString oldSurname){

}

void queryFunctions::changeEmail(QString email, bool st, QString oldEmail){
    bool ok = checkEmail(email);
    QString EMAIL = oldEmail;
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameData + " SET " + tableEmail + "  = :newEmail WHERE " + tableEmail + " = :oldEmail");
        query.bindValue(":newEmail", email);
        query.bindValue(":oldEmail", oldEmail);
        if (query.exec()) {
            qDebug() << "Email updated successfully!";
        } else {
            qDebug() << "Error updating email:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Email changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Email is incorect!\nTry again!");
        msgWarning.exec();
    }
}
void queryFunctions::changePassword(QString pass, bool st, QString oldPass){
    bool ok = checkEmail(pass);
    qDebug()<<ok;
    checkTableNames(st);
    if(ok){
        QSqlQuery query;
        query.prepare("UPDATE " + tableNameData + " SET " + tableEmail + "  = :newEmail WHERE " + tableEmail + " = :oldEmail");
        query.bindValue(":newEmail", pass);
        query.bindValue(":oldEmail", oldPass);
        if (query.exec()) {
            qDebug() << "Email updated successfully!";
        } else {
            qDebug() << "Error updating email:" << query.lastError().text();
        }
        QMessageBox msgInformation;
        msgInformation.setText("Email changed successfully!");
        msgInformation.exec();
    }
    else{
        QMessageBox msgWarning;
        msgWarning.setText("Email is incorect!\nTry again!");
        msgWarning.exec();
    }
}

std::vector<QString> queryFunctions::getStudentData(QString email, QString pass)
{
    std::vector<QString> vec;
    QSqlQuery query;
    query.prepare("SELECT *, (SELECT abbreviation FROM major WHERE id_major = allStudentData.id_major) FROM allStudentData WHERE studentEmail = :email AND studentPassword = :pass");
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        vec.push_back(query.value(0).toString()); // id
        vec.push_back(query.value(1).toString()); // email
        vec.push_back(query.value(2).toString()); // password
        vec.push_back(query.value(3).toString()); // name
        vec.push_back(query.value(4).toString()); // surname
        vec.push_back(query.value(5).toString()); // dateOfBirth
        vec.push_back(query.value(7).toString()); // studiesYear
        vec.push_back(query.value(8).toString()); // courceCode
    }
    return vec;
}

std::vector<QString> queryFunctions::getProfessorData(QString email, QString pass)
{
    std::vector<QString> vec;
    QSqlQuery query;
    query.prepare("SELECT *, (SELECT abbreviation FROM major WHERE id_major = allProfessorData.id_major), (SELECT titlename FROM professorTitle WHERE id_title = allProfessorData.id_title) FROM allProfessorData WHERE professorEmail = :email AND professorPassword = :pass");
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        vec.push_back(query.value(0).toString()); // id
        vec.push_back(query.value(1).toString()); // email
        vec.push_back(query.value(2).toString()); // password
        vec.push_back(query.value(3).toString()); // name
        vec.push_back(query.value(4).toString()); // surname
        vec.push_back(query.value(5).toString()); // dateOfBirth
        vec.push_back(query.value(8).toString()); // sciSpec
        vec.push_back(query.value(9).toString()); // title
    }
    return vec;
}

void queryFunctions::insertStudent(QString name, QString surname, QString email, QString pass, QString date, QString major, int stuYear){
    QSqlQuery loginDataQuery, accountQuery;
    // qDebug()<<nameRegisterInput<<";"<<surnameRegisterInput<<";"<<emailRegisterInput<<";"<<passwordRegisterInput;
    loginDataQuery.prepare("INSERT INTO studentLoginData (studentEmail, studentPassword) VALUES (:email, :password)");
    loginDataQuery.bindValue(":email", email);
    loginDataQuery.bindValue(":password", pass);
    bool resData = loginDataQuery.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << loginDataQuery.lastError().text();
        // messagebox?
    }
    loginDataQuery.clear();

    loginDataQuery.prepare("SELECT id_stud FROM studentLoginData WHERE studentEmail = :email AND studentPassword = :password");
    loginDataQuery.bindValue(":email", email);
    loginDataQuery.bindValue(":password", pass);
    bool ans = loginDataQuery.exec();
    if (!ans) {
        qDebug() << "SQL ERROR: " << loginDataQuery.lastError().text();
        // messagebox?
    }
    int studentID;
    while(loginDataQuery.next()){
        studentID = loginDataQuery.value(0).toInt();
    }

    loginDataQuery.clear();

    accountQuery.prepare("INSERT INTO studentData (id_stud, studentName, studentSurname, dateOfBirth, id_major, studiesYear) VALUES (:id, :name, :surname, :date, (SELECT id_major FROM major WHERE abbreviation = :cc), :year)");
    accountQuery.bindValue(":id", studentID);
    accountQuery.bindValue(":name", name);
    accountQuery.bindValue(":surname", surname);
    accountQuery.bindValue(":date", date);
    accountQuery.bindValue(":cc", major);
    accountQuery.bindValue(":year", stuYear);
    bool resAcc = accountQuery.exec();
    if (!resAcc) {
        qDebug() << "SQL ERROR: " << accountQuery.lastError().text();
    }
    accountQuery.clear();
}

void queryFunctions::insertProfessor(QString name, QString surname, QString email, QString pass, QString date, QString spec, QString title){
    QSqlQuery loginDataQuery, accountQuery;
    loginDataQuery.prepare("INSERT INTO professorLoginData (professorEmail, professorPassword) VALUES (:email, :pass)");
    loginDataQuery.bindValue(":email", email);
    loginDataQuery.bindValue(":pass", pass);
    bool resData = loginDataQuery.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << loginDataQuery.lastError().text();
    }
    loginDataQuery.clear();

    loginDataQuery.prepare("SELECT id_prof FROM professorLoginData WHERE professorEmail = :email AND professorPassword = :password");
    loginDataQuery.bindValue(":email", email);
    loginDataQuery.bindValue(":password", pass);
    bool ans = loginDataQuery.exec();
    if (!ans) {
        qDebug() << "SQL ERROR: " << loginDataQuery.lastError().text();
        // messagebox?
    }
    int profID;
    while(loginDataQuery.next()){
        profID = loginDataQuery.value(0).toInt();
    }

    loginDataQuery.clear();

    accountQuery.prepare("INSERT INTO professorData (id_prof, professorName, professorSurname, dateOfBirth, id_major, id_title) VALUES (:id, :name, :surname, :date, (SELECT id_major FROM major WHERE abbreviation = :sci), (SELECT id_title FROM professorTitle WHERE titlename = :ti))");
    accountQuery.bindValue(":id", profID);
    accountQuery.bindValue(":name", name);
    accountQuery.bindValue(":surname", surname);
    accountQuery.bindValue(":date", date);
    accountQuery.bindValue(":sci", spec);
    accountQuery.bindValue(":ti", title);
    bool resAcc = accountQuery.exec();
    if(!resAcc){
        qDebug() << "SQL ERROR: " << accountQuery.lastError().text();
    }
    accountQuery.clear();
}

bool queryFunctions::checkIfInStudentDatabase(QString emailToCheck, QString passwordToCheck){
    QSqlQuery loginQuery;
    QString email, password;
    loginQuery.prepare("SELECT * FROM studentLoginData WHERE studentEmail = :email AND studentPassword = :pass");
    loginQuery.bindValue(":email", emailToCheck);
    loginQuery.bindValue(":pass", passwordToCheck);
    bool resData = loginQuery.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << loginQuery.lastError().text();
    }

    while(loginQuery.next()){
        email = loginQuery.value(1).toString();
        password = loginQuery.value(2).toString();
    }
    if(!email.isEmpty() && !password.isEmpty()){
        return true;
    }
    return false;
}

bool queryFunctions::checkIfInProfDatabase(QString emailToCheck, QString passwordToCheck){
    QSqlQuery loginQuery;
    QString email, password;
    loginQuery.prepare("SELECT * FROM professorLoginData WHERE professorEmail = :email AND professorPassword = :pass");
    loginQuery.bindValue(":email", emailToCheck);
    loginQuery.bindValue(":pass", passwordToCheck);

    bool resData = loginQuery.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << loginQuery.lastError().text();
    }

    while(loginQuery.next()){
        email = loginQuery.value(1).toString();
        password = loginQuery.value(2).toString();
    }
    if(!email.isEmpty() && !password.isEmpty()){
        return true;
    }
    return false;
}

std::vector<std::vector<QString>> queryFunctions::getStudentGrades(int id){
    std::vector<std::vector<QString>> vec;
    QSqlQuery query;
    query.prepare("SELECT * FROM studentGrades WHERE id_stud = :id");
    query.bindValue(":id", id);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        std::vector<QString> innerVec;
        innerVec.push_back(query.value(0).toString()); //id_stud
        innerVec.push_back(query.value(1).toString()); //id_prof
        innerVec.push_back(query.value(2).toString()); //id_assignment
        innerVec.push_back(query.value(3).toString()); //id_test
        innerVec.push_back(query.value(4).toString()); //grade
        vec.push_back(innerVec);
    }
    return vec;
}

void queryFunctions::insertAssignment(QString title, QString desc, QString cC, QString begDate, QString endDate){
    QSqlQuery query;
    query.prepare("INSERT INTO assignments (assignmentTitle, assignmentDesc, assignmentBeginDate, assignmentEndDate, id_major, filename, isGraded) VALUES (:title, :desc, :begDate, :endDate, (SELECT id_major FROM major WHERE abbreviation = :cc), NULL, false)");
    query.bindValue(":title", title);
    query.bindValue(":desc", desc);
    query.bindValue(":begDate", begDate);
    query.bindValue(":endDate", endDate);
    query.bindValue(":cc", cC);

    bool res = query.exec();
    //qDebug()<<query.executedQuery();
    //qDebug()<<query.lastQuery();
    if(!res){
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }
    query.clear();
}

std::vector<std::vector<QString>> queryFunctions::getProfAssignments(QString cC){
    std::vector<std::vector<QString>> vec;
    QSqlQuery query;
    query.prepare("SELECT * FROM assignments WHERE id_major = (SELECT id_major FROM major WHERE abbreviation = :cc) AND isGraded = 'false' AND filename IS NOT NULL");
    query.bindValue(":cc", cC);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        std::vector<QString> innerVec;
        innerVec.push_back(query.value(0).toString()); //id_assignment
        innerVec.push_back(query.value(1).toString()); //title
        innerVec.push_back(query.value(2).toString()); //desc
        innerVec.push_back(query.value(3).toString()); //beginDate
        innerVec.push_back(query.value(4).toString()); //endDate
        innerVec.push_back(query.value(5).toString()); //id_major
        innerVec.push_back(query.value(6).toString()); //filename
        innerVec.push_back(query.value(7).toString()); //isGraded
        vec.push_back(innerVec);
    }
    return vec;
}

std::vector<std::vector<QString> > queryFunctions::getStudUpcomAssignments(QString cC){
    std::vector<std::vector<QString>> vec;
    QSqlQuery query;
    query.prepare("SELECT * FROM assignments WHERE id_major = (SELECT id_major FROM major WHERE abbreviation = :cc) AND filename IS NULL");
    query.bindValue(":cc", cC);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        std::vector<QString> innerVec;
        innerVec.push_back(query.value(0).toString()); //id_assignment
        innerVec.push_back(query.value(1).toString()); //title
        innerVec.push_back(query.value(2).toString()); //desc
        innerVec.push_back(query.value(3).toString()); //beginDate
        innerVec.push_back(query.value(4).toString()); //endDate
        innerVec.push_back(query.value(5).toString()); //id_major
        innerVec.push_back(query.value(6).toString()); //filename
        innerVec.push_back(query.value(7).toString()); //isGraded
        vec.push_back(innerVec);
    }

    return vec;
}

std::vector<std::vector<QString> > queryFunctions::getStudComplAssignments(QString cC){
    std::vector<std::vector<QString>> vec;
    QSqlQuery query;
    query.prepare("SELECT * FROM assignments WHERE id_major = (SELECT id_major FROM major WHERE abbreviation = :cc) AND filename IS NOT NULL");
    query.bindValue(":cc", cC);
    bool resData = query.exec();
    if (!resData) {
        qDebug() << "SQL ERROR: " << query.lastError().text();
    }

    while(query.next()){
        std::vector<QString> innerVec;
        innerVec.push_back(query.value(0).toString()); //id_assignment
        innerVec.push_back(query.value(1).toString()); //title
        innerVec.push_back(query.value(2).toString()); //desc
        innerVec.push_back(query.value(3).toString()); //beginDate
        innerVec.push_back(query.value(4).toString()); //endDate
        innerVec.push_back(query.value(5).toString()); //id_major
        innerVec.push_back(query.value(6).toString()); //filename
        innerVec.push_back(query.value(7).toString()); //isGraded
        vec.push_back(innerVec);
    }

    return vec;
}
