// Array
// 1. ��� ������ ������ �������
// 2. ��� ������� ����� ������� �� ��������� char

#include <iostream>

void f7(int) {
}

// ����� ������� �� ��������� char
void f7(char) = delete;


void test7() {
    f7(10);
    // f7('3');  //error: use of deleted function 'void f7(char)'

    int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(n) / sizeof(n[0]);
    // int len2 = std::size(n);
    std::cout << '\n' << len << '\n';  // 10
}
