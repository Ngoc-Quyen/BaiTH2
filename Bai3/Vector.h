#include <iostream>
using namespace std;
class Vector
{
private:
    double *p;
    int length;

public:
    // Vector();
    Vector(int = 0, int = 1);
    ~Vector();
    void setLength(int = 0);
    int getLength();
    friend istream &operator>>(istream &, Vector &);
    friend ostream &operator<<(ostream &, const Vector &);
    void Show();
    double &operator+(Vector &);
    double &operator-(Vector &);
    double &operator*(Vector &);
    // int Vector::operator[](int);
};