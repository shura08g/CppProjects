/*
������: ������ ������
 ������������ ����� ��� ����� ������� ��� ������������� � ���������, �������
������������ ������ ������. ��� ������� �������� ����� ������� ��� �������,
������������� � ��������� ���������� �������� � �������� ��������� �� 0 �� 100.
��������� ������ ��������� ��������� � ������� ������, ���������� ������ �� ���
�������� ��������, ����������������� �� ID � �������, �������������� � ��������
��� ��������� �������, � ���������� ������� ������ ������. ���������������
��������� ������ ��� ������� ���������� ������������ � ����. 5.1.
 ����. 5.1. ��������� ������
 �������� �����������
 ��������� ������
 93-100 �
 90-92  A-
 87-89  B+
 83-86  �
 80-82  �-
 77-79 	C+
 73-76 	�
 70-72 	C-
 67-69 	D+
 60-66 	D
 0-59 	F

*/
#include <iostream>
#include <string>

using namespace std;
/*
struct student{
    int grade;
    int studentID;
    string name;
};
*/

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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
