#include <iostream>

using namespace std;

struct vf2d{
    float x = 0.0f;
    float y = 0.0f;

    vf2d() : x(0), y(0) {}
    vf2d(float _x, float _y) : x(_x), y(_y) {}
    vf2d(const vf2d& v) : x(v.x), y(v.y) {}

    float mag(){ return (x * x + y * y);}

    vf2d norm(){
        float r = 1 / mag();
        return vf2d(x * r, y * r);
    }

    vf2d perp(){ return vf2d(-y, x); }
    float dot(const vf2d& rhs){ return this->x * rhs.x + this->y * rhs.y; }
    float cross(const vf2d& rhs){ return this->x * rhs.x + this->y * rhs.y; }

    vf2d operator + (const vf2d& rhs){ return vf2d(this->x + rhs.x, this->y + rhs.y); }
    vf2d operator - (const vf2d& rhs){ return vf2d(this->x - rhs.x, this->y - rhs.y); }
    vf2d operator * (const float& rhs){ return vf2d(this->x * rhs, this->y * rhs); }
    vf2d operator / (const float& rhs){ return vf2d(this->x / rhs, this->y / rhs); }

    vf2d& operator += (const vf2d& rhs){
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    vf2d& operator -= (const vf2d& rhs){
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    vf2d& operator *= (const float& rhs){
        this->x *= rhs;
        this->y *= rhs;
        return *this;
    }

    vf2d& operator /= (const float& rhs){
        this->x /= rhs;
        this->y /= rhs;
        return *this;
    }

    float& operator [] (std::size_t i){  //"float&" for b[0] = 7.0f; else error
        return *((float*)this + i);
    }
};

int main2()
{
    vf2d a = {1.0f, 2.5f};
    vf2d b = {2.0f, 3.5f};
    vf2d c = {3.0f, 4.5f};
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
