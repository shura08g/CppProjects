/*
3.2. 	Перепишите  код  для  нахождения  агента  с  наивысшим  средне¬
месячным  объемом  продаж  так,  чтобы  он  находил  агента  с  самым
высоким  медианным  объемом  продаж.  Как  указывалось
ранее,  медиана  набора  значений  представляет  собой  такое  зна¬
чение,  находящееся  в  середине,  что  половина  значений  набора
больше  него,  а  другая  половина  меньше.  При  наличии  четного
количества  значений  медиана  является  простым  средним  двух
значений  в  середине.  Например,  в  наборе  10,  6,  2,  14,  7,  9
значения,  находящиеся  в  середине,  —  это  7  и  9.
Среднее  значение  7  и 9  равно  8,  поэтому  8  —  это  медиана.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_MONTHS = 12;
//const int NUM_MONTHS = 11;

double maxAverage2(int *arr, int count_agent, int count_month){
    typedef int sale[][count_month];
    sale& sales = *reinterpret_cast<sale*>(arr);
    double maxAVG = 0.0;
    for (int agent = 0; agent < count_agent; ++agent){
        double avg = 0.0;
        for (int month = 0; month < count_month; ++month){
            avg += sales[agent][month];
        }
        if (avg > maxAVG) maxAVG = avg;
        cout << avg << endl;
    }
    return maxAVG;
}

int highestSales(int sales[][NUM_MONTHS], int coun_agent, int count_month){
    int highestSales = sales[0][0];
    for (int agent = 0; agent < coun_agent; ++agent){
        for (int month = 0; month < count_month; ++month){
            if (sales[agent][month] > highestSales){
                highestSales = sales[agent][month];
            }
        }
    }
    return highestSales;
}

double maxAverage(int sales[][NUM_MONTHS], int count_agent, int count_month){
    double maxAVG = 0.0;
    for (int agent = 0; agent < count_agent; ++agent){
        double avg = 0.0;
        for (int month = 0; month < count_month; ++month){
            avg += sales[agent][month];
        }
        if (avg > maxAVG) maxAVG = avg;
        cout << avg << endl;
    }
    return maxAVG;
}

int compareFunc(const void *a, const void *b){
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

bool compF(const int &a, const int &b){
    return a < b;
}

void printArr(int *arr, int size){
    cout << "[";
    for (int i = 0; i < size; ++i){
        if (i == size - 1) cout << arr[i];
        else cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void printVec(vector<int> vect){
    cout << "[";
    for (size_t i = 0; i < vect.size(); ++i){
        if (i == vect.size() - 1) cout << vect[i];
        else cout << vect[i] << ", ";
    }
    cout << "]" << endl;
}

int maxMedian(int sales[][NUM_MONTHS], int count_agent, int count_month){
    int med = 0;
    int maxMedian = 0;
    for (int agent = 0; agent < count_agent; ++agent){
        vector<int> sale = {};
        for (int month = 0; month < count_month; ++ month){
            sale.push_back(sales[agent][month]);
        }
        sort(sale.begin(), sale.end(), compF);
        if (count_month % 2 == 0){
            med = (sale[(count_month/2 -1)] + sale[count_month/2])/2;
        }
        else{
            med = sale[count_month/2];
        }
        if (maxMedian < med) maxMedian = med;
        printVec(sale);
        cout << med << endl;
    }
    return maxMedian;
}

int maxMedianQsort(int sales[][NUM_MONTHS], int count_agent, int count_month){
    int med = 0;
    int maxMedian = 0;
    int sale[NUM_MONTHS] = {0};
    for (int agent = 0; agent < count_agent; ++agent){
        for (int month = 0; month < count_month; ++ month){
            sale[month] = sales[agent][month];
        }
        printArr(sale, count_month);
        qsort(sale, count_month, sizeof(int), compareFunc);
        printArr(sale, count_month);
        if (count_month % 2 == 0){
            med = (sale[(count_month/2 -1)] + sale[count_month/2])/2;
        }
        else{
            med = sale[count_month/2];
        }
        if (maxMedian < med) maxMedian = med;

        cout << med << endl;
    }
    return maxMedian;
}

int main()
{
    const int NUM_AGENTS = 3;
    //const int NUM_MONTHS = 12;
    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    /*int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544}
    };*/
    int highestSale = highestSales(sales, NUM_AGENTS, NUM_MONTHS);
    cout << "Highest sales = " << highestSale << endl;

    double maxAVG = maxAverage(sales, NUM_AGENTS, NUM_MONTHS);
    cout << "Max average sales = " << maxAVG << endl;

    int maxMed = maxMedian(sales, NUM_AGENTS, NUM_MONTHS);
    cout << "Max median sales = " << maxMed << endl;

    cout << "qsort test " << endl;
    maxMed = maxMedianQsort(sales, NUM_AGENTS, NUM_MONTHS);
    cout << "Max median qsort sales = " << maxMed << endl;

    return 0;
}
