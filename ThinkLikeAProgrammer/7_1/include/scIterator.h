#ifndef SCITERATOR_H
#define SCITERATOR_H
#include "studentCollection.h"

class scIterator
{
    public:
        scIterator();
        scIterator(studentCollection::studentList initial);
        void advance(); // ++()
        bool pastEnd(); // end()
        studentRecord student();
        //scIterator firstItemIter(); // begin() for iterator: define in studentCollection
    private:
        studentCollection::studentList current;
};

#endif // SCITERATOR_H
