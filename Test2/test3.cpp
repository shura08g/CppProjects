#include <iostream>
#include <string>

void test3() {
  std::string out{"Hello world"};
  //std::cout << (out[out.size()] == '');  // 1
  std::cout << (out[out.size()] == 0);  // 1
}
