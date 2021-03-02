#include <iostream>

class A4 {
public:
    A4() { std::cout << 'a'; }
    ~A4() { std::cout << 'A'; }
};

class B4 {
public:
    B4() { std::cout << 'b'; }
    ~B4() { std::cout << 'B'; }
    A4 a;
};

void test4() {
    std::cout << '\n';
    B4 b;  //abBA
}
