#include <iostream>
#include <sstream>
#include <vector>

template<typename T>
void print_impl(const T &t){
    std::cout << t << '\n';
}

int f1(){
    std::cout << "f1\n";
    return 1;
}

int f2(){
    std::cout << "f2\n";
    return 2;
}

template<typename ... T>
void print(const T& ... t){
    //(void)std::initializer_list<int>{ (print_impl(t), 0)... };
    (void)std::initializer_list<int>{ (std::cout << t << '\n', 0)... };
}

template<typename ... T>
std::vector<std::string> print_vec(const T& ... t){
    std::vector<std::string> retval;
    std::stringstream ss;
    (void)std::initializer_list<int>{ (ss.str(""), ss << t, retval.push_back(ss.str()), 0)... };
    return retval;
}

int main()
{
    print("---TEST PRINT---");
    print("Hello world!", 1, 2.2, 3, 4, 5.50f, f1(), f2());
    print(f1(), f2());  // f2, f1, 1, 2 in clang f1, f2, 1, 2
    (void)std::initializer_list<int>{ f1(), f2() }; // f1, f2
    print("---TEST PRINT_VEC---");
    for (const auto &s : print_vec("Hello world!", 1, 2.2, 3, 4, 5.50f, f1(), f2())){
        std::cout << s << '\n';
    }
    return 0;
}
