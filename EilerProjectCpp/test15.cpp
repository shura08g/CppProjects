#include <iostream>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 15
Пути через таблицу

Начиная в левом верхнем углу сетки 2×2 и имея возможность двигаться
только вниз или вправо, существует ровно 6 маршрутов до правого нижнего
угла сетки.
p015.png
Сколько существует таких маршрутов в сетке 20×20?

Starting in the top left corner of a 2×2 grid, and only being able to
move to the right and down, there are exactly 6 routes to the bottom right
corner.
p015.png
How many such routes are there through a 20×20 grid?
*/

unsigned long long fact(int num){
    unsigned long long f = 1;
    for (int i = 1; i <= num; i++){
        f = f * i;
    }
    return f;
}

void eiler15(){
    int row = 10;
    int col = 10;
    unsigned long long f1 = fact(row + col);
    unsigned long long f2 = fact(row);
    unsigned long long f3 = fact(col);
    // cout << f1 << " " << f2 << " " << f3 << endl;
    unsigned long long result = f1 / f2 / f3;
    cout << "15. Result = " << result << endl;
    // 15. Result = 184756
}
