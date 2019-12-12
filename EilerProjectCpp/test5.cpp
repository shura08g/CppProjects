#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 5
Наименьшее кратное

2520 - самое маленькое число, которое делится без остатка
на все числа от 1 до 10.

Какое самое маленькое число делится нацело на все числа от 1 до 20?

2520 is the smallest number that can be divided by each of
the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by
all of the numbers from 1 to 20?
*/

void test_2520(){
    int test_num = 2520;
    for (int i = 1; i <= 10; i++){
        if (test_num % i == 0) {
            cout << test_num << " % " << i << " = " << test_num % i << endl;
        }
        else{
            cout << "#5. Test fails: " << test_num << " % " << i << " = " << test_num % i << endl;
            break;
        }

    }
}

void eiler5_test(){
    // test_2520();
    int result = 0;
    int start = 20;
    bool flag = false;
    while (result == 0){
        for (int i = 1; i <= 20; i++){
            if (start % i == 0) flag = true;
            else { flag = false; break; }
        }
        if (flag) result = start;
        start += 20;
    }
    cout << "#5. Result = " << result << endl;  // 232792560
}

// greatest common divisor
unsigned long long gcd(unsigned long long a, unsigned long long b){
    while (a != 0){
        unsigned long long c = a;
        a = b % a;
        b = c;
    }
    return b;
}

// least common multiple (наименьший общий множитель)
unsigned long long lcm(unsigned long long a, unsigned long long b){
    // cout << "a = " << a << " b = " << b << " gcd(a, b) = " << gcd(a, b) << endl;
    return a * b / gcd(a, b);
}

void eiler5(){
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= 20; i++){
        result = lcm(result, i);
    }
    cout << "#5. Result = " << result << endl; // 232792560
    //#5. Result = 232792560
}
