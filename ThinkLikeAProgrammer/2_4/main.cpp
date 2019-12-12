#include <iostream>
#include <string.h>
/*
�����  ���������  ����  ������������  �  ����  ����������  ������,  �������  ������  ����
��������  ������  ��  ��������.  �����  ��������  ������������������  �����  �����,  ���
��������  ��������.  ������  ��  ����  �����  ~  �������������  �����,  �������  �����
����  ������������  �����  int  �����  �++.  ������  ��,  �����  ������,  �����������  ���
���  ����  �����  ������,  �������  ����������  �������������������.  �����  ��������
��  ���  ������:  �������  �������,  ������  �������  �  ����������.
 �  ������  ��������  ��������  ������  �����  �����  ������������  ���������  �����:  �����
�����,  ������  ��  ������  27,  ��������  �����  ��������  (���  1  =  �  �  ���  �����).  �����
�������,  ���������  ��������  143  �  ������  ��������  ��������  �����  ��������  �����
�,  ���  ���  143  ��  ������  27  ���������  8,  �  �  �  �������  �����  ����������  ��������.
�����  �������  ��������  ��������  �����������  �������,  ��  ��  ���������  �������:  ����
���  ��  �������  ������  �����  ��  27  ������������  ��������  �����  (���  1  =  �  �  ���  �����).
�����  �������,  ���������  ��������  56  �  ������  ��������  ��������  �����  ��������  �����
b,  ���  ���  56  ��  ������  27  ���������  2,  �  b  �  ������  �����  ����������  ��������.
 �  ������  ����������  �����  �����  ���  �������  ��  ������  9  �  ��������  �������������
�  �����������  ����  ����.  2.3.  �����  �������,  19  ��  ������  9  �����  ��������  ���
������������  ����,  ���  ���  19  ��  ������  9  ���������  1.
 �  ������  �������  ���������  ���������������  �����  �������������  ��������  ����
����.  ������  ���,  �����  ���������  ��������  �������  ��  ������  (27  ���  9,  �  ������
�����  ��  ������)  �����  0,  ����������  ������������  ������  �������������.  ����  �
�������  ������  ����������  �����  �������������  ��������  ��������,  ��  ����������
������������  ��  �����  �������������  �������  ��������.  ����  ��  �  �������  ������
����������  �����  �������������  �������  ��������,  ��  ����������  ������������  ��
�����  �������������  ����������.  ����  ����������  �����  �������������  �������
���,  ��  ����������  ������������  ��  �����  �������������  ��������  ��������.

*/
using namespace std;

enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};

void testTwoCharToDigit(){
    cout << "Enter a two-digit number: ";
    char digitChar = cin.get();
    int overallNumber = (digitChar - '0') * 10;
    //int overallNumber = digitChar * 10;  // error: use cod of symbol but not value
    digitChar = cin.get();
    overallNumber += (digitChar - '0');
    //overallNumber += digitChar;   // error: use cod of symbol but not value
    cout << "That number as an integer: " << overallNumber << endl;
}

void testIntToChar(){
    cout << "Enter a number 1-26: ";
    int number;
    cin >> number;
    char outputCharacter;
    outputCharacter = number + 'A' - 1;  // -1 because start 1 - 26 but not 0
    cout << "Equivalent symbol: " << outputCharacter << endl;

}

void testSwitchMode(){
    int number;
    modeType mode = UPPERCASE;
    cout << "Enter some numbers ending with -1: ";
    do{
        cin >> number;
        cout << "Number read: " << number;
        switch (mode){
        case UPPERCASE:
            number = number % 27;
            cout << ". Modulo 27: " << number << ". ";
            if (number == 0){
                cout << "Switch to LOWERCASE";
                mode = LOWERCASE;
            }
            break;
        case LOWERCASE:
            number = number % 27;
            cout << ". Modulo 27: " << number << ". ";
            if (number == 0){
                cout << "Switch to PUNCTUATION";
                mode = PUNCTUATION;
            }
            break;
        case PUNCTUATION:
            number = number % 9;
            cout << ". Modulo 9: " << number << ". ";
            if (number == 0){
                cout << "Switch to UPPERCASE";
                mode = UPPERCASE;
            }
            break;
        }
        cout << endl;
    }while (number != -1);
}

int toIntSequentionDigit(){
    cout << "Enter a number: ";
    char digitChar = cin.get();
    int overallNumber = 0;
    while ((digitChar != 10) && (digitChar != ',')){
        overallNumber += (digitChar - '0');
        digitChar = cin.get();
        if (digitChar != 10) overallNumber *= 10;
    }
    return overallNumber;
}

char intToChar(int number, modeType mode){
    char outputCharacter;
    if (mode == UPPERCASE) outputCharacter = number + 'A' - 1;
    if (mode == LOWERCASE) outputCharacter = number + 'a' - 1;
    if (mode == PUNCTUATION){
        switch (number) {
        case 1: outputCharacter = '!'; break;
        case 2: outputCharacter = '?'; break;
        case 3: outputCharacter = ','; break;
        case 4: outputCharacter = '.'; break;
        case 5: outputCharacter = ' '; break;
        case 6: outputCharacter = ';'; break;
        case 7: outputCharacter = '"'; break;
        case 8: outputCharacter = '\''; break;
        default: outputCharacter = '@'; break;
        }
    }
    return outputCharacter;
}

int main()
{
    //testTwoCharToDigit();
    /*int test = toIntSequentionDigit();
    cout << test << endl;*/
    //testIntToChar();
    /*char testUpper = intToChar(1, UPPERCASE);
    char testLower = intToChar(1, LOWERCASE);
    char testPunctutuin = intToChar(1, PUNCTUATION);
    cout << testUpper << testPunctutuin << testLower << endl;*/
    //testSwitchMode();
    char outputCharacter;
    modeType mode = UPPERCASE;
    char digitChar;
    do{
        digitChar = cin.get();
        int number = (digitChar - '0');
        digitChar = cin.get();
        while ((digitChar != 10) && (digitChar != ',')){
            number = number * 10 + (digitChar - '0');
            digitChar = cin.get();
        }
        switch (mode){
        case UPPERCASE:
            number = number % 27;
            outputCharacter = number + 'A' - 1;
            if (number == 0){
                mode = LOWERCASE;
                continue;
            }
            break;
        case LOWERCASE:
            number = number % 27;
            outputCharacter = number + 'a' - 1;
            if (number == 0){
                mode = PUNCTUATION;
                continue;
            }
            break;
        case PUNCTUATION:
            number = number % 9;
            switch (number) {
            case 1: outputCharacter = '!'; break;
            case 2: outputCharacter = '?'; break;
            case 3: outputCharacter = ','; break;
            case 4: outputCharacter = '.'; break;
            case 5: outputCharacter = ' '; break;
            case 6: outputCharacter = ';'; break;
            case 7: outputCharacter = '"'; break;
            case 8: outputCharacter = '\''; break;
            default: outputCharacter = '@'; break;
            }
            if  (number == 0){
                mode = UPPERCASE;
                continue;
            }
            break;
        }
        cout << outputCharacter;
    }while (digitChar != 10);
    cout << endl;
    return 0;
}
