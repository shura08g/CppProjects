#include "scIterator.h"

scIterator::scIterator(){
    current = NULL;
}

scIterator::scIterator(studentCollection::studentList initial){
    current = initial;
}

void scIterator::advance(){
    if (current != NULL)
        current = current->next;
}

bool scIterator::pastEnd(){
    return current == NULL;
}

studentRecord scIterator::student(){
    if (current == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    else{
        return current->studentData;
    }
}

scIterator studentCollection::firstItemIter(){
    return scIterator(_listHead);
}
