#include <iostream>
#include <windows.h>  // for sleep()
#include <iomanip>  // setfill(), setw()

using namespace std;

int main()
{
    int h = 0, m = 0, s = 0;
    cout << "Enter time in format of HH MM SS\n" << endl;
    cin >> h >> m >> s;
    // �������� ���� ������
    //HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    system("color 0A");
    if (h > 23) h = 0;
    if (h > 23) h = 0;
    if (m > 59) m = 0;
    if (s > 59) s = 0;
    for(; h <= 24; h++){
        if (h == 24) h = 0;
        for(; m < 60; m++){
            for(; s < 60; s++){
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
                cout << setfill('0') << setw(2) << h << ":";
                cout << setfill('0') << setw(2) << m << ":";
                cout << setfill('0') << setw(2) << s << "\r";
                Sleep(1000);
            }
            s = 0;
        }
        m = 0;

    }
}
/*
0=������
1=�����
2=�������
3=�������
4=�������
5=�������
6=������
7=�����
8=�����
9=������-�����
a=������-�������
b=������-�������
c=������-�������
d=������-�������
e=������-������
f=����-�����
*/
