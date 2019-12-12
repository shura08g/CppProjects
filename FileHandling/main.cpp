#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    char arr[100];
    cout << "Enter your name and age:" << endl;
    cin.getline(arr, 100);

    ofstream myfile("xyz.txt", std::fstream::out | std::fstream::app);
    if (myfile) cout << "File open." << endl;
    else cout << "File can't open." << endl;
    // myfile.open("xyz.txt", std::fstream::in | std::fstream::out | std::fstream::app);  // for append
    myfile << arr;
    myfile << endl;
    cout << "File write operation performed successfully." << endl;
    if (myfile.is_open()){
        myfile.close();
        cout << "File closed." << endl;
    }

    string temp_st;
    string all_str;
    vector<string> str_v;
    cout << "Reading from file started..." << endl;
    ifstream infile("xyz.txt");
    while (getline(infile, temp_st)){
        temp_st += "\n";
        all_str += temp_st;
        str_v.push_back(temp_st);
        //cout << temp_st;
    }
    if (infile.is_open()){
        infile.close();
        cout << "File closed." << endl;
    }
    //cout << all_str;
    for (unsigned int i = 0; i < str_v.size(); i++)
        cout << str_v[i];
}
