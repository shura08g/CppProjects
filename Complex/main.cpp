#include <iostream>

using namespace std;

class ComplexNumber{
private:
    // data members
    int real;
    float imaginary;
public:
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(int r, float i) : real(r), imaginary(i) {}
    void displayData() { cout << "Complex number is: " << real << " + " << imaginary << "i" << endl; }
    int getRealPart() { return real; }
    float getImaginaryPart() { return imaginary; }
    ComplexNumber operator + (const ComplexNumber& rval){
        return ComplexNumber(this->real + rval.real, this->imaginary + rval.imaginary);
    }
    ComplexNumber& operator += (const ComplexNumber& rval){
        this->real += rval.real;
        this->imaginary += rval.imaginary;
        return *this;
    }
};

ComplexNumber add2number(ComplexNumber& n1, ComplexNumber& n2){
    int r;
    float i;
    r = n1.getRealPart() + n2.getRealPart();
    i = n1.getImaginaryPart() + n2.getImaginaryPart();
    return ComplexNumber(r, i);
}

int main()
{
    ComplexNumber comp1(5, 4);
    ComplexNumber comp2(3, 7);
    ComplexNumber comp3, comp4, comp5;
    comp3 = comp1 + comp2;
    comp1.displayData();
    comp3.displayData();
    comp4 = add2number(comp1, comp3);
    comp4.displayData();
    comp5 += comp2;
    comp5.displayData();

    ComplexNumber* compPrt;
    compPrt = &comp1;
    compPrt->displayData();
    comp2 = add2number(comp1, *compPrt);
    comp2.displayData();
    cout << compPrt->getRealPart() << " + " << compPrt->getImaginaryPart() << "i : " << compPrt << endl;
    return 0;
}
