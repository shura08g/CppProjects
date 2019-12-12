#include <iostream>
/*
    Задача:  операции  со  строками  переменной  длины
    Напишите,  используя  кучу,  реализацию  трех  основных  функций  строковых  переменных:
    append  Функция  получает  в  качестве  параметров  строку  и  символ  и  добавляет
символ  к  конец  строки.
    concatenate  Функция  получает  две  строки  и  добавляет  символы  второй  строки
к  первой.
    characterAt  Функция  получает  строку  и  число  и  возвращает  символ,  находящий¬
ся  на  соответствующей  числу  позиции  (нумерация  символов  начинается  с  нуля).
    При  написании  кода  учитывайте,  что  функция  characterAt  будет  применяться  часто,  в
то  время  как  две  другие  функции  —  достаточно  редко.  Частота  вызовов  отразит  отно¬
сительную  эффективность  операций.

*/

using namespace std;
typedef char *arrayString;

int length(arrayString s){
    int count = 0;
    while (s[count] != '\0') count++;
    return count;
}

void printArrCh(arrayString s){
    while (*s != '\0') cout << *s++;
    cout << endl;
}

char characterAt(arrayString s, int index){
    return s[index];
}

void append(arrayString s, char ch){
    int i = 0;
    while (s[i] != '\0') ++i;
    s[i++] = ch;
    s[i] = '\0';
}

void concatenate(arrayString s1, arrayString s2){
    int i = 0;
    int j = 0;
    while (s1[i] != '\0') ++i;
    while (s2[j] != '\0') s1[i++] = s2[j++];
    s1[i] = '\0';
}

void appendNew(arrayString &s, char ch){
    int oldLength = length(s);
    arrayString newS = new char[oldLength + 2];
    for (int i = 0; i < oldLength; ++i){
        newS[i] = s[i];
    }
    newS[oldLength] = ch;
    newS[oldLength + 1] = '\0';
    delete[] s;
    s = newS;
}

void concatenateNew(arrayString &s1, arrayString s2){
    int len_s1 = length(s1);
    int len_s2 = length(s2);
    int newLen = len_s1 + len_s2;
    arrayString newS = new char[newLen + 1];
    for (int index = 0; index < len_s1; ++index){
        newS[index] = s1[index];
    }
    for (int index = 0; index < len_s2; ++index){
        newS[len_s1 + index] = s2[index];
    }
    newS[newLen] = '\0';
    delete[] s1;
    s1 = newS;
}

void printArr(arrayString s, int size){
    for (int i = 0; i < size; ++i) cout << s[i];
    cout << endl;
}


int main()
{
    char str[100] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
    char str_add[] = {'\n','H','e','l','l','0',' ','a','g','a','i','n','.','\0'};
    //int sizeArr = sizeof(str)/sizeof(str[0]);
    arrayString pstr = str;
    arrayString pstr_add = str_add;
    //printArr(pstr, sizeArr);
    printArrCh(pstr);
    cout << pstr_add << endl;  //так как в конце 0 мы можем передать массив прямо в поток вывода

    char ch;
    ch = characterAt(pstr, 4);
    cout << ch << endl;

    append(pstr, '!');
    cout << "append Test add !:" << endl;
    cout << pstr << endl;

    concatenate(pstr, pstr_add);
    cout << "concatenate Test:" << endl;
    cout << pstr << endl;

    ch = characterAt(pstr, 11);
    cout << ch << endl;

    arrayString sTest = new char[5];
    sTest[0] = 't';
    sTest[1] = 'e';
    sTest[2] = 's';
    sTest[3] = 't';
    sTest[4] = '\0';

    arrayString sTest2 = new char[1];
    sTest2[0] = '\0';

    ch = characterAt(sTest, 2);
    cout << ch << endl;

    appendNew(sTest, '!');
    cout << "appendNew Test:" << endl;
    cout << sTest << endl;

    concatenateNew(sTest, pstr_add);
    cout << "concatenateNew Test:" << endl;
    cout << sTest << endl;

    concatenateNew(sTest2, sTest);
    cout << "concatenateNew Test with \\0:" << endl;
    cout << sTest2 << endl;
    return 0;
}
