#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include <string>

class studentRecord{
public:
    studentRecord();
    studentRecord(int newGrade, int newID, std::string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    std::string name();
    void setName(std::string newName);
    std::string letterGrade();
    //void sortRecord(studentRecord sra[], int arraySize);

private:
    int _grade;
    int _studentID;
    std::string _name;
    bool isValidGrade(int grade);
};

#endif // STUDENTRECORD_H
