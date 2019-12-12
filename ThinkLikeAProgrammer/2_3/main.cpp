#include <iostream>
/*
Формула  Луна  —  это  широко  используемая  система  проверки  идентификационных
номеров.  Используя  исходное  число,  увеличить  вдвое  значение  каждой  цифры.  Затем
сложить  значения  отдельных  цифр  (если  удвоенное  значение  имеетдве  цифры,  то  сло¬
жить  эти  цифры  по  отдельности).  Идентификационный  номер  проходит  проверку,  если
получившаяся  сумма  делится  на  10.
 Напишите  программу,  которая  принимала  бы  идентификационный  номер  произволь¬
ной  длины  и  определяла  бы  по  формуле  Луна,  действителен  ли  номер.  Программа
должна  обрабатывать  каждый  символ  перед  чтением  следующего.

*/

using namespace std;

int doubleDigit(int digit){
    int doubleDig = digit * 2;
    int sum;
    if (doubleDig >= 10) sum = 1 + doubleDig % 10;
    else sum = doubleDig;
    return sum;
}

int symbol_to_digit(char symb){
    int digit;
    digit = symb - '0';  // '0' - cod 48
    return digit;
}

int main()
{
    char symbol;
    int checksum = 0;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;
    cout << "Enter a number: ";
    symbol = cin.get();
    /*while (true){
        cout << int(symbol) << " "; // <ENTER> - 10
        symbol = cin.get();
        ++position;
    }*/
    while (symbol != 10){  // <ENTER> - 10
        if (position % 2 == 0){
            oddLengthChecksum += doubleDigit(symbol_to_digit(symbol));  // for odd
            evenLengthChecksum += symbol_to_digit(symbol);  // for even
        }
        else{
            oddLengthChecksum += symbol_to_digit(symbol); // for odd
            evenLengthChecksum += doubleDigit(symbol_to_digit(symbol)); // for even
        }
        symbol = cin.get();
        ++position;
    }
    --position;  // without <ENTER>
    if (position % 2 == 0) checksum = evenLengthChecksum;
    else checksum = oddLengthChecksum;
    cout << "Checksum = " << checksum << endl;
    if (checksum % 10 == 0 && checksum != 0) cout << "Checksum is divisible by 10. Valid.\n";
    else cout << "Checksum is not divisible by 10. Invalid.\n";
    //1762483
    //154849
    return 0;
}
