#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton* getSingleton();
    int getValue();
    void setValue(int i);

private:
    static Singleton* singleton;
    int value;
    Singleton();
    /* data */
};

//Declaration of static property.
Singleton* Singleton::singleton;

//Returns a pointer to the singleton.
Singleton* Singleton::getSingleton(){
    if (singleton == NULL)
    {
        singleton = new Singleton();
        return singleton;
    }

    return singleton;
}

//Private constructor for singleton
Singleton::Singleton(){
    std::cout << "Singleton instance created" << std::endl;
}

//Returns the value of the singleton
int Singleton::getValue(){
    return this->value;
}

//Sets the value of the singleton
void Singleton::setValue(int i){
    this->value = i;
}

int main(int argc, char const *argv[])
{

    //Create pointer to singleton
    std::cout << "Creating singleton..." << std::endl;
    Singleton* singleton = Singleton::getSingleton();
    singleton->setValue(12);

    delete singleton;

    //create another and check value persists.
    singleton = Singleton::getSingleton();
    std::cout << singleton->getValue() << std::endl;
    /*singleton->setValue(22);
    std::cout << singleton->getValue() << std::endl;*/
    return 0;
}
