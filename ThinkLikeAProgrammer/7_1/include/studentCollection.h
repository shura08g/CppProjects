#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H
#include "studentRecord.h"

class scIterator;

class studentCollection{
private:
    struct studentNode{
        studentRecord studentData;
        studentNode *next;
    };
    typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2);
    /*создает тип с именем firstStudentPolicy в качестве указателя
    на функцию, которая возврашеает bool и принимает два параметра */
public:
    studentCollection();
    studentCollection(const studentCollection &original); // копирующий конструктор
    studentCollection& operator=(const studentCollection &rhs);
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    void setFirstStudentPolicy(firstStudentPolicy f);
    studentRecord firstStudent();
    void printColl();
    friend scIterator;  // для доступа к пиватным членам
    scIterator firstItemIter(); // begin() for iterator: realized in scIterator
    //studentNode* firstItemIterator(); // if scIterator doesn't work
private:
    typedef studentNode *studentList;
    studentList _listHead;
    void deleteList(studentList &listPrt);
    studentList copiedList(const studentList original);
    firstStudentPolicy _currentPolicy;
};
#endif // STUDENTCOLLECTION_H
