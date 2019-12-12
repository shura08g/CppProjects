#include <iostream>

using namespace std;

int main()
{
    int const SIZE_TRIANGLE = 5;
    cout << "------------1-----------\n";
    for (int row = 0; row < SIZE_TRIANGLE; ++row){
        for (int col = 0; col < SIZE_TRIANGLE - row; ++col){
            cout << "#";
        }
        cout << "\n";
    }

    cout << "------------2-----------\n";
    int const SIZE_ROMB = 7;
    int max_elem = SIZE_ROMB / 2;
    for (int row = 0; row < SIZE_ROMB; ++row){
        for (int col = 0; col <= max_elem - abs(max_elem - row); ++col){
            cout << "#";
        }
        cout << "\n";
    }
    if (SIZE_ROMB % 2 == 0) cout << "#\n";

    cout << "------------3-----------\n";
    int num;
    int contr_sum = 0;
    int const SYM_COUNT = 7;
    cout << "Enter number:\n";
    for (int i = 1; i <= SYM_COUNT; ++i){
        cin >> num;
        if (i % 2 == 0){
            num *= 2;
            if (num >= 10) num = 1 + num % 10;
            contr_sum += num;
        }
        else contr_sum += num;
    }
    //1762483
    cout << "Control sum = " << contr_sum << endl;
    if (contr_sum % 10 == 0) cout << "Entered number valid\n";
    else cout << "Entered number incorrect\n";
    return 0;
}
