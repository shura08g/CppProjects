/*
4.2. —оздайте дл€ нашей динамической строки функцию substring,
котора€ получает три параметра: массив arrayString,  начальную
позицию в числовом формате и количество элементов подстро-
ки, также в числовом формате. ‘ункци€ возвращает указатель
на вновь созданный динамический массив. Ётот строковый мас-
сив содержит символы из первоначальной строки, начина€ с
указанной позиции и указанной длины. ѕервоначальна€ строка
остаетс€ неизменной. “ак что, если изначально строка представ-
л€ла собой abcdefg, позици€ была 3, а длина 4, то нова€ строка
будет содержать cdef.

*/
#include <iostream>

using namespace std;

int length(char *arrayString){
    int count = 0;
    while (arrayString[count] != '\0') count++;
    return count;
}

char *substring(char *arrayString, int position, int count){
    char *new_sub_str = new char[count];
    int i = 0;
    if (length(arrayString) < position){
        cout << "Position biggest then array length." << '\n';
        //throw system_error(EDOM, generic_category(), "Position biggest then array length.");
        new_sub_str[i] = '\0';
        return new_sub_str;
    }
    for (; i < count; ++i){
        if (arrayString[position - 1 + i] == '\0'){
            new_sub_str[i] = '\0';
            return new_sub_str;
        }
        new_sub_str[i] = arrayString[position - 1 + i];
        //cout << arrayString[position - 1 + i] << endl;
        //cout << new_sub_str[i] << endl;
    }
    new_sub_str[i] = '\0';
    return new_sub_str;
}

int main()
{
    char arrayString[] = {'a','b','c','d','e','f','g','\0'};
    cout << arrayString << endl;
    char *sub_str = substring(arrayString, 3, 4);
    cout << sub_str << endl;
    sub_str = substring(arrayString, 3, 9);
    cout << sub_str << endl;
    sub_str = substring(arrayString, 9, 3);
    cout << sub_str << endl;
    sub_str = substring(arrayString, 1, 5);
    cout << sub_str << endl;
    return 0;
}
