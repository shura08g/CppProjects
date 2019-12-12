#include "studentCollection.h"
#include <iostream>

studentCollection::studentCollection(){
    _listHead = NULL;
    _currentPolicy = NULL;
}

studentCollection::studentCollection(const studentCollection &original){
    _listHead = copiedList(original._listHead);
}

studentCollection::~studentCollection(){
    deleteList(_listHead);
}

studentCollection& studentCollection::operator=(const studentCollection &rhs){
    if (this != &rhs){
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

void studentCollection::deleteList(studentList &listPrt){
    while (listPrt != NULL){
        studentNode *temp = listPrt;
        listPrt = listPrt->next;
        delete temp;
    }
}

studentCollection::studentList studentCollection::copiedList(const
                                             studentList original){
    if (original == NULL) return NULL;
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode *oldLoopPrt = original->next;
    studentNode *newLoopPrt = newList;
    while (oldLoopPrt != NULL){
        newLoopPrt->next = new studentNode;
        newLoopPrt = newLoopPrt->next;
        newLoopPrt->studentData = oldLoopPrt->studentData;
        oldLoopPrt = oldLoopPrt->next;
    }
    newLoopPrt->next = NULL;
    return newList;
}

void studentCollection::printColl(){
    studentNode *loopPrt = _listHead;
    while (loopPrt != NULL){
        std::cout << loopPrt->studentData.studentID() << " "
             << loopPrt->studentData.name() << " "
             << loopPrt->studentData.grade() << " "
             << loopPrt->studentData.letterGrade() << '\n';
        loopPrt = loopPrt->next;
    }
}

void studentCollection::addRecord(studentRecord newStudent){
    studentNode *newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode *loopPrt = _listHead;
    while (loopPrt != NULL && loopPrt->studentData.studentID() != idNum){
        loopPrt = loopPrt->next;
    }
    if (loopPrt == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    else{
        return loopPrt->studentData;
    }
}

void studentCollection::removeRecord(int idNum){
    studentNode *loopPrt = _listHead;
    studentNode *prevNode = NULL;
    while (loopPrt != NULL && loopPrt->studentData.studentID() != idNum){
        prevNode = loopPrt;
        loopPrt = loopPrt->next;
    }
    if (loopPrt == NULL) return;
    if (prevNode == NULL){
        _listHead = _listHead->next; // if delete first element
    }
    else{
        prevNode->next = loopPrt->next;
    }
    delete loopPrt;
}

void studentCollection::setFirstStudentPolicy(firstStudentPolicy f){
    _currentPolicy = f;
}

studentRecord studentCollection::firstStudent(){
    if (_listHead == NULL || _currentPolicy == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    studentNode *loopPrt = _listHead;
    studentRecord first = loopPrt->studentData;
    loopPrt = loopPrt->next;
    while (loopPrt != NULL){
        if (_currentPolicy(loopPrt->studentData, first)){
            first = loopPrt->studentData;
        }
        loopPrt = loopPrt->next;
    }
    return first;
}

// if scIterator doesn't work
/*studentCollection::studentNode* studentCollection::firstItemIterator(){
    return _listHead;
}*/

