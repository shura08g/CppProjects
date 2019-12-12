#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 6
Разность между суммой квадратов и квадратом суммы

Сумма квадратов первых десяти натуральных чисел равна

1^2 + 2^2 + ... + 10^2 = 385
Квадрат суммы первых десяти натуральных чисел равен

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Следовательно, разность между суммой квадратов и квадратом суммы первых
десяти натуральных чисел составляет 3025 − 385 = 2640.

Найдите разность между суммой квадратов и квадратом суммы первых ста
натуральных чисел.

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.
*/

void eiler6(){
    int sum_square = 0;
    int square_sum = 0;
    int sum = 0;
    int dif = 0;
    for (int i = 0; i <= 100; i++){
        sum_square += i * i;
        sum += i;
    }
    square_sum = sum * sum;
    dif = square_sum - sum_square;
    cout << "#6. Result = " << dif << endl;
    //#6. Result = 25164150
}
