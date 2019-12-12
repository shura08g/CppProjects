#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    int a[10][10], transpose[10][10], r, c, i, j;
    cout << "Введите количество строк и колонок: " << endl;
    cin >> r >> c;

    // Сохраняем элементы
    cout << "\nВведите элементы матрицы:\n";
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            cout << "a" << i + 1 << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    // Показываем a[][]
    cout <<"\nИсходная матрица: \n";
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            cout << a[i][j] << " ";
            if (j == c - 1)
                cout << "\n\n";
        }
    }

    // Вычисляем транспонированую матрицу
    for (i = 0; i < r; ++i){
        for (j = 0; j < c; ++j){
            transpose[j][i] = a[i][j];
        }
    }

    // Результат
    cout <<"\nТранспонированная матрица: \n";
    for (i = 0; i < c; ++i){
        for (j = 0; j < r; ++j){
            cout << transpose[i][j] << " ";
            if (j == r - 1)
                cout << "\n\n";
        }
    }

    return 0;
}
