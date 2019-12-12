#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 1
Числа, кратные 3 или 5

Если выписать все натуральные числа меньше 10, кратные 3 или 5,
то получим 3, 5, 6 и 9. Сумма этих чисел равна 23.
Найдите сумму всех чисел меньше 1000, кратных 3 или 5.

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

void eiler1(){
    int limit1 = 1000;
    int sum = 0;
    for (int i = 3; i < limit1; i++){
        if ((i % 3 == 0) || (i % 5 == 0)) sum += i;
    }
    cout << "#1. Sum = " << sum << endl;
    //#1. Sum = 233168
}
