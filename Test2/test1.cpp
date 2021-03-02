#include <iostream>

using Func1 = int();

struct S1 {
    Func1 f1;
};

int S1::f1() { return 1; }

void test1()
{
    S1 s1;
    std::cout << s1.f1() << std::endl;  // 1
}
