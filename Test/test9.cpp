// Template
#include <iostream>

template<int n>
struct F9{
    enum { value = n * F9<n - 1>::value };
    //In instantiation of 'struct F9<-894>'
};

// нужно указать когда остановится (при F9<1> мы знаем что будет 1
template<>
struct F9<1>{
    enum { value = 1 };
};

void test9() {
    std::cout << F9<5>::value << '\n';  // 120
}
