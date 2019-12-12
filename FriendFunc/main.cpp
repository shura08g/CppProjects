#include <iostream>

using namespace std;

class Distance{
private:
    int meters;
public:
    Distance() : meters(0) {}
    virtual void displayData(){ cout << "Meters value: " << meters << endl; }
    // prototype or signature
    friend void addValue(Distance &d, int);
    friend void addFive(Distance &d);
};

class Dist2 : public Distance{
private:
    int meters;
public:
    Dist2() : meters(100) {}
    void displayData() override { cout << "Meters value of distance: " << meters << endl; }
    friend void addValue(Dist2 &d, int);
    friend void addFive(Dist2 &d);
};

void addValue(Distance &d, int m){
    d.meters += m;
}

void addValue(Dist2 &d, int m){
    d.meters += m;
}

void addFive(Distance &d){
    d.meters += 5;
}

void addFive(Dist2 &d){
    d.meters += 5;
}

int main()
{
    Distance d1;
    d1.displayData();

    addFive(d1); // pass by reference
    d1.displayData();

    addValue(d1, 10); // pass by reference
    d1.displayData();

    Dist2 d2;
    d2.displayData();
    addFive(d2);
    d2.displayData();
    addValue(d2, 50);
    d2.displayData();

    return 0;
}
