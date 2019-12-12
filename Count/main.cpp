#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 1. auto - return type deduction
template<typename T>
auto count_things(const T &vec, int value){
    const auto count = std::count(begin(vec), end(vec), value);
    return count;
}

// 2. lambdas - generic
template<typename T>
void count_things_less_then_5(const T &vec, int value){
    const auto count = std::count(begin(vec), end(vec),
                                  [](const auto i){ return i < 5; }
                                  );
    std::cout << count << '\n';
}

// 3. lambdas - generalized capture expression
template<typename T>
void count_things_less_then_num_cpp14(const T &vec, int value){
    const auto count = std::count(begin(vec), end(vec),
                                  [value = static_cast<int>([](){return 5;}())](const auto i){ return i < value; }
                                  );
    std::cout << count << '\n';
}

// 4. make_unique - new and delete now no needed!
#include <memory>
void allocate_memory(){
    auto prt(std::make_unique<int>(5));
} // prt is destroyed, memory freed

// 5. constexpr is more flexible
constexpr int get_value(){
    int val = 5;
    int val2 = 3;
    return val * val2;
}

constexpr auto = get_value();

int main()
{
    std::vector<int> intVec = {1,2,3,4,5,7,8,6,1,2,43,4,2,3,7,15,4,3};
    std::vector<std::string> strVec = {"abc","def","ghi"};

    std::cout << count_things(intVec, 7) << '\n';
    // count_things_less_then_5(intVec, 5);
    //count_things_less_then_num_cpp14(intVec, 5);
    return 0;
}
