#include <iostream>

volatile int a5;
//int a5; // 0

void test5() {
    //int a5;  // ��� ������  undefined
    std::cout << '\n';
    std::cout << (a5 + a5);  // undefined or 0
}
