#include <iostream>

using namespace std;

const int SIZE = 10;

class MyStack{
    char stck[SIZE];
    int count_symb;
    int stackID;
public:
    MyStack(int id);
    ~MyStack();
    void init();
    void push(char ch);
    char pop();
    int size_stack();
};

MyStack::MyStack(int id){
    stackID = id;
    cout << "Initialization stack #" << stackID << endl;
    count_symb = 0;

}

MyStack::~MyStack(){
    cout << "Destruction stack #" << stackID << endl;
}

void MyStack::init(){
    count_symb = 0;
}

void MyStack::push(char ch){
    if (count_symb == SIZE){
        cout << "Stack full!" << endl;
        return;
    }
    stck[count_symb] = ch;
    count_symb++;
}

char MyStack::pop(){
    if (count_symb == 0){
        cout << "Stack empty!" << endl;
        return 0;
    }
    count_symb--;
    return stck[count_symb];
}

int MyStack::size_stack(){
    return count_symb;
}

int main()
{
    MyStack st1(1), st2(2);
    int i;

    //st1.init();
    //st2.init();

    st1.push('o');
    st2.push('d');
    st1.push('l');
    st2.push('l');
    st1.push('l');
    st2.push('r');
    st1.push('e');
    st2.push('o');
    st1.push('H');
    st2.push('W');

    int st1_size = st1.size_stack();
    int st2_size = st2.size_stack();
    for (i = 0; i < st1_size; ++i) cout << st1.pop() << "";
    cout << endl;
    for (i = 0; i < st2_size; ++i) cout << st2.pop() << "";
    cout << endl;
    return 0;
}
