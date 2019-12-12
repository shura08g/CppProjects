/*
4.4. �������� ���������� ����� ������ ����� �������, ����� ���-
���� ������� location[0] �������� ������ ������� (�, �������-
�������, ������� ������� location[l] �������� ������ �����-
����� � ������� ������) � ��� �� �������� �� ������������
������� ����������� ����. ���������� ������ �� ���� ����-
��� append, concatenate � charactertAt, ���������, ���������
��� ��������, ������������ ����������� ���������� � ���-
���� �������. ��� ��� �� ������ �� ����� ������������ �����-
����� � ������� ����������� �����, ������� ���������� ���
������ �� ����������� ������� ������, �� ��� ���������� ��-
������ ���� ����������� ������� output, ������� � �������
����� ��������� ��������� �������� � ������� �� ����� ���-
����.

*/
#include <iostream>

using namespace std;
typedef char * arrayString;

void output(arrayString &s){
    for (int i = 1; i < s[0]; ++i) cout << s[i];
    cout << '\n';
}

char characterAt(arrayString &s, int index){
    return s[index];
}

void append(arrayString &s, char ch){
    int oldLength = s[0];
    arrayString newS = new char[oldLength + 1];
    newS[0] = oldLength + 1;
    for (int i = 1; i < oldLength; ++i){
        newS[i] = s[i];
    }
    newS[oldLength] = ch;
    delete[] s;
    s = newS;
}

void concatenate(arrayString &s1, arrayString s2){
    int newLen = s1[0] + s2[0];
    arrayString newS = new char[newLen];
    newS[0] = newLen;
    for (int index = 1; index < s1[0]; ++index){
        newS[index] = s1[index];
    }
    for (int index = 1; index < s2[0]; ++index){
        newS[s1[0] + index - 1] = s2[index];
    }
    delete[] s1;
    s1 = newS;
}

int main()
{
    char str[] = {12, 'H','e','l','l','o',' ','w','o','r','l','d'};
    char str_add[] = {13, 'H','e','l','l','o',' ','a','g','a','i','n','.'};
    arrayString pstr = str;

    output(pstr);

    char ch = characterAt(pstr, 7);
    cout << ch << '\n';

    append(pstr, '!');
    output(pstr);

    append(pstr, ' ');
    concatenate(pstr, str_add);
    output(pstr);
    return 0;
}
