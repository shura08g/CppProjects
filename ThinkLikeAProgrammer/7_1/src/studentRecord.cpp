#include "studentRecord.h"
#include <iostream>

bool studentRecord::isValidGrade(int grade){
    if ((grade >= -1) && (grade <= 100)) // -1 - для неправильных записей
        return true;
    else
        return false;
}

int studentRecord::grade(){
    return _grade;
}

void studentRecord::setGrade(int newGrade){
    if (isValidGrade(newGrade))
        _grade = newGrade;
}

int studentRecord::studentID(){
    return _studentID;
}

void studentRecord::setStudentID(int newID){
    if (newID >= 0)
        _studentID = newID;
}

std::string studentRecord::name(){
    return _name;
}

void studentRecord::setName(std::string newName){
    _name = newName;
}

studentRecord::studentRecord(int newGrade, int newID, std::string newName){
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord(){
    setGrade(0);
    setStudentID(-1);
    setName("");
}

std::string studentRecord::letterGrade(){
    if (!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const std::string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
}

/*void studentRecord::sortRecord(studentRecord sra[], int arraySize){
    int start = 0;
    int end = arraySize - 1;
    for (int i = start + 1; i <= end; i++){
        for (int j = i; j > start && sra[j - 1].grade() > sra[j].grade(); j--){
            studentRecord temp = sra[j - 1];
            sra[j - 1] = sra[j];
            sra[j] = temp;
        }
    }
}*/
