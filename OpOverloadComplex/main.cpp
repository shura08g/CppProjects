#include <iostream>

using namespace std;

class Complex{
private:
    int real, img;
public:
    Complex() : real(0), img(0) {}
    Complex(int r, int i) : real(r), img(i) {}
    ~Complex(){}

    void print(){
        cout << real << " + " << img << "i" << endl;
    }

    Complex operator + (const Complex& rval){ return Complex(this->real + rval.real, this->img + rval.img); }
    Complex operator - (const Complex& rval){ return Complex(this->real - rval.real, this->img - rval.img); }
    Complex operator * (const Complex& rval){ return Complex(this->real * rval.real, this->img * rval.img); }
    Complex& operator += (const Complex& rval){
        this->real += rval.real;
        this->img += rval.img;
        return *this;
    }
    Complex& operator -= (const Complex& rval){
        this->real -= rval.real;
        this->img -= rval.img;
        return *this;
    }
    Complex operator ++ (){ return Complex(++this->real, ++this->img); } // prefix
    Complex operator ++ (int){ return Complex(this->real++, this->img++); } // postfix

    // overloading print
    void print(int r, float i){
        real = r;
        img = (int)i;
        cout << real << " + " << img << "i" << endl;
    }
    // overloading print
    void print(float r, int i){
        real = (int)r;
        img = i;
        cout << real << " + " << img << "i" << endl;
    }
};

int main()
{
    Complex c1(5, 4);
    Complex c2(2, 7);
    Complex c3, c4, c5, c6;
    c1.print();
    c2.print();
    c3.print();
    c3 = c1 + c2;
    c3.print();
    c4 = c3 - c1;
    c4.print();
    c5 = c1 * c2;
    c5.print();
    c4 += c4;
    c4.print();
    c6 = c5;
    c6.print();
    ++c6;
    c6.print();
    c6++;
    c6.print();
    c6.print(66, 99.0);
    c6.print(88.00, 77);
    return 0;
}
