#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 9
Особая тройка Пифагора

Тройка Пифагора - три натуральных числа a < b < c,
для которых выполняется равенство

a^2 + b^2 = c^2
Например, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

Существует только одна тройка Пифагора, для которой a + b + c = 1000.
Найдите произведение abc.

A Pythagorean triplet is a set of three natural numbers, a < b < c,
for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

void eiler9(){
    int product = 1000;
    int result = 0;
    int a, b, c;
    bool flag = false;
    for (a = 1; a <= product; a++){
        if (flag) break;
        for (b = a; b <= product; b++){
            c = product - a - b;
            if (c > 0){
                if (c * c == a * a + b * b){
                    result = a * b *c;
                    flag = true;
                    a--;
                    break;
                }
            }
        }
    }
    cout << "#9. " << a << " * " << b << " * " << c << " = " << result << endl;
    //#9. 200 * 375 * 425 = 31875000
}
