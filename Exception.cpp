//
// Created by gosha on 10/25/2022.
//

#include "Exception.h"
#include "iostream"
using namespace std;
class Exception : public std::exception
{
protected:
    std::string err;
public:
    Exception(const char* str)
    {
        err = std::string(str);
    }

    Exception(std::string& str)
    {
        err = str;
    }

    Exception(const Exception& err)
    {
        this->err = err.err;
    }

    virtual ~Exception() {};

    virtual void print() const
    {
        std::cout << "\nError - " << err << std::endl;
    }
};
class IndexOutOfBoundsException : public Exception
{
protected:
    int row, columns;
public:
    IndexOutOfBoundsException(string str, int& r, int& clmn) : Exception(str)
    {
        row = r;
        columns = clmn;
    }

    virtual void print() const
    {
        cout << err << " Element at index (" << row << "," << columns << ") is outside the bounds of the matrix" << endl;
    }

};

class WrongDimensionsException : public Exception
{
protected:
    int r_1, c_1, r_2, c_2;
public:
    WrongDimensionsException(string str, int r1, int c1, int r2, int c2) : Exception(str), r_1(r1), r_2(r2), c_1(c1), c_2(c2) {}

    virtual void print() const
    {
        cout << err << "The dimensions "<<"("<<r_1<<") and "<<"("<<r_2<<") are not compatible\n";
    }
};

class WrongSizeExceptionOfTwoMatrixs : public Exception
{
protected:
    int r_1, r_2;
public:
    WrongSizeExceptionOfTwoMatrixs(string str, int r1, int r2) : Exception(str), r_1(r1), r_2(r2) {}

    virtual void print() const
    {
        cout << err << "The dimensions "<<"("<<r_1<<") and "<<"("<<r_2<<") are not compatible\n";
    }
};

class WrongSizeException : public Exception
{
protected:
    int rw, cl;
public:
    WrongSizeException(string str, int r, int c) : Exception(str), rw(r), cl(c) { }

    virtual void print() const
    {
        cout << err << "Wrong matrix size: " << "(" << rw << "," << cl << ")\n";
    }
};
class WrongSizeOfMatrixB : public Exception{
protected:
    int columns;
public:
    WrongSizeOfMatrixB(string str, int& cl) : Exception(str)
    {
        columns = cl;
    }

    virtual void print() const
    {
        cout << err << "The element at index (" << columns << ") is outside the bounds of the matrix" << endl;
    }
};

class IncorrectDataInMatrix : public Exception
{
private:
    int r, c;
public:
    IncorrectDataInMatrix(string str, int rw, int cl) : Exception(str), r(rw), c(cl) {}

    virtual void print() const
    {
        cout << err << "\nYou have entered incorrect data in the matrix, element -> < " << r << " , " << c << " >\n\a";
    }
};