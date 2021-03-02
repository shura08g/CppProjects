#include <iostream>

volatile int a5;
//int a5; // 0

void test5() {
    //int a5;  // что угодно  undefined
    std::cout << '\n';
    std::cout << (a5 + a5);  // undefined or 0
}
