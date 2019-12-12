#include <iostream>
#include <cmath>
#include <string>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a, b, c;
    float x1, x2, discriminant, realPart, imageneryPart;
    string aStr, bStr, cStr;
    cout << "Введите коэффициенты a, b, c: " << endl;
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    aStr = to_string(a);
    bStr = (b > 0) ? "+" + to_string(b) : to_string(b);
    cStr = (c > 0) ? "+" + to_string(c) : to_string(c);
    if (discriminant > 0){
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << a << "x^2 " << bStr << "x " << cStr << " = 0" << endl;
        cout << "Корни являются вещественными и они разные" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (discriminant == 0){
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << a << "x^2 " << bStr << "x " << cStr << " = 0" << endl;
        cout << "Корни являются вещественными и они одинаковые" << endl;
        cout << "x1 = " << x1 << endl;
    }
    else{
        realPart = -b / (2 * a);
        imageneryPart = sqrt(-discriminant) / (2 * a);
        cout << a << "x^2 " << bStr << "x " << cStr << " = 0" << endl;
        cout << "Корни являются комплексными и они разные" << endl;
        cout << "x1 = " << realPart << " + " << imageneryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imageneryPart << "i" << endl;
    }
    return 0;
}
