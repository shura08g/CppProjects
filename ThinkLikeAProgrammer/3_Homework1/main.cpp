#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <string.h> //strcmp

using namespace std;

/*
3.1. 	Вы  разочарованы  тем,  что  мы  мало  занимались  сортировкой?
Я  знаю,  как  это  исправить.  Чтобы  убедиться  в  том,  что  вы  осво¬
ились  с  функцией  qsort,  напишите  код,  в  котором  эта  функция
используется  для  сортировки  массива  студенческой  структуры
struct.  Сначала  попробуйте  сортировать  по  оценкам,  а  затем  по¬
пытайтесь  сделать  это,  используя  идентификатор  студента.

*/

struct Student{
    //string name; //qsort dont work with string;
    char name[20];
    int studentID;
    int grade;
};

int compareFunc(const void *a, const void *b){
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

int compareByGrade(const void *a, const void *b){
    const struct Student *studentA = (Student*)a;
    const struct Student *studentB = (Student*)b;
    if (studentA->grade < studentB->grade) return -1;
    if (studentA->grade > studentB->grade) return 1;
    return 0;
}

int compareByID(const void *a, const void *b){
    const struct Student *studentA = (Student*)a;
    const struct Student *studentB = (Student*)b;
    if (studentA->studentID < studentB->studentID) return -1;
    if (studentA->studentID > studentB->studentID) return 1;
    return 0;
    /*return studentA->studentID < studentB->studentID;*/
}

int compareByName(const void *a, const void *b){
    const struct Student *studentA = (Student*)a;
    const struct Student *studentB = (Student*)b;
    //return studentA->name.compare(studentB->name);
    return strcmp(studentA->name, studentB->name);

}

bool compareVecByLength(const Student &a, const Student &b){
    //return a.name.size() < b.name.size(); // for string
    /*int len_a = 0;
    int len_b = 0;
    int i = 0;
    int j = 0;
    while (a.name[i] != '\0'){
        ++len_a;
        ++i;
    }
    while (b.name[j] != '\0'){
      ++len_b;
      ++j;
    }
    return len_a < len_b;*/
    string s1 = a.name;
    string s2 = b.name;
    return s1.size() < s2.size();
}

bool compareVecByGrade(const Student &a, const Student &b){
    return a.grade < b.grade;
}

bool compareVecByID(const Student &a, const Student &b){
    return a.studentID < b.studentID;
}

bool compareVecByIDReverse(const Student &a, const Student &b){
    return a.studentID > b.studentID;
}

bool compareVecByName(const Student &a, const Student &b){
    //return a.name < b.name;  //for string
    string s1 = a.name;
    string s2 = b.name;
    return s1 < s2;
}

void sortArrayByName(Student *students, size_t len){
    bool swapped;

    do{
        swapped = false;
        for (size_t i = 0; i < len - 1; ++i){
            if (students[i].name > students[i + 1].name){
                swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    }while(swapped); // Loop again if a swap occurred on this pass
}

void sortArrayByGrade(Student *students, size_t len){
    bool swapped;

    do{
        swapped = false;
        for (size_t i = 0; i < len - 1; ++i){
            if (students[i].grade > students[i + 1].grade){
                swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    }while(swapped);
}

void sortArrayByID(Student *students, size_t len){
    bool swapped;

    do{
        swapped = false;
        for (size_t i = 0; i < len - 1; ++i){
            if (students[i].studentID > students[i + 1].studentID){
                swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    }while(swapped);
}

int length(Student *students, int size_arr){
    return size_arr/sizeof(struct Student);
}

int length_arr(Student *students){
    return *(&students + 1) - students;
}

void printArray(Student *students){
    int len = length_arr(students);
    for (int i = 0; i < len; ++i){
        cout << students[i].studentID << " " << students[i].name << " " << students[i].grade << endl;
    }
}

void printArray(struct Student *students, size_t len){
    for (size_t i = 0; i < len; ++i){
        cout << students[i].studentID << " " << students[i].name << " " << students[i].grade << endl;
    }
}

void printVector(vector<Student> students){
    int len = students.size();
    cout << "Vector of students" << endl << "-----------------" << endl;
    for (int i = 0; i < len; ++i){
        cout << students[i].studentID << " " << students[i].name << " " << students[i].grade << endl;
    }
    cout << "-----------------" << endl;
}

int main()
{
    Student arrayStudents[] = {{"Alex", 10001, 86},
                               {"John", 10002, 89},
                               {"Den", 10003, 84},
                               {"Stefania", 10004, 88},
                               {"Linda", 10005, 91},
                               {"Mike", 10006, 85},
                               {"Trevor", 10007, 89},
                               {"Sasha", 10008, 91},
                               {"Max", 10009, 84},
                               {"Den", 10010, 88}
                              };
    //const int size_arr = sizeof(arrayStudents);
    //const int count_elem = length(arrayStudents, size_arr);
    //int count_elem = length_arr(arrayStudents);
    size_t count_elem = sizeof(arrayStudents)/sizeof(struct Student);
    cout << "Size array of students: " << count_elem << endl;
    printArray(arrayStudents, count_elem);

    vector<Student> vStudent;
    for (size_t i = 0; i < count_elem; ++i){
        vStudent.push_back(arrayStudents[i]);
    }

    cout << endl << "Sorting by name myFunc:" << endl;
    sortArrayByName(arrayStudents, count_elem);
    printArray(arrayStudents, count_elem);

    cout << endl << "Sorting by grade myFunc:" << endl;
    sortArrayByGrade(arrayStudents, count_elem);
    printArray(arrayStudents, count_elem);

    cout << endl << "Sorting by ID myFunc:" << endl;
    sortArrayByID(arrayStudents, count_elem);
    printArray(arrayStudents, count_elem);

    qsort(arrayStudents, count_elem, sizeof(struct Student), compareByGrade);
    cout << endl << "Sorting by grade qsort:" << endl;
    printArray(arrayStudents, count_elem);

    qsort(arrayStudents, count_elem, sizeof(struct Student), compareByID);
    cout << endl << "Sorting by ID qsort:" << endl;
    printArray(arrayStudents, count_elem);

    qsort(arrayStudents, count_elem, sizeof(struct Student), compareByName);
    cout << endl << "Sorting by name qsort:" << endl;
    printArray(arrayStudents, count_elem);


    printVector(vStudent);

    sort(vStudent.begin(), vStudent.end(), compareVecByLength);
    cout << endl << "Sorting by name length:" << endl;
    printVector(vStudent);

    sort(vStudent.begin(), vStudent.end(), compareVecByGrade);
    cout << endl << "Sorting by grade:" << endl;
    printVector(vStudent);

    sort(vStudent.begin(), vStudent.end(), compareVecByID);
    cout << endl << "Sorting by ID:" << endl;
    printVector(vStudent);

    sort(vStudent.begin(), vStudent.end(), compareVecByIDReverse);
    cout << endl << "Sorting by ID reverse:" << endl;
    printVector(vStudent);

    sort(vStudent.begin(), vStudent.end(), compareVecByName);
    cout << endl << "Sorting by name:" << endl;
    printVector(vStudent);


    return 0;
}
