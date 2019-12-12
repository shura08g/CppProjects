#include <iostream>

using namespace std;

int revNumber(int number){
    int remainder, reverseNum = 0;
    while (number != 0){
        remainder = number % 10;
        reverseNum = reverseNum * 10 + remainder;
        //cout << number << " " << remainder << " " << reverseNum << endl;
        number /= 10;
    }
    return reverseNum;
}

bool is_palindrome(int num){
    if (num == revNumber(num)) return true;
    return false;
}

int main(){
    int number, revNum;
    int arrInt[5] = {4567, 657, 656, 789987, 156454};

    for (int i = 0; i < 5; i++){
        if (is_palindrome(arrInt[i])) cout << number << " is palindrome" << endl;
        cout << revNumber(arrInt[i]) << endl;
    }

    cout << "Imput number" << endl;
    cin >> number;
    if (is_palindrome(number)) cout << number << " is palindrome" << endl;
    revNum = revNumber(number);
    cout << revNum << endl;

    return 0;
}
