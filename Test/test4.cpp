#include <iostream>

class D {
public:
    D() {
        std::cout << "D: ";
    }
    void foo() {
        std::cout << "D::foo\n";
    }
};

class E: public D {
public:
    E() {
        std::cout << "E: ";
    }
    void foo() {
        std::cout << "E::foo\n";
    }
};

class F: public E {
public:
    F() {
        std::cout << "F: ";
    }
    void foo() {
        std::cout << "F::foo\n";
    }
};

void test4() {
    std::cout << '\n';
    F f;
    E *pe = &f;

    pe->foo();  // D: E: F: E::foo
}
