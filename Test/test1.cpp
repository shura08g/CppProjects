#include <iostream>

using namespace std;

int a = 2;

int& f(int x) {
    a = a + x;
    return a;
}

void test1()
{
    int t = 2;
    // cout << a  << ' ' << t << endl;  // 2 2
    cout << f(t) << endl;  // 4
    // cout << a  << ' ' << t << endl;  // 4 2
    f(t) = 10;
    // cout << a  << ' ' << t << endl;  // 10 2
    cout << f(t) << endl;  // 12
    // cout << a  << ' ' << t << endl;  // 12 2
    t = f(t);
    // cout << a  << ' ' << t << endl;  // 14 14
    cout << f(t) << endl;  // 28
    // cout << a  << ' ' << t << endl;  // 28 14
}
