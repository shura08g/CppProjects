#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int id;
    string name;
    double money;
  /*  ofstream outFile("players.txt");

    cout << "Enter ID, name, money for player" << '\n';
    cout << "Enter Ctr+Z for quit" << '\n';

    while(cin >> id >> name >> money){
        outFile << id << ' ' << name << ' ' << money << '\n';
    }

    outFile.close();*/

    ifstream inFile("players.txt");

    cout << "ID, name, money:" << '\n';
    while (inFile >> id >> name >> money){
        cout << id << ", " << name << ", " << money << '\n';
    }
    inFile.close();
    return 0;
}
