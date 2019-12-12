#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void printVec(vector<int> vec){
    int size = vec.size();
    cout << "[";
    for (int i = 0; i < size; ++i){
        if (i == size - 1) cout << vec[i] << "]" << endl;
        else cout << vec[i] << " ";
    }
}

int main()
{
    //srand(55);
    srand(time(0));
    vector<int> vecInt;
    int number;
    for (int i = 0; i < 25; ++i){
        number = (1 + rand()%10); // range 1..10
        vecInt.push_back(number);
        cout << number << endl;
    }

    printVec(vecInt);
    return 0;
}
