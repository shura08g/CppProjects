#include <iostream>
#include <clocale>

using namespace std;

void reverse_string(const string &str);

int main()
{
    setlocale(LC_CTYPE, "rus");
    string str;
    cout << "¬ведите строку: " << endl;
    getline(cin, str);
    reverse_string(str);
    return 0;
}

void reverse_string(const string &str){
    size_t numOfChars = str.size();
    if (numOfChars == 1) cout << str << endl;
    else{
        cout << str[numOfChars - 1];
        reverse_string(str.substr(0, numOfChars - 1));
    }
}
