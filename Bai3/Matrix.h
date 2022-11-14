#include <iostream>
using namespace std;

class Matrix
{
private:
    int row, col;
    double **mt;

public:
    Matrix(int = 0, int = 0, int = 1);
    ~Matrix();
    void setRow(int = 0);
    int getRow();
    void setCol(int = 0);
    int getCol();
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix);
    double &operator()(const int &, const int &);
};