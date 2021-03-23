#include <iostream>
#include <string>

auto test12() -> void {
    std::string out{"Hello world"};
    //std::cout << (out[out.size()] == '');  // error: empty character constant
    std::cout << (out[out.size()] == '\0') << "\n";  // 1
}
