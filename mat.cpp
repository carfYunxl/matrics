#include "mat.h"

using std::cin;
using std::cout;
using std::endl;

Mat::Mat()
{
    cout << "1.默认构造函数调用" << endl;
    initialize();
}
Mat::Mat(int a11,int a12,int a13,int a21,int a22,int a23 ,int a31,int a32,int a33)
{
    cout << "4.3X3构造函数调用" << endl;
    initialize();
    this->array[0][0] = a11;
    this->array[0][1] = a12;
    this->array[0][2] = a13;

    this->array[1][0] = a21;
    this->array[1][1] = a22;
    this->array[1][2] = a23;

    this->array[2][0] = a31;
    this->array[2][1] = a32;
    this->array[2][2] = a33;
}
Mat::Mat(int r,int c):row(r),col(c)
{
    cout << "2.构造函数调用" << endl;
    initialize();
    for(int i = 0;i<r;++i)
    {
        for(int j = 0;j < c;++j)
        {
            array[i][j] = 0;
        }
    }
}
Mat::Mat(int r,int c,int value):row(r),col(c)
{
    cout << "3.构造函数调用" << endl;
    initialize();
    for(int i = 0;i < row;++i)
    {
        for(int j = 0;j < col;++j)
        {
            array[i][j] = value;
        }
    }
}
void Mat::initialize()
{
    array = new int*[row];
    for(int i = 0;i < row;++i)
    {
        array[i] = new int[col];
    }
}
Mat::~Mat()
{
    cout << "析构函数调用！" << endl;
    for(int i = 0;i < row;++i)
    {
        delete[] array[i];
    }
    delete []array;
}
void Mat::M_print()
{
    cout << "-----------------------------------" << endl;
    for(int i = 0;i<row;++i)
    {
        for(int j = 0;j < col;++j)
        {
            if(j == 0)
            {
                cout << "|";
            }
            cout << "  " << array[i][j];
            if(j == col - 1)
            {
                cout << "  " << "|" << endl;
            }
        }
    }
    cout << "-----------------------------------" << endl;
}
Mat& Mat::operator+(const Mat& m)
{
    if(m.row == this->row && m.col == this->col)
    {
        for(int i = 0;i < row;++i)
        {
            for(int j = 0;j < col;++j)
            {
                this->array[i][j] += m.array[i][j];
            }
        }
        return *this;
    }
    else
    {
        cout << "Invalid mat plus!" << endl;
        return *this;
    }
}
Mat& Mat::operator-(const Mat& m)
{
    if(m.row == this->row && m.col == this->col)
    {
        for(int i = 0;i < row;++i)
        {
            for(int j = 0;j < col;++j)
            {
                this->array[i][j] -= m.array[i][j];
            }
        }
        return *this;
    }
    else
    {
        cout << "Invalid mat plus!" << endl;
        return *this;
    }
}
Mat operator*(const Mat &m,const Mat &n)
{
    Mat tmp(m.row,n.col);
    if(m.col == n.row)
    {
        for(int i = 0;i < m.row;++i)
        {
            for(int j = 0;j < n.col;++j)
            {
                for(int k = 0;k < n.row;++k)
                {
                    tmp.array[i][j] = tmp.array[i][j] + m.array[i][k] * n.array[k][j];
                }
            }
        }
        return tmp;
    }
    else
    {
        cout << "Invalid mat plus!" << endl;
        return tmp;
    }
}
Mat& Mat::operator=(const Mat&m)
{
    if(m.row == this->row && m.col == this->col)
    {
        for(int i = 0;i < this->row;++i)
        {
            for(int j = 0;j < this->col;++j)
            {
                this->array[i][j] = m.array[i][j];
            }
        }
        return *this;
    }
    else
    {
        cout << "Invalid mat plus!" << endl;
        return *this;
    }
}
void Mat::diag(int value)
{
    for(int i = 0;i < this->row;++i)
    {
        for(int j = 0;j < this->col;++j)
        {
            if(i == j)
            {
                this->array[i][j] = value;
            }
        }
    }
}
Mat Mat::M_cvt() const
{
    Mat tmp(this->col,this->row);
    for(int i = 0;i < this->row;++i)
    {
        for(int j = 0;j < this->col;++j)
        {
            tmp.array[j][i] = this->array[i][j];
        }

    }
    return tmp;
}
int Mat::at(int a,int b)
{
    if(a > this->row  ||  b > this->col || a < 0 || b < 0-1){
        return 0;
    }
    else {
        return this->array[a][b];
    }
}
void absModle()
{

}
void Mat::M_elimination()
{
    int tmp,pivot;
    pivot = this->array[0][0];
    if(pivot)//如果主元1不为0
    {
        if(this->array[1][0])//如果主元2也不为0,第一次消元操作
        {
            tmp = this->array[1][0] / pivot;
            for(int i = 0;i < this->row;i++)
            {
                this->array[1][i] = this->array[1][i] - this->array[0][i] * tmp;
            }
            if(this->array[2][0])
            {
                tmp = this->array[2][0] / pivot;
                for(int i = 0;i < this->row;i++)
                {
                    this->array[2][i] = this->array[2][i] - this->array[0][i] * tmp;
                }
            }
        }
        //主元2为0，主元3不为0
        else if(this->array[2][0]){
            tmp = this->array[2][0] / pivot;
            for(int i = 0;i < this->row;i++)
            {
                this->array[2][i] = this->array[2][i] - this->array[0][i] * tmp;
            }
        }
    }
    //主元1为0
    else{
        if(this->array[1][0])//主元2不为0
        {
            if(this->array[2][0])//主元3不为0
            {
                tmp = this->array[2][0] / this->array[1][0];
                for(int i = 0;i < this->row;i++)
                {
                    this->array[2][i] = this->array[2][i] - this->array[1][i] * tmp;
                }
            }
        }
    }

    //进一步消元
    if(this->array[1][1])//主元1不为0
    {
        if(this->array[2][1])//主元2不为0
        {
            //再一次消元
            tmp = this->array[2][1] / this->array[1][1];
            for(int i = 1;i < this->row;i++)
            {
                this->array[2][i] = this->array[2][i] - this->array[1][i] * tmp;
            }
        }
        for(int i = 0;i < this->row;i++)
        {
            if(this->array[2][i] == 0)
            {
                cout << "该矩阵不是可逆矩阵！" << endl;
            }
            else{
                cout << "该矩阵是可逆矩阵！" << endl;
            }
        }
    }
    else if(this->array[2][1])//主元2不为0
    {
        if(this->array[0][1])
        {
            tmp = this->array[2][1] / this->array[0][1];
            for(int i = 1;i < this->row;i++)
            {
                this->array[2][i] = this->array[2][i] - this->array[0][i] * tmp;
            }

            for(int i = 0;i < this->row;i++)
            {
                if(this->array[2][i] == 0)
                {
                    cout << "该矩阵不是可逆矩阵！" << endl;
                }
                else{
                    cout << "该矩阵是可逆矩阵！" << endl;
                }
            }
        }
        else
        {
            cout << "该矩阵是可逆矩阵！" << endl;
        }

    }
}

Mat::Mat(int a11,int a12,int a21,int a22,int r,int c):row(r),col(c)
{
    cout << "6.2X2构造函数调用" << endl;
    initialize();
    this->array[0][0] = a11;
    this->array[0][1] = a12;
    this->array[1][0] = a21;
    this->array[1][1] = a22;
}

Mat::Mat(int a11,int a12,int a13,int a14,int a21,int a22,int a23,int a24,int a31,int a32,int a33,int a34,int a41,int a42,int a43,int a44,int r,int c):row(r),col(c)
{
    cout << "5.4X4构造函数调用" << endl;
    initialize();
    this->array[0][0] = a11;
    this->array[0][1] = a12;
    this->array[0][2] = a13;
    this->array[0][3] = a14;

    this->array[1][0] = a21;
    this->array[1][1] = a22;
    this->array[1][2] = a23;
    this->array[1][3] = a24;

    this->array[2][0] = a31;
    this->array[2][1] = a32;
    this->array[2][2] = a33;
    this->array[2][3] = a34;

    this->array[3][0] = a41;
    this->array[3][1] = a42;
    this->array[3][2] = a43;
    this->array[3][3] = a44;
}
