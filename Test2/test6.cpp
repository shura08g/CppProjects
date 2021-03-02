#include <iostream>

struct A6 {
    A6() { std::cout << "A"; }
    A6(const A6 &a) { std::cout << "B"; }
    virtual void f6() { std::cout << "C"; }
};

void test6() {
    std::cout << '\n';
    A6 a[2];
    for (auto x : a) {
        x.f6();
    }
    // AABCBC  (AA - два элемента a[2])
    std::cout << '\n';
    A6 a2[3];
    // для избежания вызова копирующего конструктора вызываем по ссылке
    for (auto& x : a2) {
        x.f6();
    }
    // AAACCC
}
