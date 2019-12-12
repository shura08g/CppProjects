/*
Шаблон стратегия/политика
Задача:  стараста
 в каждом классе школы назначается староста («первый ученик»),
 который отвечает за поддержание порядка в классе в отсутствие учителя.
 Первоначально это звание присваивалось ученику с наивысшим уровнем
 успеваемости, однако теперь некоторые преподаватели считают, что староста
 должен определяться по старшинству, то есть по наименьшему
 идентификационному номеру ученика, поскольку они назначаются
 последовательно. Другая часть преподавателей считает традицию избрания
 старосты смехотворной и намеревается протестовать против нее, просто
 выбрав ученика, имя которого идет первым по алфавиту в ведомости
 успеваемости класса. Ноша задача — изменить класс коллекции учеников,
 добавив методдля извлечения из этой коллекции старосты, при этом учитывая
 критерии отбора различных групп учителей.
*/

/*
Шаблон iterator (поведенчиский шаблон)
Задача: эффективный обход
 В проекте программы будет использоваться ваш класс studentCollection.
 Клиентский код нуждается в возможности обхода всех учеников в коллекции.
 Очевидно, что для обеспечения сокрытия информации клиентскому коду не
 может быть предоставлен прямой доступ к списку, однако эффективность
 обходов — непременное условие.
*/
#include <iostream>
#include "studentCollection.h"
#include <string.h> // strcmp
#include "scIterator.h"
#include <cstdlib> // qsort

void test1();
void test2_strategy();
void test3_iterator();
void test4_sort();

//typedef bool (* firstStudentPolicy)(studentRecord r1, studentRecord r2);
/*создает тип с именем firstStudentPolicy в качестве указателя
на функцию, которая возврашеает bool и принимает два параметра */

//создаем три функции политики:
bool higherGrade(studentRecord r1, studentRecord r2){
    return r1.grade() > r2.grade();
}

bool lowerStudentNumber(studentRecord r1, studentRecord r2){
    return r1.studentID() < r2.studentID();
}

bool nameComesFirst(studentRecord r1, studentRecord r2){
    //return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
    //std::cout << r1.name().compare(r2.name()) << '\n';
    return r1.name().compare(r2.name()) < 0;
}

int main()
{
    std::cout << "TEST #1" << '\n';
    std::cout << "-------" << '\n';
    test1();
    std::cout << "-------" << '\n';
    std::cout << "TEST #2" << '\n';
    std::cout << "-------" << '\n';
    test2_strategy();
    std::cout << "-------" << '\n';
    std::cout << "TEST #3" << '\n';
    std::cout << "-------" << '\n';
    test3_iterator();
    std::cout << "-------" << '\n';
    std::cout << "TEST #4" << '\n';
    std::cout << "-------" << '\n';
    test4_sort();
    return 0;
}

void test1(){
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    std::cout << "TEST ADD" << '\n';
    std::cout << "--------" << '\n';
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.printColl();
    std::cout << "--------" << '\n';
    std::cout << "CREATE S2 FROM S" << '\n';
    studentCollection s2(s);
    std::cout << "PRINT S2" << '\n';
    std::cout << "--------" << '\n';
    s2.printColl();
    std::cout << "--------" << '\n';
    std::cout << "TEST REMOVE FROM S2" << '\n';
    std::cout << "--------" << '\n';
    s2.removeRecord(2938);
    s2.printColl();
    std::cout << "--------" << '\n';
    std::cout << "PRINT S" << '\n';
    std::cout << "--------" << '\n';
    s.printColl();
}

studentCollection createCollection(){
    studentCollection s;
    studentRecord stu3(85, 3333, "Bucky");
    studentRecord stu2(99, 2222, "Den");
    studentRecord stu1(98, 1111, "Mary");
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    return s;
}

void test2_strategy(){
    studentCollection sc = createCollection();
    sc.printColl();
    std::cout << "-------------" << '\n';
    std::cout << "Higher grade:" << '\n';
    sc.setFirstStudentPolicy(higherGrade);
    std::cout << sc.firstStudent().name() << '\n';
    std::cout << "---------" << '\n';
    std::cout << "Lower ID:" << '\n';
    sc.setFirstStudentPolicy(lowerStudentNumber);
    std::cout << sc.firstStudent().name() << '\n';
    std::cout << "-----------" << '\n';
    std::cout << "Name first:" << '\n';
    sc.setFirstStudentPolicy(nameComesFirst);
    std::cout << sc.firstStudent().name() << '\n';
}

void test3_iterator(){
    studentCollection sc = createCollection();
    scIterator iter;
    int gradeTotal = 0;
    int numRecords = 0;
    iter = sc.firstItemIter();
    //iter = sc.firstItemIterator();
    while (!iter.pastEnd()){
        numRecords++;
        gradeTotal += iter.student().grade();
        iter.advance();
    }
    double average = (double)gradeTotal / numRecords;
    std::cout << "Average grade = " << average << '\n';
}

void sortRecordMerge(studentRecord *sra, int arraySize){
    int start = 0;
    int end = arraySize - 1;
    for (int i = start + 1; i <= end; ++i){
        for (int j = i; j > start && sra[j - 1].grade() > sra[j].grade(); j--){
            studentRecord temp = sra[j - 1];
            sra[j - 1] = sra[j];
            sra[j] = temp;
        }
    }
}

void sortWhithMinusOne(studentRecord *sra, int arraySize){
    int start = 0;
    int end = arraySize - 1;
    for (int i = start + 1; i <= end; ++i){
        if (sra[i].grade() != -1){
            int rightswap = i;
            for (int leftswap = i - 1;
                 leftswap >= start
                 && (sra[leftswap].grade() > sra[rightswap].grade()
                 || sra[leftswap].grade() == -1);
                 --leftswap){
                if (sra[leftswap].grade() != -1){
                    studentRecord temp = sra[leftswap];
                    sra[leftswap] = sra[rightswap];
                    sra[rightswap] = temp;
                    rightswap = leftswap;
                }
            }
        }
    }
}

int compareStudentRecord(const void *voidA, const void *voidB){
    studentRecord *recordA = (studentRecord *)voidA;
    studentRecord *recordB = (studentRecord *)voidB;
    return recordA->grade() - recordB->grade();
}

void test4_sort(){
    int arraySize = 5;
    studentRecord stu1(98, 1111, "Mary");
    studentRecord stu2(74, 2222, "Den");
    studentRecord stu3(85, 3333, "Bucky");
    studentRecord stu4(-1, 0, "Dummy");
    studentRecord stu5(56, 4444, "Benny");
    studentRecord srArr[] = {stu1, stu2, stu3, stu4, stu5};
    for (int i = 0; i < arraySize; ++i){
        std::cout << srArr[i].studentID() << " " << srArr[i].name() << " " << srArr[i].grade() << '\n';
    }
    std::cout << '\n' << "Sort exclude -1" << '\n';
    std::cout << "---------------" << '\n';
    sortWhithMinusOne(srArr, arraySize);
    for (int i = 0; i < arraySize; ++i){
        std::cout << srArr[i].studentID() << " " << srArr[i].name() << " " << srArr[i].grade() << '\n';
    }
  /*  std::cout << '\n' << "Sort exclude -1 qsort" << '\n';
    std::cout << "---------------" << '\n';
    studentRecord *sortArray = new studentRecord[5];
    int sortArrayCount = 0;
    for (int i = 0; i < arraySize; ++i){
        if (srArr[i].grade() != -1){
            sortArray[sortArrayCount] = srArr[i];
            ++sortArrayCount;
        }
    }
    qsort(sortArray, sortArrayCount, sizeof(studentRecord), compareStudentRecord);
    sortArrayCount = 0;
    for (int i = 0; i < arraySize; ++i){
        if (srArr[i].grade() != -1){
            srArr[i] = sortArray[sortArrayCount];
            ++sortArrayCount;
        }
    }
    for (int i = 0; i < arraySize; ++i){
        std::cout << srArr[i].studentID() << " " << srArr[i].name() << " " << srArr[i].grade() << '\n';
    }*/

    /*std::cout << '\n' << "Sort qsort" << '\n';
    std::cout << "---------------" << '\n';
    qsort(srArr, arraySize, sizeof(studentRecord), compareStudentRecord);
    for (int i = 0; i < arraySize; ++i){
        std::cout << srArr[i].studentID() << " " << srArr[i].name() << " " << srArr[i].grade() << '\n';
    }*/
    std::cout << '\n' << "Sort" << '\n';
    std::cout << "---------------" << '\n';
    sortRecordMerge(srArr, arraySize);
    for (int i = 0; i < arraySize; ++i){
        std::cout << srArr[i].studentID() << " " << srArr[i].name() << " " << srArr[i].grade() << '\n';
    }
}
