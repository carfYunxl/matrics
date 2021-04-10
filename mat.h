#ifndef MAT_H
#define MAT_H
#include <iostream>

class Mat
{
public:
    Mat();
    Mat(int,int,int,int,int r,int c);
    Mat(int,int,int,int,int,int,int,int,int);
    Mat(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int r,int c);
    Mat(int r,int c);
    Mat(int r,int c,int value);//创建值全为value的矩阵
    ~Mat();

    void M_print();//矩阵元素输出
    void diag(int value);//对角矩阵
    Mat M_cvt()const;//转置矩阵
    int at(int,int);
    void absModle();
    void M_elimination();
    //四则运算符重载
    Mat& operator+(const Mat&);
    Mat& operator-(const Mat&);
    Mat& operator=(const Mat&);





protected:
    friend Mat operator*(const Mat&,const Mat&);

private:
    const int row = 3;
    const int col = 3;

    int **array ;
    void initialize();

};

Mat operator*(const Mat&,const Mat&);

#endif // MAT_H
