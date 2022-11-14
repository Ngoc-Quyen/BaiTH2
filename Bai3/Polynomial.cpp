#include "Polynomial.h"

Polynomial::Polynomial(int n)
{
    this->n = n;
    this->a = new int[this->n];
}
Polynomial::~Polynomial()
{
    this->n = 0;
    delete[] a;
}
istream &operator>>(istream &in, Polynomial &p)
{
    cout << "Nhap bac cua da thuc: ";
    in >> p.n;
    p.a = new int[p.n + 1];
    cout << "Nhap lan luot cac he so cua da thuc: \n";
    for (int i = 0; i <= p.n; i++)
    {
        in >> p.a[i];
    }
    return in;
}
ostream &operator<<(ostream &out, const Polynomial p)
{
    int m = p.n;
    cout << "Da thuc: ";
    for (int i = 0; i < p.n; i++)
    {
        cout << p.a[i] << "x^" << m;
        if (i != p.n)
            cout << " + ";
        m--;
    }
    cout << p.a[p.n] << endl;
    return out;
}
Polynomial Polynomial::operator+(Polynomial &d)
{
    int max = (this->n > d.n) ? this->n : d.n;
    int min = (this->n < d.n) ? this->n : d.n;
    Polynomial sum(max);
    for (int i = max; i > min; i--)
        sum.a[i] = (n == max) ? a[i] : d.a[i];
    for (int i = 0; i <= min; i++)
        sum.a[i] = a[i] + d.a[i];
    return sum;
}
Polynomial Polynomial::operator-(Polynomial &d)
{
    int max = (n > d.n) ? this->n : d.n;
    int min = (n < d.n) ? this->n : d.n;
    Polynomial sub(max);
    for (int i = 0; i <= min; i++)
        sub.a[i] = a[i] - d.a[i];
    for (int i = max; i > min; i--)
        sub.a[i] = (n == max) ? a[i] : d.a[i];
    return sub;
}
Polynomial Polynomial::operator*(Polynomial &d)
{
    Polynomial c(this->n + d.n);
    for (int i = 0; i <= this->n; i++)
    {
        for (int j = 0; j <= d.n; j++)
        {
            c.a[i + j] = c.a[i + j] + this->a[i] * d.a[j];
        }
    }
    while (c.n && c[c.n] == 0)
        c.n--;
    return c;
}
int &Polynomial::operator[](int index)
{
    if (index > this->n)
        exit(0);
    return this->a[index];
}