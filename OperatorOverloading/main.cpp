#include <iostream>

using namespace std;

template <class T>
struct v2d_generic{
    T x = 0.0f;
    T y = 0.0f;

    v2d_generic() : x(0), y(0) {}
    v2d_generic(T _x, T _y) : x(_x), y(_y) {}
    v2d_generic(const v2d_generic& v) : x(v.x), y(v.y) {}

    T mag(){ return (x * x + y * y);}

    v2d_generic norm(){
        T r = 1 / mag();
        return v2d_generic(x * r, y * r);
    }

    v2d_generic perp(){ return v2d_generic(-y, x); }
    T dot(const v2d_generic& rhs){ return this->x * rhs.x + this->y * rhs.y; }
    T cross(const v2d_generic& rhs){ return this->x * rhs.x + this->y * rhs.y; }

    v2d_generic operator + (const v2d_generic& rhs){ return v2d_generic(this->x + rhs.x, this->y + rhs.y); }
    v2d_generic operator - (const v2d_generic& rhs){ return v2d_generic(this->x - rhs.x, this->y - rhs.y); }
    v2d_generic operator * (const T& rhs){ return v2d_generic(this->x * rhs, this->y * rhs); }
    v2d_generic operator / (const T& rhs){ return v2d_generic(this->x / rhs, this->y / rhs); }

    v2d_generic& operator += (const v2d_generic& rhs){
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    v2d_generic& operator -= (const v2d_generic& rhs){
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    v2d_generic& operator *= (const T& rhs){
        this->x *= rhs;
        this->y *= rhs;
        return *this;
    }

    v2d_generic& operator /= (const T& rhs){
        this->x /= rhs;
        this->y /= rhs;
        return *this;
    }

    T& operator [] (std::size_t i){  //"float&" for b[0] = 7.0f; else error
        return *((T*)this + i);
    }
};

typedef v2d_generic<float> vf2d;
typedef v2d_generic<double> vd2d;
typedef v2d_generic<int> vi2d;

int main()
{
    vf2d a = {1.0f, 2.5f};
    vf2d b = {2.0f, 3.5f};
    vf2d c = {3.0f, 4.5f};

    /*vi2d a = {1, 2};
    vi2d b = {2, 3};
    vi2d c = {3, 4};*/
    cout << std::fixed << "c.x = " << c.x << " c.y = " << c.y << endl;

    //a.x = b.x + c.x;
    //a.y = b.y + c.y;

    a = {b.x + c.x, b.y + c.y};
    cout << std::fixed << "a.x = " << a.x << " a.y = " << a.y << " " << a.mag() << endl;

    vf2d d = a;
    cout << std::fixed << "d.x = " << d.x << " d.y = " << d.y << endl;

    vf2d n = d.norm();
    cout << std::fixed << "n.x = " << n.x << " n.y = " << n.y << endl;

    vf2d p = a.perp();
    cout << std::fixed << "p.x = " << p.x << " p.y = " << p.y << endl;

    b = a + c;
    cout << std::fixed << "a + c: b.x = " << b.x << " b.y = " << b.y << endl;

    b = a - c;
    cout << std::fixed << "a - c: b.x = " << b.x << " b.y = " << b.y << endl;

    b = a * 2;
    cout << std::fixed << "a * 2: b.x = " << b.x << " b.y = " << b.y << endl;

    b = a / 3;
    cout << std::fixed << "a / 3: b.x = " << b.x << " b.y = " << b.y << endl;

    b += d;
    cout << std::fixed << "b += d: b.x = " << b.x << " b.y = " << b.y << endl;

    b -= p;
    cout << std::fixed << "b -= p: b.x = " << b.x << " b.y = " << b.y << endl;

    b *= 4;
    cout << std::fixed << "b *= 4: b.x = " << b.x << " b.y = " << b.y << endl;

    b /= 2;
    cout << std::fixed << "b /= 2: b.x = " << b.x << " b.y = " << b.y << endl;
    b[0] = 7.0f;
    b[1] = 10.0f;
    cout << std::fixed << "subscript: b[0]= " << b[0] << " b[1] = " << b[1] << endl;

    return 0;
}
