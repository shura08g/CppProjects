#include <iostream>
#include <cmath>
#include <utility>

long long int fibonacci(const int i){
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

template<int I>
struct Fib{
    static const unsigned long long int val = Fib<I - 1>::val + Fib<I - 2>::val;
};

template<>
struct Fib<0>{
    static const int val = 0;
};

template<>
struct Fib<1>{
    static const int val = 1;
};

constexpr long long int fib(const int i){
    constexpr auto sqrt_5 = std::sqrt(5);
    if (i == 0) return 0;
    if (i == 1) return 1;
    return static_cast<long long int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i)) / (std::pow(2, i) * sqrt_5));
}

int main()
{
    //std::cout << fibonacci(45) << '\n'; // 1134903170 7.308s.
    //std::cout << Fib<45>::val << '\n'; // 1134903170 0.030s.
    //std::cout << Fib<92>::val << '\n'; // 7540113804746346429 0.031s. for long long int
    //std::cout << Fib<93>::val << '\n'; // 12200160415121876738 0.030s. for unsigned long long int
    //std::cout << fib(45) << '\n'; // 1134903170 0.031s.
    //std::cout << fib(72) << '\n'; // ~498454011879265 0.032s.
    // std::cout << fib(92) << '\n'; // ~7540113804746369157 0.032s.

    auto fib2 = [a = 0, b = 1]() mutable {
        struct Results{
            int &a;
            int &b;

            Results next(int num = 1){
                while (num > 0){
                    a = std::exchange(b, b + a);
                    --num;
                }

                return *this;
            }
            operator int(){  // чтови не писать fib2().a
                return  b - a;
            }
        };
        return Results{a, b}.next();
    };
    //fib2().b = 8;
    std::cout << fib2().next(45) << '\n'; // 1134903170 0.031s.
    return 0;
}
