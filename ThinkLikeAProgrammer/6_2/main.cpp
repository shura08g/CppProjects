/*
Задача: вычисление суммы элементов целочисленного массива
 Напишите рекурсивную функцию, которой в качестве параметров передан
массив целых чисел и размер массива. Эта функция должна возвратить сумму
целых чисел в массиве.
*/

#include <iostream>

void printArr(int arr[], int size){
    std::cout << "[";
    for (int i = 0; i < size; ++i){
        if (i == size - 1) std::cout << arr[i];
        else std::cout << arr[i] << ", ";
    }
    std::cout << "]";
}

int iterativeArraySum(int integers[], int size){
    int sum = 0;
    for (int i = 0; i < size; ++i){
        sum += integers[i];
    }
    return sum;
}

int arraySumRecursive(int integers[], int size){
    if (size == 0) return 0;
    //int lastNumber = integers[size - 1];
    //int allButLastSum = arraySumRecursive(integers, size - 1);
    //return lastNumber + allButLastSum;
    return integers[size - 1] + arraySumRecursive(integers, size - 1);
}

int main()
{
    const int ARR_SIZE = 10;
    int int_arr[ARR_SIZE] = {12, 34, 321, 45, 54, 87, 8, 96, 43, 65};
    std::cout << "Iterative path: " << '\n';
    int sum = iterativeArraySum(int_arr, ARR_SIZE);
    std::cout << "Sum of ";
    printArr(int_arr, ARR_SIZE);
    std::cout << " = " << sum << '\n';

    std::cout << "Recursive path: " << '\n';
    sum = arraySumRecursive(int_arr, ARR_SIZE);
    std::cout << "Sum of ";
    printArr(int_arr, ARR_SIZE);
    std::cout << " = " << sum << '\n';
    return 0;
}
