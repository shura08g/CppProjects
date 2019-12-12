#include <iostream>
#include <string.h>
/*
Некое  сообщение  было  закодировано  в  виде  текстового  потока,  который  должен  быть
прочитан  символ  за  символом.  Поток  содержит  последовательность  целых  чисел,  раз¬
деленных  запятыми.  Каждое  из  этих  чисел  ~  положительное  целое,  которое  может
быть  представлено  типом  int  языка  С++.  Однако  то,  какой  символ,  представлен  тем
или  иным  целым  числом,  зависит  оттекущего  режимадекодирования.  Всего  существу¬
ет  три  режима:  верхний  регистр,  нижний  регистр  и  пунктуация.
 В  режиме  верхнего  регистра  каждое  целое  число  представляет  прописную  букву:  целое
число,  взятое  по  модулю  27,  означает  букву  алфавита  (где  1  =  А  и  так  далее).  Таким
образом,  введенное  значение  143  в  режиме  верхнего  регистра  будет  означать  букву
Н,  так  как  143  по  модулю  27  равняется  8,  а  Н  —  восьмая  буква  латинского  алфавита.
Режим  нижнего  регистра  работает  аналогичным  образом,  но  со  строчными  буквами:  оста¬
ток  от  деления  целого  числа  на  27  представляет  строчную  букву  (где  1  =  а  и  так  далее).
Таким  образом,  введенное  значение  56  в  режиме  верхнего  регистра  будет  означать  букву
b,  так  как  56  по  модулю  27  равняется  2,  а  b  —  вторая  буква  латинского  алфавита.
 В  режиме  пунктуации  целое  число  уже  берется  по  модулю  9  и  согласно  интерпретации
в  приведенной  ниже  табл.  2.3.  Таким  образом,  19  по  модулю  9  будет  означать  вос¬
клицательный  знак,  так  как  19  по  модулю  9  равняется  1.
 В  начале  каждого  сообщения  устанавливается  режим  декодирования  верхнего  реги¬
стра.  Каждый  раз,  когда  результат  операции  деления  по  модулю  (27  или  9,  в  зависи¬
мости  от  режима)  равен  0,  происходит  переключение  режима  декодирования.  Если  в
текущий  момент  установлен  режим  декодирования  верхнего  регистра,  то  происходит
переключение  на  режим  декодирования  нижнего  регистра.  Если  же  в  текущий  момент
установлен  режим  декодирования  нижнего  регистра,  то  происходит  переключение  на
режим  декодирования  пунктуации.  Если  установлен  режим  декодирования  пунктуа¬
ции,  то  происходит  переключение  на  режим  декодирования  верхнего  регистра.

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
