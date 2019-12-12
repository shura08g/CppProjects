#include <iostream>
#include <cmath>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 10
Сложение простых чисел

Сумма простых чисел меньше 10 равна 2 + 3 + 5 + 7 = 17.

Найдите сумму всех простых чисел меньше двух миллионов.

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

const int limit10 = 2000000;
int sieve[limit10];

void fill_arr(int s[]){
    for (int i = 0; i <= limit10; i++){
        s[i] = 1;
    }
}

void mark(int s[], int x){
    for (int i = x + x; i < limit10; i += x){
        s[i] = 0;
        // s[i] = 1;
    }
}

void eiler10_sieve(){
    fill_arr(sieve);
    unsigned long long result = 0;
    for (int i = 2; i < int(sqrt(limit10)) + 1; i++){
        mark(sieve, i);
    }
    for (int i = 2; i < limit10; i++){
        if (sieve[i]) result += i;
        //if (!sieve[i]) result += i;
    }
    cout << "#10. Sum = " << result << endl;
    // #10. Sum = 142913828922 execution time : 0.150 s
}

bool is_prime10(int x){
    if (x == 2) return 1;
    if (x < 2 || x % 2 == 0) return 0;
    for (int i = 3; i * i <= x; i += 2){
        if (x % i == 0) return 0;
    }
    return 1;
}

void eiler10(){
    unsigned long long result = 0;
    for (int i = 2; i < limit10; i++){
        if (is_prime10(i)) result += i;
    }
    cout << "#10. Sum = " << result << endl;
    // #10. Sum = 142913828922 execution time : 0.285 s
}
