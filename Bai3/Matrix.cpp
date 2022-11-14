#include "Matrix.h"

Matrix::Matrix(int row, int col, int t)
{
    this->row = row;
    this->col = col;
    this->mt = new double *[this->row];
    for (int i = 0; i < this->row; i++)
    {
        *(this->mt + i) = new double[this->col];
        for (int j = 0; j < this->col; j++)
        {
            *(*(this->mt + i) + j) = t;
        }
    }
}
Matrix::~Matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] * (this->mt + i);
    }
    delete[] this->mt;
}
void Matrix::setRow(int r)
{
    this->row = r;
}
int Matrix::getRow()
{
    return this->row;
}
void Matrix::setCol(int c)
{
    this->col = c;
}
int Matrix::getCol()
{
    return this->col;
}
istream &operator>>(istream &in, Matrix &m)
{
    cout << "Nhap lan luot so hang va cot cua ma tran: ";
    cin >> m.row >> m.col;
    m.mt = new double *[m.row];
    for (int i = 0; i < m.row; i++)
    {
        *(m.mt + i) = new double[m.col];
        for (int j = 0; j < m.col; j++)
        {
            in >> *(*(m.mt + i) + j);
        }
    }
    return in;
}
ostream &operator<<(ostream &out, Matrix m)
{
    out << "Ma tran:\n";
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            cout << *(*(m.mt + i) + j) << " ";
        }
        out << '\n';
    }
    return out;
}
double &Matrix::operator()(const int &i, const int &j)
{
    static double t = 0;
    if (i >= 0 && i < this->row && j >= 0 && j < this->col)
        return *(*(this->mt + i) + j);
    else
        return t;
}