#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename = "test.txt";
    ofstream fout(filename);

    cout << "Write test..." << endl;
    if (!fout){
        cout << "Can't open file" << endl;
        return 1;
    }

    fout << "- TEST -" << endl;
    fout << "--------" << endl;
    fout << "-  OK  -" << endl;

    fout.close();

    cout << "Done!" << endl;
    cout << "Read test by symbol..." << endl;
    ifstream fin1(filename);
    //не пропускать пробелы
    fin1.unsetf(ios::skipws);
    if (!fin1){
        cout << "Can't read file" << endl;
        return 1;
    }
    char ch;
    while (!fin1.eof()){
        fin1 >> ch;
        cout << ch;
    }
    fin1.close();
    cout << "Done!" << endl;

    cout << "Read test by line..." << endl;
    ifstream fin2(filename);

    if (!fin2){
        cout << "Can't read file" << endl;
        return 1;
    }
    string s;
    while (getline(fin2, s)){
        cout << s << endl;
    }
    fin2.close();
    cout << "Done!" << endl;
    return 0;
}
