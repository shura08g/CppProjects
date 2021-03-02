#include <iostream>
#include <limits>

void test9() {
    std::cout << '\n';
    int i = std::numeric_limits<int>::max();
    std::cout << ++i;
    // -2147483648
    // C++ 17 undefined behavior
}
