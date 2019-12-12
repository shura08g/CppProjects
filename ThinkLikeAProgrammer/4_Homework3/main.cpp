/*
4.3. �������� ��� ����� ������������ ������ ������� replaceString,
������� �������� ��� ��������� � ������� arrayString:
source, target � replaceText. ������� �������� ������ ����-
����� ������ target � ������ source �� ������ replaceText. ��-
������, ���� source ��������� �� ������, ���������� abcdabee,
target ��������� �� ab, � replaceText � �� xyz, �� ����� �������-
��� ������ ������� source ����� ��������� �� ������, �������-
��� xyzcdxyzee.
*/

#include <iostream>

using namespace std;

typedef char * arrayString;

int length(char *arrayString){
    int count = 0;
    while (arrayString[count] != '\0') count++;
    return count;
}

bool containSubString(arrayString source, arrayString target, int position){
    int lenTarget = length(target);
    for (int k = position, j = 0; k < lenTarget + position; ++k, ++j){
        if (source[k] != target[j]){
            return false;
        }
    }
    return true;
}

void replaceString(arrayString &source, arrayString target, arrayString replaceText){
    int lenSource = length(source);
    int lenTarget = length(target);
    int lenRepl = length(replaceText);
    arrayString newStr = new char[lenSource * 2];
    int iNewS = 0;
    for (int iSource = 0; iSource < lenSource; ++iSource){
        if (source[iSource] == target[0]){
            if (containSubString(source, target, iSource)){
                for (int i = 0; i < lenRepl; ++i){
                    newStr[iNewS] = replaceText[i];
                    ++iNewS;
                }
                iSource += lenTarget - 1;
            }
            else {
                newStr[iNewS] = source[iSource];
                ++iNewS;
            }
        }
        else{
            newStr[iNewS] = source[iSource];
            ++iNewS;
        }
    }
    newStr[iNewS] = '\0';
    delete[] source;
    source = newStr;
}

int main()
{
    char arr[] = {'a','b','c','d','a','b','e','e','\0'};
    char target[] = {'a','b','\0'};
    char replaceText[] = {'x','y','z','\0'};
    arrayString source = arr;
    cout << source << '\n';

    replaceString(source, target, replaceText);
    cout << source << '\n';
    return 0;
}
