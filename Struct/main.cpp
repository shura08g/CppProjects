#include <iostream>
#include <clocale>
#include <string>

using namespace std;

struct Student{
    string name;
    int roll;
    float mark;
};

struct Distance{
    int feet;
    float meters;
}d1, d2, sum;

typedef struct ComplexNum{
    float real;
    float img;
}ComplexNumber;



ComplexNumber add(ComplexNum n1, ComplexNum n2){
    ComplexNum temp;
    temp.real = n1.real + n2.real;
    temp.img = n1.img + n2.img;
    return temp;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
 /*   Student s1;
    cout << "���� � ��������" << endl;
    cout << "���: ";
    cin >> s1.name;
    cout << "����: ";
    cin >> s1.roll;
    cout << "������: ";
    cin >> s1.mark;

    cout << "\n���������� ����:" << endl;
    cout << "���: " << s1.name << endl;
    cout << "����: " << s1.roll << endl;
    cout << "������: " << s1.mark << endl;*/

 /*   cout << "\n������ ���������" << endl;
    cout << "���������� �����: ";
    cin >> d1.feet;
    cout << "���������� ������: ";
    cin >> d1.meters;

    cout << "\n������ ���������" << endl;
    cout << "���������� �����: ";
    cin >> d2.feet;
    cout << "���������� ������: ";
    cin >> d2.meters;

    sum.feet = d1.feet + d2.feet;
    sum.meters = d1.meters + d2.meters;

    cout << endl << "����� = " << sum.feet << " ����� ";
    cout << sum.meters << " ������" << endl;*/

    ComplexNumber n1, n2, temporaryNumber;
    char signOfImag;

    cout << "\n������ ����������� �����" << endl;
    cout << "������� �������������� � ������ ����� ��������������: " << endl;
    cin >> n1.real >> n1.img;

    cout << "\n������ ����������� �����" << endl;
    cout << "������� �������������� � ������ ����� ��������������: " << endl;
    cin >> n2.real >> n2.img;

    temporaryNumber = add(n1, n2);
    signOfImag = (temporaryNumber.img > 0) ? '+' : '-';
    temporaryNumber.img = (temporaryNumber.img > 0) ? temporaryNumber.img : -temporaryNumber.img;
    cout << "����� = " << temporaryNumber.real << signOfImag << temporaryNumber.img << "i";
    cout << endl;

    return 0;
}
