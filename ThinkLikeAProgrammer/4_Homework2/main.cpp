/*
4.2. �������� ��� ����� ������������ ������ ������� substring,
������� �������� ��� ���������: ������ arrayString,  ���������
������� � �������� ������� � ���������� ��������� �������-
��, ����� � �������� �������. ������� ���������� ���������
�� ����� ��������� ������������ ������. ���� ��������� ���-
��� �������� ������� �� �������������� ������, ������� �
��������� ������� � ��������� �����. �������������� ������
�������� ����������. ��� ���, ���� ���������� ������ ��������-
���� ����� abcdefg, ������� ���� 3, � ����� 4, �� ����� ������
����� ��������� cdef.

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
