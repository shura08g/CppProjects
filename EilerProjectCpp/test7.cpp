#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 7
10001-ое простое число

Выписав первые шесть простых чисел, получим 2, 3, 5, 7, 11 и 13.
Очевидно, что 6-ое простое число - 13.

Какое число является 10001-ым простым числом?

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

int prim_num = 10001;

bool is_prm(int x){
    if (x == 2) return 1;
    if (x < 2 || x % 2 == 0) return 0;
    for (int i = 3; i * i <= x; i += 2){
        if (x % i == 0) return 0;
    }
    return 1;
}

void eiler7(){
    int i = 1;
    int num = 0;
    while (num < prim_num){
        i += 1;
        if (is_prm(i)){
            num += 1;
            // cout << num << " : " << i << endl;
        }
    }
    cout << "#7. " << i << " is " << prim_num << " prime number" << endl;
    //#7. 104743 is 10001 prime number
}
