/*
в  статистике  мода  набора  значений  представляет  собой  самое  часто  встречающееся
значение.  Напишите  код,  который  обрабатывает  массив  данных  опроса,  в  ходе  кото¬
рого  респонденты  отвечали  на  вопрос  с  помощью  цифры  от  1  до  10,  чтобы  определить
моду  набора  данных.  Для  нашей  цели  можно  выбрать  любую  моду,  если  их  окажется
несколько.

*/
#include <iostream>

using namespace std;

int compareFunc(const void * voidA, const void * voidB){
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}

int main()
{
    int SIZE_SURVEY = 15;
    int SIZE_VAL = 11;
    int survey[SIZE_SURVEY] = {5,2,3,5,7,1,7,1,10,2,6,7,2,7,5};
    int values[SIZE_VAL] = {0};

    // #1
    int mostFrequent = 0;
    int value = 0;
    for (int i = 0; i < SIZE_SURVEY; ++i){
        ++values[survey[i]];
    }
    for (int i = 0; i < SIZE_VAL; ++i){
        cout << values[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE_VAL; ++i){
        if (values[i] > mostFrequent) mostFrequent = values[i];
    }

    for (int i = 0; i < SIZE_VAL; ++i){
        if (values[i] == mostFrequent) value = i;
    }
    cout << "Moda = " << value << " repeats " << mostFrequent << " times" << endl;

    // #2

    int mostFreq;
    int highestFreq = 0;
    int currentFreq = 0;

    qsort(survey, SIZE_SURVEY, sizeof(int), compareFunc);

    for (int i = 0; i < SIZE_SURVEY; ++i){
        ++currentFreq;
        // if (survey[i]) IS LAST OCCURENCE OF A VALUE
        if ((i == SIZE_SURVEY - 1) || (survey[i] != survey[i + 1])){
            if (currentFreq > highestFreq){
                highestFreq = currentFreq;
                mostFreq = survey[i];
            }
            currentFreq = 0;
        }
    }
    for (int i = 0; i < SIZE_SURVEY; ++i){
        cout << survey[i] << " ";
    }

    cout << endl;

    cout << "Moda = " << mostFreq << endl;
    return 0;
}
