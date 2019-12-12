#include <iostream>
#include <set>
//#include <algorithm>

using namespace std;

struct Data{
    int i;
    int j;

    bool operator<(const Data &rhs) const {
        return i < rhs.i || (i == rhs.i && j < rhs.j);
    }

    //bool operator<=>(const Data &rhs) const = default; //c++ 20
};

int main(){
    cout << "Spaceship <=>" << endl;
    cout << "-------------" << endl;
    set<Data> d;
    d.insert(Data{1, 2});
    d.insert(Data{3, 4});
    for (Data const& _d: d){
        cout << _d.i << " "<< _d.j << endl;
    }
    cout << "---" << endl;
    d.insert(Data{5, 6});
    set<Data>::iterator it;
    for (it = d.begin(); it != d.end(); ++it){
        cout << (*it).i << " " << (*it).j << endl;
    }
    cout << "---" << endl;
    d.insert(Data{7, 8});
    it = d.begin();
    while (it != d.end()){
        cout << (*it).i << " " << (*it).j << endl;
        ++it;
    }
    cout << "---" << endl;
    return 0;
}
