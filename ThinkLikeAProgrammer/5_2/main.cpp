/*
Задача: отслеживание неизвестного количества записей студентов
 В этой задаче вы создадите класс с методами для хранения и манипулирования
коллекцией записей студентов. Запись студента содержит номер студента, оценку,
оба параметра целочисленные, и фамилию студента (строковая переменная).
Необходимо реализовать следующие функции:
 addRecord Этот метод принимает номер, фамилию и оценку студента и добавляет
 новую запись с этими данными в коллекцию.
 recordWlthNumber Эта функция принимает номер студента и возвращает из
коллекции запись для студента с этим номером.
 removeRecord Эта функция принимает номер студента и удаляет из коллекции
запись студента с этим номером.
 Коллекция может быть любого размера. Ожидается, что операция addRecord будет
выполняться часто, потому она должна быть реализована эффективно.

*/

#include <iostream>

using namespace std;

/* 5.1 */
class studentRecord{
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);
    int grade();
    void setGrade(int newGrade);
    int studentID();
    void setStudentID(int newID);
    string name();
    void setName(string newName);
    string letterGrade();

private:
    int _grade;
    int _studentID;
    string _name;
    bool isValidGrade(int grade);
};

bool studentRecord::isValidGrade(int grade){
    if ((grade >= 0) && (grade <= 100))
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

string studentRecord::name(){
    return _name;
}

void studentRecord::setName(string newName){
    _name = newName;
}

studentRecord::studentRecord(int newGrade, int newID, string newName){
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord(){
    setGrade(0);
    setStudentID(-1);
    setName("");
}

string studentRecord::letterGrade(){
    if (!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
}


/* 5.2 */
class studentCollection{
private:
    struct studentNode{
        studentRecord studentData;
        studentNode *next;
    };
public:
    studentCollection();
    studentCollection(const studentCollection &original); // копирующий конструктор
    ~studentCollection();
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    void printColl();
    studentCollection& operator=(const studentCollection &rhs);
private:
    typedef studentNode *studentList;
    studentList _listHead;
    void deleteList(studentList &listPrt);
    studentList copiedList(const studentList original);
};

studentCollection::studentCollection(){
    _listHead = NULL;
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

int main()
{
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
    return 0;
}
