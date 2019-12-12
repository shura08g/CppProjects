/*
3.4.	Вот  вариация  задания  с  массивом  значений  const.  Напишите
программу  для  шифрования  методом  подстановки.  При  таком
шифровании  все  сообщения  состоят  из  прописных  букв  и  зна¬
ков  препинания.  Исходное  сообщение  называется  открытым
текстом,  зашифрованный  текст  создается  путем  замены  каждой
буквы  другой  буквой  (например,  каждая  буква  С  может  стать  бук¬
вой  X).  Для  этой  задачи  жестко  закодируйте  массив  const  из  26
элементов  char  для  шифрования  и  сделайте  так,  чтобы  ваша  про¬
грамма  прочитывала  открытый  текст  и  выводила  эквивалент  со¬
общения  в  виде  зашифрованного  текста.

3.5. 	Сделайте  так,  чтобы  предыдущая  программа  преобразовывала
зашифрованный  текст  обратно  в  открытый  текст  для  проверки
корректности  кодирования  и  декодирования.

*/

#include <iostream>
#include <clocale>

using namespace std;

const char ALPHABET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' ,'J',
                         'K', 'L' ,'M' ,'N' ,'O', 'P' ,'Q', 'R', 'S', 'T',
                         'U', 'V', 'W', 'X', 'Y', 'Z'};
const int OFFSET = 12;

const size_t SIZE_ALPH = sizeof(ALPHABET)/sizeof(char);

char coding_char(char ch){
    char temp;
    //if (ch <= 'Z' - OFFSET) temp = ch + OFFSET;
    if (ch <= ALPHABET[SIZE_ALPH - OFFSET - 1]) temp = ch + OFFSET;
    else temp = ch + OFFSET - SIZE_ALPH;
    return temp;
}

char decoding_char(char ch){
    char temp;
    //if (ch >= 'A' + OFFSET) temp = ch - OFFSET;
    if (ch >= ALPHABET[OFFSET]) temp = ch - OFFSET;
    else temp = ch + SIZE_ALPH - OFFSET;
    //cout << int(temp);
    return temp;
}

bool is_capital_char(char ch){
    if (ch >= 'A' && ch <= 'Z') return true;
    else return false;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "Characters count: "<< SIZE_ALPH << endl;
    cout << "Enter the message in capital letters:" << endl;

    char input_cahrs[100];
    int index = 0;

    char symb = cin.get();
    while (symb != 10){
        if (is_capital_char(symb)){
            symb = coding_char(symb);
        }
        input_cahrs[index++] = symb;
        cout << symb;
        symb = cin.get();
    }

    cout << endl << "Decoding:" << endl;
    char decode_symb;
    for (int i = 0; i < index; ++i){
        if (is_capital_char(input_cahrs[i])) decode_symb = decoding_char(input_cahrs[i]);
        else decode_symb = input_cahrs[i];
        cout << decode_symb;
    }

    return 0;
}
