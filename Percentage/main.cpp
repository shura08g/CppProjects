#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a;
    float p = 10000;
    float r = 0.01;
    int days;

    cout << "Input days count:" << endl;
    cin >> days;

    for (int day = 1; day <= days; day++){
        a = p * pow(1 + r, day);
        cout << day << " ----- " << a << endl;
    }
    return 0;
}
