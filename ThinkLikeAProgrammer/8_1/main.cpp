#include <iostream>

double averagePositive(int *arr, int sizeArr){
    int sumPositive = 0;
    int totalPositive = 0;
    for (int i = 0; i < sizeArr; ++i){
        if (arr[i] > 0){
            sumPositive += arr[i];
            ++totalPositive;
        }
    }
    if (totalPositive == 0) return -1;
    return sumPositive/(double)totalPositive;
}

int main()
{
    int ARRSIZE = 5;
    int arr[ARRSIZE] = {7, 5, -6, 0, 9};
    std::cout << averagePositive(arr, ARRSIZE) << '\n'; // 5
    int arr2[] = {-7, -5, -6, 0, -9};
    std::cout << averagePositive(arr2, ARRSIZE) << '\n'; // nan
    return 0;
}
