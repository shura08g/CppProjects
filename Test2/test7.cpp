#include <iostream>

struct X7 {
    X7() { std::cout << "a"; }
    X7(const X7 &x) { std::cout << "b"; }
    const X7 &operator=(const X7 &x) {
         std::cout << "c";
         return *this;
    }
};

void test7() {
    std::cout << '\n';
    X7 x;  // a
    X7 y(x);  // b
    X7 z = y;  // z ещё не создан поэтому вызовется b
    z = x;  // c
    // abbc
}
