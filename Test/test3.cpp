#include <iostream>

struct A1 {
    A1() {
        std::cout << "A1:";
    }
    ~A1() {
        std::cout << "~A1:";
    }
};

struct A2 {
    A2() {
        std::cout << "A2:";
    }
    ~A2() {
        std::cout << "~A2:";
    }
};

class B {
public:
    B() {
        std::cout << "B:";
    }
    ~B() {
        std::cout << "~B:";
    }
private:
    A1 a;
};

class C: public B {
public:
    C() {
        std::cout << "C:";
    }
    ~C() {
        std::cout << "~C:";
    }
private:
    A2 a;
};

int test3() {
    C c;  // A1:B:A2:C:
    std::cout << '\n';
    // ~C:~A2:~B:~A1:
}
