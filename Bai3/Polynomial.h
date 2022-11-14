#include <iostream>
using namespace std;
class Polynomial
{
    private: 
        int n; 
        int *a; 
    public:
        Polynomial(int = 0);
        ~Polynomial();
        friend ostream& operator<<(ostream&, const Polynomial);
        friend istream& operator>>(istream&, Polynomial&);
        Polynomial operator+(Polynomial&);
        Polynomial operator-(Polynomial&);
        Polynomial operator*(Polynomial&);
        int& operator[](int);

};