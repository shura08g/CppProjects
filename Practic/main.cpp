#include <iostream>

using namespace std;

void test1(){
    char a = 'A';
    char b = 'B';
    char c;
    c = a + b;
    cout << "A + B = " << c << endl;
}

void test2(){
    cout << "bool " << sizeof(bool) << endl;
    cout << "char " << sizeof(char) << endl;
    cout << "short " << sizeof(short) << endl;
    cout << "int " << sizeof(int) << endl;
    cout << "unsigned int " << sizeof(unsigned int) << endl;
    cout << "long " << sizeof(long) << endl;
    cout << "float " << sizeof(float) << endl;
    cout << "double " << sizeof(double) << endl;
    cout << "long long " << sizeof(long long) << endl;
    cout << "unsigned long long " << sizeof(unsigned long long) << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
