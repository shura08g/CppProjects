/*
3.4.	���  ��������  �������  �  ��������  ��������  const.  ��������
���������  ���  ����������  �������  �����������.  ���  �����
����������  ���  ���������  �������  ��  ���������  ����  �  ���
���  ����������.  ��������  ���������  ����������  ��������
�������,  �������������  �����  ���������  �����  ������  ������
�����  ������  ������  (��������,  ������  �����  �  �����  �����  ���
���  X).  ���  ����  ������  ������  �����������  ������  const  ��  26
���������  char  ���  ����������  �  ��������  ���,  �����  ����  ���
������  �����������  ��������  �����  �  ��������  ����������  ��
�������  �  ����  ��������������  ������.

3.5. 	��������  ���,  �����  ����������  ���������  ���������������
�������������  �����  �������  �  ��������  �����  ���  ��������
������������  �����������  �  �������������.

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
