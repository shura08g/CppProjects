#include <iostream>
#include <string>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 4
Наибольшее произведение-палиндром

Число-палиндром с обеих сторон (справа налево и слева направо) читается
одинаково.
Самое большое число-палиндром, полученное умножением двух двузначных чисел –
9009 = 91 × 99.

Найдите самый большой палиндром, полученный умножением двух трехзначных чисел.

A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool polindrom(int x){
    string num_str = to_string(x);
    int len = num_str.length();
    for (int i = 0; i <= len; i++){
        if (num_str[i] != num_str[len - (1 + i)]) return 0;
    }
    return 1;
}

void eiler4(){
    int start = 100;
    int finish = 999;
    int pol = 0;
    int product = 0;
    while (start <= finish){
        for (int i = finish; i >= start; i--){
            product = i * finish;
            if (polindrom(product)){
                if (pol < product) pol = product;
            }
        }
        --finish;
    }
    cout << "#4. Largest palindrome = " << pol << endl; // 906609
    //#4. Largest palindrome = 906609
}
