#include <iostream>
#include <map>

void test10() {
    std::cout << '\n';
    std::map<bool, int> mb = {{1, 2}, {3, 4}, {5, 0}};  // 1, 3, 5 - true
    std::cout << mb.size();  // 1
    std::cout << '\n';
    std::map<int, int> mi = {{1, 2}, {3, 4}, {5, 0}};
    std::cout << mi.size();  // 3
    // 1 3
    std::cout << '\n';
    for(const auto& elem : mb)
    {
        std::cout << elem.first << ": " <<elem.second << "\n";
    }
    // 1: 2

    for(const auto& elem : mi)
    {
        std::cout << elem.first << ": " <<elem.second << "\n";
    }
    /*
    1: 2
    3: 4
    5: 0
    */
}
