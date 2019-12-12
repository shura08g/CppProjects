/*
    Задача: отслеживание неизвестного количества студенческих карточек
    В этой задаче вы должны будете реализовать функции для создания и управления сту-
денческими карточками. Такая карточка содержит числовые данные: номер студента и
балл. Нужно реализоватьдве функции:
    addRecord - Функция получает указатель на коллекцию студенческих карточек,
номер студента и балл и добавляет новую запись с этими данными в коллекцию.
    averageRecord - Функция получает указатель на коллекцию студенческих карто-
чек и возвращает среднее значение баллов студентов этой коллекции в формате double.
    Коллекция может быть любого размера. Предполагается, что функция addRecord бу-
дет использоваться часто, следовательно, она должна быть реализована наиболее
эффективным способом.
*/

#include <iostream>

using namespace std;

struct listNode{
    int studentID;
    int grade;
    listNode *next;
};
typedef listNode *studentCollection;

void addRecord(studentCollection &sc, int id, int grade){
    //&sc - потому что изменяем ссылку на голову списка
    listNode *newNode = new listNode;
    newNode->studentID = id;
    newNode->grade = grade;
    if (sc == NULL){
        sc = newNode;
        sc->next = NULL;
    }
    else{
        newNode->next = sc;
        sc = newNode;
    }
}

void addRecordBack(studentCollection &sc, int id, int grade){
    //&sc - потому что изменяем ссылку на голову списка если список пустой
    studentCollection scTemp = sc;
    listNode *newNode = new listNode;
    newNode->studentID = id;
    newNode->grade = grade;
    newNode->next = NULL;
    if (sc == NULL){
        sc = newNode;
    }
    else{
        while (sc->next) sc = sc->next;
        sc->next = newNode;
        sc = scTemp;
    }
}

double averageRecord(studentCollection sc){
    double sum = 0;
    int count = 0;
    if (sc == NULL) return 0;
    while (sc != NULL){
        sum += sc->grade;
        count++;
        sc = sc->next;
    }
    return sum/count;
}

void printList(studentCollection sc){
    if (sc == NULL){
        cout << "List empty" << endl;
        return;
    }
    while (sc != NULL){
        cout << "ID: " << sc->studentID << "; grade: " << sc->grade << ";" << endl;
        sc = sc->next;
    }
}

int main()
{
    studentCollection sc;
    listNode *node1 = new listNode;
    node1->studentID = 1001;
    node1->grade = 78;
    listNode *node2 = new listNode;
    node2->studentID = 1002;
    node2->grade = 93;
    listNode *node3 = new listNode;
    node3->studentID = 1003;
    node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    /* чтобы избежать возможной проблемы перекрестных ссылок, мы присваиваем
    значение NULL каждому из индивидуальных указателей на узлы*/

    printList(sc);

    double avg = averageRecord(sc);
    cout << "Average grade: " << avg << endl << endl;

    // Более эфективно вставлять в начало списка чем в конец
    addRecord(sc, 1004, 82);
    addRecord(sc, 1005, 87);
    addRecord(sc, 1006, 93);
    printList(sc);

    avg = averageRecord(sc);
    cout << "Average grade: " << avg << endl << endl;

    addRecordBack(sc, 1007, 91);
    addRecordBack(sc, 1008, 99);
    addRecordBack(sc, 1009, 89);
    addRecordBack(sc, 1010, 79);
    printList(sc);

    avg = averageRecord(sc);
    cout << "Average grade: " << avg << endl << endl;

    cout << "test empty list:" << endl;
    studentCollection scEmpty = NULL;// = new listNode;
    printList(scEmpty);
    avg = averageRecord(scEmpty);
    cout << "Average grade: " << avg << endl << endl;
    addRecordBack(scEmpty, 1113, 98);
    addRecord(scEmpty, 1110, 100);
    addRecord(scEmpty, 1111, 90);
    addRecordBack(scEmpty, 1112, 89);

    printList(scEmpty);

    return 0;
}
