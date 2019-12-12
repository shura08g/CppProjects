/*
������: ������������ ��� ���� � "��������"
 �������� ���������, ������� ����� ������� 1 � ��������� ������ ����
��������� (�� ���� �� ����� ���� ��� �� ����� �������� �����������,
����� ������ ����������� ���������� ������������ �������). ����� 2 �����
�������� ������� ��������� ����, �������� ����� �����, ������� ���������
�������, � ����� ���������� ������������ �������, ������� �������� �
���������.
 ������ ����������� � ���, ��� ��������� ����� ����������. ������ ����
����� �������� ����� � ������ ����, ��������� ����� �������� ������
����� ���, ���, ����� ����� 2 ���������, ��������� ��������������,
��������������� ���� ����������, ��������������� ������ 2. ���������
��������� ����� ������ ����������� � ��������������� �� ����������, �
����������� ��������� ����� ������ �� ����� ��������� � ���� �����. �����
���� ����������. ����� 1 (���������) ������� ������ 2 �����, ������� ����
�������. ������� ����� 2 ������� �� ������ ��������, ��� ���� ���
����������; ������ ����������� �������� ��� ������ 2 ������.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;
#include <cstring>
#include <clocale>

list<string> readWordFile(const char * filename){
    list<string> wordList;
    ifstream wordFile(filename, ios::in);
    if (!wordFile){
        cout << "File open failed. \n";
        return wordList;
    }
    char currentWord[30];
    while (wordFile >> currentWord){
        if (strchr(currentWord, '\'') == 0){  // �������� �� ���������
            string temp(currentWord);
            wordList.push_back(temp);
        }
    }
    return wordList;
}

void displayList(const list<string> &wordList){
    /*for (auto &w: wordList){
        cout << w << '\n';
    }*/
    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while (iter != wordList.end()){
        //cout << *iter << '\n';
        count++;
        cout << count << ' ' << iter->c_str() << '\n';
        iter++;
    }
}

int countWordsWithoutLetter(const list<string> &wordList, char letter){
    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->find(letter) == string::npos){  // string::npos ���� ������ �� ������
            count++;
        }
        iter++;
    }
    return count;
}

void removeWordsOfWrongLength(list<string> &wordList, unsigned int acceptableLength){
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->length() != acceptableLength){
            iter = wordList.erase(iter);
        }
        else{
            iter++;
        }
    }
}

void removeWordsWithoutLetters(list<string> &wordList, char requiredLetter){
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->find(requiredLetter) == string::npos){
            iter = wordList.erase(iter);
        }
        else{
            iter++;
        }
    }
}

void removeWordsWithLetters(list<string> &wordList, char forbiddenLetter){
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->find(forbiddenLetter) != string::npos){
            iter = wordList.erase(iter);
        }
        else{
            iter++;
        }
    }
}

bool numberInPattern(const list<int> &pattern, int number){
    list<int>::const_iterator iter;
    iter = pattern.begin();
    while (iter != pattern.end()){
        if (*iter == number){
            return true;
        }
        iter++;
    }
    return false;
}

bool matchesPattern(string word, char letter, list<int> pattern){
    for (unsigned int i = 0; i < word.length(); i++){
        if (word[i] == letter){
            if (!numberInPattern(pattern, i)){
                return false;
            }
        }
        else{
            if (numberInPattern(pattern, i)){
                return false;
            }
        }
    }
    return true;
}

void mostFreqPatternByLetter(list<string> wordList, char letter,
                             list<int> &maxPattern, int &maxPatternCount){
        removeWordsWithoutLetters(wordList, letter);
        list<string>::iterator iter;
        maxPatternCount = 0;
        while (wordList.size() > 0){
            iter = wordList.begin();
            list<int> currentPattern;
            for (unsigned int i = 0; i < iter->length(); i ++){
                if ((*iter)[i] == letter){
                    currentPattern.push_back(i);
                }
            }
            int currentPatternCount = 1;
            iter = wordList.erase(iter);
            while (iter != wordList.end()){
                if (matchesPattern(*iter, letter, currentPattern)){
                    currentPatternCount++;
                    iter = wordList.erase(iter);
                }
                else{
                    iter++;
                }
            }
            if (currentPatternCount > maxPatternCount){
                maxPatternCount = currentPatternCount;
                maxPattern = currentPattern;
            }
            currentPattern.clear();
        }
    }

void displayGuessedLetters(bool letters[32]){
    cout << "��������� �����: ";
    for (int i = 0; i < 32; i++){
        if (letters[i]){
            cout << (char)('�' + i) << " ";
        }
    }
    cout << '\n';
}

void fillRevealedWord(char* revWord, int len, char symbol){
    for (int i = 0; i < len; i++){
        revWord[i] = symbol;
    }
    /*for (int i = 0; i < len; i++){
        cout << revWord[i];
    }*/
}

void fillquessedLetters(bool* queLetter, int len, bool flag){
    for (int i = 0; i < len; i++){
        queLetter[i] = flag;
    }
    /*for (int i = 0; i < len; i++){
        cout << i << " " << queLetter[i] << '\n';
    }*/
}

int main()
{
    std::setlocale(LC_CTYPE, "rus");
    list<string> wordList = readWordFile("words.txt");
    const int wordLength = 8;
    const int maxMisses = 9;
    const int letterInAlphabet = 32;
    int misses = 0;
    int discoveredLettersCount = 0;
    /*displayList(wordList);
    int count = countWordsWithoutLetter(wordList, '0');
    removeWordsOfWrongLength(wordList, 10);
    removeWordsWithoutLetters(wordList, '�');
    displayList(wordList);
    */
    /*int count = 1;
    for (int i = 0; i < 26; i++){
        cout << count << ": "<< (char)('a' + i) << " " << 'a' + i << '\n';
    count++;
    }*/
    /*cout << (char)-72;  //�
    cout << (char)-32;  //�
    cout << (char)-31;  //�
    cout << (char)-2;  //�
    cout << (char)-1;  //�*/
    removeWordsWithLetters(wordList, '�');  // ������� �� ������ ����� � ������ "�"
    removeWordsOfWrongLength(wordList, wordLength);
    char revealedWord[wordLength + 1];
    fillRevealedWord(revealedWord, wordLength, '*'); //********
    bool guessedLetter[letterInAlphabet];
    fillquessedLetters(guessedLetter, letterInAlphabet, false);
    char nextLetter;
    /*for (int i = 0; i < letterInAlphabet; i++){
        cout << i << " " << guessedLetter[i] << '\n';
    }*/
    cout << "�������� �����: " << revealedWord << '\n';
    while (discoveredLettersCount < wordLength && misses < maxMisses){
        cout << "�������� �����:";
        cin >> nextLetter;
        if (nextLetter >= '�' || nextLetter <= '�'){
            guessedLetter[nextLetter + 96] = true;
        }
        if (nextLetter >= '�' || nextLetter <= '�'){
            guessedLetter[nextLetter + 48] = true;
        }
        int missingCount = countWordsWithoutLetter(wordList, nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        mostFreqPatternByLetter(wordList, nextLetter, nextPattern, nextPatternCount);
        if (missingCount > nextPatternCount){
            removeWordsWithLetters(wordList, nextLetter);
            misses++;
        }
        else{
            list<int>::iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()){
                discoveredLettersCount++;
                revealedWord[*iter] = nextLetter;
                iter++;
            }
            // !!! wordList = reduceByPattern(wordList, nextLetter, nextPattern);
        }
        cout << "�������� �����: " << revealedWord << '\n';
        displayGuessedLetters(guessedLetter);
    }
    if (misses == maxMisses){
            cout << "�� ���������. ��������� ����� ����: '";
            cout << (wordList.cbegin())->c_str() << "'.\n";
        }
        else{
            cout << "�� ��������. ��������� ����� ����: '" << revealedWord << "'.\n";
        }

    return 0;
}
