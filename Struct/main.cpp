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
    cout << "Инфо о студенте" << endl;
    cout << "Имя: ";
    cin >> s1.name;
    cout << "Курс: ";
    cin >> s1.roll;
    cout << "Оценка: ";
    cin >> s1.mark;

    cout << "\nОтображаем инфо:" << endl;
    cout << "Имя: " << s1.name << endl;
    cout << "Курс: " << s1.roll << endl;
    cout << "Оценка: " << s1.mark << endl;*/

 /*   cout << "\nПервая структура" << endl;
    cout << "Количество шагов: ";
    cin >> d1.feet;
    cout << "Количество метров: ";
    cin >> d1.meters;

    cout << "\nВторая структура" << endl;
    cout << "Количество шагов: ";
    cin >> d2.feet;
    cout << "Количество метров: ";
    cin >> d2.meters;

    sum.feet = d1.feet + d2.feet;
    sum.meters = d1.meters + d2.meters;

    cout << endl << "Сумма = " << sum.feet << " шагов ";
    cout << sum.meters << " метров" << endl;*/

    ComplexNumber n1, n2, temporaryNumber;
    char signOfImag;

    cout << "\nПервое комплексное число" << endl;
    cout << "Введите действительную и мнимую часть соответственно: " << endl;
    cin >> n1.real >> n1.img;

    cout << "\nВторое комплексное число" << endl;
    cout << "Введите действительную и мнимую часть соответственно: " << endl;
    cin >> n2.real >> n2.img;

    temporaryNumber = add(n1, n2);
    signOfImag = (temporaryNumber.img > 0) ? '+' : '-';
    temporaryNumber.img = (temporaryNumber.img > 0) ? temporaryNumber.img : -temporaryNumber.img;
    cout << "Сумма = " << temporaryNumber.real << signOfImag << temporaryNumber.img << "i";
    cout << endl;

    return 0;
}
