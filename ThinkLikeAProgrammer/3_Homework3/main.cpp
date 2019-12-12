/*
	Напишите  функцию  bool,  которой  передается  массив  и  коли¬
чество  элементов  в  этом  массиве  и  которая  определяет,  будут  ли
данные  в  этом  массиве  сортироваться.  Для  этого  требуется  толь¬
ко  одна  передача!
*/

#include <iostream>

using namespace std;

bool be_sorted(int *arr, size_t size){
    for (size_t i = 0; i < size - 1; ++i){
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {3, 1, 5, 6, 8, 10, 7, 4, 2, 9};
    int arr3[] = {1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool flag;
    size_t size;

    size = sizeof(arr1)/sizeof(int);
    flag = be_sorted(arr1, size);

    if (flag) cout << "Array sorted" << endl;
    else cout << "Array not sorted" << endl;

    size = sizeof(arr2)/sizeof(int);
    flag = be_sorted(arr2, size);

    if (flag) cout << "Array sorted" << endl;
    else cout << "Array not sorted" << endl;

    size = sizeof(arr3)/sizeof(int);
    flag = be_sorted(arr3, size);

    if (flag) cout << "Array sorted" << endl;
    else cout << "Array not sorted" << endl;

    return 0;
}
