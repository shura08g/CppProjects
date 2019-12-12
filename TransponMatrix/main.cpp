#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a[10][10], transpose[10][10], r, c, i, j;
    cout << "������� ���������� ����� � �������: " << endl;
    cin >> r >> c;

    // ��������� ��������
    cout << "\n������� �������� �������:\n";
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            cout << "a" << i + 1 << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    // ���������� a[][]
    cout <<"\n�������� �������: \n";
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            cout << a[i][j] << " ";
            if (j == c - 1)
                cout << "\n\n";
        }
    }

    // ��������� ���������������� �������
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            transpose[j][i] = a[i][j];
        }
    }

    // ���������
    cout <<"\n����������������� �������: \n";
    for (i = 0; i < c; ++i){
        for (j = 0; j < r; ++j){
            cout << transpose[i][j] << " ";
            if (j == r - 1)
                cout << "\n\n";
        }
    }

    return 0;
}
