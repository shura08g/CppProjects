// According to the C++17 standard, what is the output of this program?
#include <iostream>

void test13() {
    int a = 0;
    decltype(a) b = a;
    b++;
    std::cout << a << b << '\n';  // 01
}
