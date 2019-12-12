#include <iostream>

using namespace std;

class SomeClass{
    public:
        SomeClass(){
            someVar = 0;
            cout << "someVar now = " << someVar << '\n';
        }
        void printCrap();
    private:
        int someVar;
        friend void friendFunc(SomeClass &sc);
};

void friendFunc(SomeClass &sc){
    sc.someVar = 100;
    cout << "someVar now = " << sc.someVar << '\n';
}

void SomeClass::printCrap(){
    cout << "someVar = " << someVar << '\n';
    cout << "this->someVar = " << this->someVar << '\n';
    cout << "(*this).someVar = " << (*this).someVar << '\n';
}

int main()
{
    SomeClass sc;
    friendFunc(sc);
    sc.printCrap();
    return 0;
}
