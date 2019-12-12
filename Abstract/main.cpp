#include <iostream>

using namespace std;

class MyBase{
public:
    void show(){ cout << "Base class show() function called" << endl; }
    virtual void print(){ cout << "Base class print() function called" << endl; }
};

class MyDerived : public MyBase{
public:
    void show(){ cout << "Derived class show() function called" << endl; }
    void print(){ cout << "Derived class print() function called" << endl; }
};

class Animal{
public:
    virtual void eat(){ cout << "I'm eating generic food." << endl; }
};

class Cat : public Animal{
public:
    void eat(){ cout << "I'm eating cat food." << endl; }
};

class Dog : public Animal{
public:
    void eat(){ cout << "I'm eating dog food." << endl; }
};

void func1(Animal* xyz){ xyz->eat();}

int main()
{
    MyBase* basePrt = new MyBase();
    MyDerived derivedObj;

    basePrt->print(); // Base class print() function called"
    basePrt->show(); // Base class show() function called

    derivedObj.print(); // Derived class print() function called
    derivedObj.show(); // Derived class show() function called

    basePrt = &derivedObj;

    // run-time polymorphism
    basePrt->print(); // Derived class print() function called
    basePrt->show(); // Base class show() function called

    //--------------------------------------
    Animal *animPrt;
    Cat catObj;
    Dog dogObj;

    animPrt = &catObj;
    func1(animPrt); // I'm eating cat food.
    // without virtual void eat() in Animal print "I'm eating generic food."

    animPrt = &dogObj;
    func1(animPrt);  // I'm eating dog food.

    return 0;
}
