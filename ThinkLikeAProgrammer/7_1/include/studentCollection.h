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
    /*������� ��� � ������ firstStudentPolicy � �������� ���������
    �� �������, ������� ����������� bool � ��������� ��� ��������� */
public:
    studentCollection();
    studentCollection(const studentCollection &original); // ���������� �����������
    studentCollection& operator=(const studentCollection &rhs);
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    void setFirstStudentPolicy(firstStudentPolicy f);
    studentRecord firstStudent();
    void printColl();
    friend scIterator;  // ��� ������� � �������� ������
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
