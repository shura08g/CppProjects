#include <iostream>
#include <string.h>

using namespace std;

void exercise1(){
    int const ROW = 4;
    int const COL = ROW * 2;
    for (int i = 0; i < ROW; ++i){
        for (int j = 0; j < COL; ++j){
            if ((j >= i) && (j < COL - i)) cout << "#";
            else cout << " ";
        }
        cout << "\n";
    }
/*
########
 ######
  ####
   ##
*/
}

void exercise2(){
    int const ROW = 8;
    for (int i = 0; i < ROW/2; ++i){
        for (int j = 0; j < ROW; ++j){
            if ((j >= (ROW/2 - i - 1)) && (j <= (ROW/2 + i))) cout << "#";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < ROW/2; ++i){
        for (int j = 0; j < ROW; ++j){
            if ((j >= i) && (j <= ROW - i - 1)) cout << "#";
            else cout << " ";
        }
        cout << "\n";
    }
/*
   ##
  ####
 ######
########
########
 ######
  ####
   ##
*/
}

void exercise3(){
    int const ROW = 8;
    int const COL = ROW * 2 - 2;
    int step = 0;
    for (int i = 0; i < ROW/2; ++i){
        for (int j = 0; j < COL; ++j){
            if (((j >= step) && (j < COL - step)) && ((j <= i + step) || (j >= COL - i - 1 - step))) cout << "#";
            else cout << " ";
        }
        ++step;
        cout << "\n";
    }
    --step;
    for (int i = 0; i < ROW/2; ++i){
        for (int j = 0; j < COL; ++j){
            if (((j >= step) && (j < COL - step)) && ((j < COL/2 - (i*2)) || (j > COL/2 + (i*2) - 1))) cout << "#";
            else cout << " ";
        }
        --step;
        cout << "\n";
    }
/*
#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#            #
*/
}

void exercise6(){
/*
двоичные  числа  и  знаете,  как  преобразовывать
дес€тичные  числа  в  двоичные  и  наоборот,  попробуйте  написать
программу  дл€  выполнени€  таких  преобразований.
*/
    int number, i;
    int result[10];
    int result_str = 0;
    cout << "Enter number: ";
    cin >> number;
    for (i = 0; number > 0; ++i){
        result[i] = number % 2;
        number = number / 2;
    }
    cout << "Binary of the given number = ";
    for (i -= 1; i >= 0; --i){
        result_str += result[i];
        result_str *= 10;
        cout << result[i];
    }
    result_str /= 10;
    cout << endl << result_str << endl;
}

void decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
    // counter for hexadecimal number array
    int i = 0;
    while(n != 0)
    {
        // temporary variable to store remainder
        int temp  = 0;
        // storing remainder in temp variable.
        temp = n % 16;
        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    // printing hexadecimal number array in reverse order
    for(int j = i-1; j >= 0; j--)
        cout << hexaDeciNum[j];
    cout << endl;
}

void exercise9(){
/*
	Ќапишите  программу,  котора€  считывала  бы  строку  текста,  подђ
считыва€  количество  слов  и  вычисл€€  длину  самого  длинного
слова,  наибольшее  количество  гласных  букв  в  слове  и/или  люђ
бую  другую  статистику,  какую  вы  можете  себе  представить.

*/
    char symbol;
    char prev_sym;
    int count_sym = 0;
    int count_word = 0;
    int temp = 0;
    cin.clear(); //
    fflush(stdin);  // очистить буфер cin
    cout << "Enter string: ";
    //symbol = cin.get();
    //cout << int(' ');  // 32 пробел
    while (symbol != 10){
        prev_sym = symbol;
        symbol = cin.get();
        if (symbol == 32){
            if (temp != 0 && prev_sym != 32) ++count_word;
            if (temp > count_sym){
                count_sym = temp;
                temp = 0;
            }
        }
        else ++temp;
        //cout << symbol;
    }
    //cout << "|" << prev_sym << "|" << endl;
    if (temp > count_sym) count_sym = --temp;
    if (prev_sym != 32) ++count_word;
    cout << "\nWords in string: " << count_word << endl;
    cout << "Longest word has: " << count_sym << " symbols." << endl;
}

void exercise9_test(){
    char * symbols;
    int i = 0;
    cin.clear(); //
    fflush(stdin);  // очистить буфер cin
    cout << "Enter string: ";
    symbols[i] = cin.get();
    while (symbols[i] != 10){
        ++i;
        symbols[i] = cin.get();
    }
    for (i -= 1; i >= 0; --i){
        cout << symbols[i];
    }
}

int main()
{
    exercise9_test();
    /*cout << "Exercise #1" << endl;
    cout << "===========" << endl;
    exercise1();
    cout << "===========" << endl;
    cout << "Exercise #2" << endl;
    cout << "===========" << endl;
    exercise2();
    cout << "===========" << endl;
    cout << "Exercise #3" << endl;
    cout << "===========" << endl;
    exercise3();
    cout << "===========" << endl;
    cout << "Exercise #6" << endl;
    cout << "===========" << endl;
    exercise6();
    decToHexa(125);
    cout << "===========" << endl;
    cout << "Exercise #9" << endl;
    cout << "===========" << endl;
    exercise9();*/
    return 0;
}
