#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> names = {"John", "Bobby", "Dear", "Test1", "Catherine", "Nomi", "Shinta", "Martin", "Abe", "May", "Zeno", "Zack", "Angel"};
    // vector<string> names_sorted = names;
    vector<string> names_sorted(names);

    sort(names_sorted.begin(), names_sorted.end());

    cout << "Unsorted names:" << endl;
    for (const auto& currentName : names){
        cout << currentName << endl;
    }

    cout << "Sorted names:" << endl;

    for (int i = 0; i < names_sorted.size(); ++i){
        cout << names_sorted[i] << endl;
    }

    return 0;
}
