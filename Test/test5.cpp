#include <iostream>

class D2 {
public:
    D2() {
        std::cout << "D2: ";
    }
    virtual void foo() {
        std::cout << "D2::foo\n";
    }
};

class E2: public D2 {
public:
    E2() {
        std::cout << "E2: ";
    }
    void foo() override {
        std::cout << "E2::foo\n";
    }
};

class F2: public E2 {
public:
    F2() {
        std::cout << "F2: ";
    }
    void foo() override {
        std::cout << "F2::foo\n";
    }
};

void test5() {
    std::cout << '\n';
    F2 f;
    E2 *pe = &f;

    pe->foo();  // D2: E2: F2: F2::foo
}

