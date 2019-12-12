/*
Ќапишите  программу,  которой  дан  массив  целых  чисел  и  котођ
ра€  определ€ет  моду,  то  есть  наиболее  часто  встречающеес€  в
массиве
*/

#include <iostream>

using namespace std;

int main()
{
    const int SIZE_HIST = 100;
    int arr[] = {1,5,3,3,6,5,8,9,11,12,45,65,33,43,23,32,99,99,34,54,55,76,44,57,77,33,77,41,77};
    int histogram[SIZE_HIST] = {0};
    int maxModa = 0;
    int valModa = 0;

    size_t size = sizeof(arr)/sizeof(int);

    for (size_t i = 0; i < size; ++i){
        ++histogram[arr[i]];
    }

    for (int i = 0; i < SIZE_HIST; ++i){
        //cout << histogram[i] << " ";
        if (maxModa < histogram[i]){
            maxModa = histogram[i];
        }
        if (histogram[i] == maxModa) valModa = i;
    }

    cout << endl;
    cout << "Moda = " << valModa << " repeat " << maxModa << " times."<< endl;
    return 0;
}
