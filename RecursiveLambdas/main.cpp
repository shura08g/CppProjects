#include <iostream>

using namespace std;

constexpr auto fib_ = [](const auto fib, int input){
    if (input < 2){
        return 1;
    }
    return fib_(fib, input - 1) + fib_(fib, input - 2);
};

constexpr auto fib = [](int input){
    return fib_(fib_, input);
};

constexpr auto fib2 = [](int input){
    auto fib_ = [](const auto fib2, int input){
        if (input < 2){
            return 1;
        }
        return fib2(fib2, input - 1) + fib2(fib2, input - 2);
    };
    return fib_(fib_, input);
};

int main()
{
    cout << fib_(fib, 3) << endl;
    cout << fib_(fib, 4) << endl;
    cout << fib(5) << endl;
    cout << fib(6) << endl;
    cout << fib2(7) << endl;
    cout << fib2(10) << endl;
    return 0;
}
