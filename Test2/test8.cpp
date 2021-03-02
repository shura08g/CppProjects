#include <iostream>

struct Foo8 {
    operator auto() {
        std::cout << "A";
        return 1;
    }
};

void test8() {
    std::cout << '\n';
    int a = Foo8();
    std::cout << a;  // A1
    std::cout << '\n';
    bool f = Foo8();
    std::cout << f;  // A1
}
