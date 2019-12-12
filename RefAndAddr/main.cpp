#include <iostream>

using namespace std;

void passByReference(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}

void passByAddress(int* x, int* y){
    int z = *x;
    *x = *y;
    *y = z;
}

void passByVal(int val){
    val = 10;
    cout << "val = " << val << endl;
}

void passByRef(int & refer){
    refer = 20;
    cout << "ref = " << refer << endl;
}

void passByPrt(int * ptr){
    *ptr = 30;
    cout << "*ptr = " << *ptr << endl;
}

int main()
{
    int a = 55;
    int b = 77;
    int c = 99;
    cout << "Before swapping: " << "a = " << a << "; b = " << b << "; c = " << c << endl;
    passByReference(a, b);
    cout << "After swapping: " << "a = " << a << "; b = " << b << "; c = " << c << endl;
    passByAddress(&b, &c);
    cout << "After swapping: " << "a = " << a << "; b = " << b << "; c = " << c << endl;

    int x = 5;

    cout << "x = " << x << endl;
    passByVal(x);
    cout << "x = " << x << endl;
    passByRef(x);
    cout << "x = " << x << endl;
    passByPrt(&x);
    cout << "x = " << x << endl;
    int y = 50;
    int * yprt = &y;
    cout << "y = " << y << endl;
    passByPrt(yprt);
    cout << "y = " << y << endl;

    int * prt;
    int var = 7;
    prt = &var;
    cout << var << " in address: " << prt << " dereference pointer: " << *prt <<endl;
    int& refer = var;
    cout << refer << " in address: " << &refer << endl;
    int new_var = 21;
    refer = new_var;
    cout << refer << " in address: " << &refer << endl;

    return 0;
}
