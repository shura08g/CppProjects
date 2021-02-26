#include <iostream>

// Что вернет функция
int f8( int x) {
    int count = 0;
    while (x) {
        count++;
        x = x&(x-1);
        /*
           (11)   (10)
        1. 1011 & 1010 -> 1010  (10)
        2. 1010 & 1001 -> 1000  (8)
        3. 1000 & 0111 -> 0000  (0)
        */
    }
    return count;
}

void test8() {
    std::cout << f8(11) << std::endl;  // 3
}
