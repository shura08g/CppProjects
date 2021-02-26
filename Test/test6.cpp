#include <iostream>

class A {
public:
    A() {
        std::cout << "1 ";
    }

    A(const A&) {
        std::cout << "2 ";
    }

    A& operator=(const A&) {
        std::cout << "3 ";
        return *this;
    }
};

void test6() {
    std::cout << '\n';
    A a1;
    A a2 = a1;
    A a3;
    a3 = a1;
    // 1 2 1 3
}
