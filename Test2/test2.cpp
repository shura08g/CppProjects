#include <iostream>

template <class T> void f2(T) {
    static int i = 0;
    std::cout << ++i << '\n';
}

void test2() {
    f2(1);  // 1
    f2(1.0);// 1
    f2(1);  // 2
}
