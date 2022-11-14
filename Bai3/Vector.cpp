#include "Vector.h"

// Vector::Vector()
// {
//     this->length = 0;
//     this->p = nullptr;
// }
Vector::Vector(int n, int t)
{
    this->setLength(n);
    this->p = new double[n];
    for (int i = 0; i < this->length; i++)
    {
        *(p + i) = t;
    }
}
Vector::~Vector()
{
    delete[] p;
}
void Vector::setLength(int length)
{
    this->length = length;
}
int Vector::getLength()
{
    return this->length;
}
istream &operator>>(istream &in, Vector &v)
{
    cout << "Nhap chieu dai cua vector: ";
    cin >> v.length;
    delete[] v.p;
    cout << "Nhap Gia tri cua cac phan tu: \n";
    v.p = new double[v.length];
    for (int i = 0; i < v.length; i++)
    {
        cin >> *(v.p + i);
    }
    return in;
}
ostream &operator<<(ostream &out, const Vector &v)
{
    for (int i = 0; i < v.length; i++)
    {
        out << *(v.p + i) << " ";
    }
    out << endl;
    return out;
}
void Vector::Show()
{
    cout << "Xuat: \n";
    for (int i = 0; i < this->length; i++)
    {
        cout << *(this->p + i) << " ";
    }
    cout << endl;
}
// int Vector::operator[](int index)
// {
//     if (index > this->length)
//         exit(0);
//     return this->p[index];
// }
double &Vector::operator+(Vector &v)
{

    for (int i = 0; i < v.length; i++)
    {
        sum += *(v.p + i);
    }
    return sum;
}
double &Vector::operator-(Vector &v)
{
    double
}