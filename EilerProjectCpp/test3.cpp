#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 3
Наибольший простой делитель
Простые делители числа 13195 - это 5, 7, 13 и 29.
Каков самый большой делитель числа 600851475143, являющийся простым числом?

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
*/

void eiler3(){
    unsigned long long big_num = 600851475143;
    unsigned long long lpf = big_num;
    unsigned long long factor = 2;
    while (factor * factor <= lpf){
        while (lpf % factor == 0){
            lpf = lpf / factor;
        }
        factor++;
    }
    cout << "#3. Largest prime factor of " << big_num << " is " << lpf << endl;
    //#3. Largest prime factor of 600851475143 is 6857
}
