//
// Created by gosha on 10/26/2022.
//
#include "headers/Matrix.h"

#include <iostream>
#include <cstddef>
#include <cassert>
#include <utility> //std::swap
#include <sstream>

class RangeException : public std::exception {
protected:
    std::string error_info;
public:
    RangeException(std::string in) : exception() {
        error_info = in;
    }
    void print() const {
        std::cout << this->error_info << "\n";
    }
};
template <typename T>
Matrix<T>::Matrix()
        :rows(0), columns(0), size(0), number(0), data(nullptr)
{
}
template <typename T>
Matrix<T>::Matrix(std::size_t r, std::size_t c)
        :rows(r), columns(c), size(r * c)
{
    if(0 == columns && rows != 0) {
        columns = rows;
        rows = 1;
        size = columns;
    }

    data = new float*[rows];
    for(std::size_t i = 0; i < rows; ++i) {
        data[i] = new float[columns];
    }
}
template <typename T>
Matrix<T>::Matrix(const Matrix& M)
        :rows(M.rows), columns(M.columns), size(M.size), number(M.number), data(new float*[M.rows])
{
    for(std::size_t i = 0; i < rows; ++i) {
        data[i] = new float[columns];
        for(std::size_t j = 0; j < columns; ++j) {
            data[i][j] = M.data[i][j];
        }
    }
}


template <typename T>
Matrix<T>& Matrix<T>::operator+(const Matrix& M){
    if(size == M.size) {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < columns; ++j) {
                data[i][j] += M.data[i][j];
            }
        }
    }
    return *this;
}
template <typename T>
Matrix<T>& Matrix<T>::operator-(const Matrix& M){
    if(size == M.size) {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < columns; ++j) {
                data[i][j] -= M.data[i][j];
            }
        }
    }
    return *this;
}
template <typename T>
Matrix<T>& Matrix<T>::operator*(const Matrix& M){
    if(this->columns == M.rows) {
        Matrix tmp(rows, M.columns);
        for (std::size_t i = 0; i < rows; ++i) {
            for(std::size_t k = 0; k < M.columns; ++k){
                for(std::size_t j = 0; j < columns; ++j){
                    //std::cout << "\n -> " << data[i][j]*M.data[j][k];
                    tmp(i, k) += data[i][j]*M.data[j][k];
                }
            }
        }
        for(std::size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = tmp.rows;
        columns = tmp.columns;
        size = tmp.size;

        data = new float*[rows];
        for(std::size_t i = 0; i < rows; ++i) {
            data[i] = new float[columns];
            for(std::size_t j = 0; j < columns; ++j) {
                data[i][j] = tmp.data[i][j];
            }
        }
        return *this;
    } else {
        throw RangeException(std::string("columns < rows"));
    }

}
template <typename T>
Matrix<T>& Matrix<T>::operator*(const size_t& M){
    for(std::size_t i = 0; i < rows; ++i){
        for(std::size_t j = 0; j < columns; ++j) {
            data[i][j] *=M;
        }
    }
    return *this;
}template <typename T>
Matrix<T>& Matrix<T>::operator*(const float& M){
    for(std::size_t i = 0; i < rows; ++i){
        for(std::size_t j = 0; j < columns; ++j) {
            data[i][j] = data[i][j] * M;
        }
    }
    return *this;
}
template <typename T>
Matrix<T>& Matrix<T>::operator/(const Matrix& M){
    //TODO
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& M)
{
    if(&M == this) {
        return *this;
    }

    for(std::size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    rows = M.rows;
    columns = M.columns;
    size = M.size;

    data = new float*[rows];
    for(std::size_t i = 0; i < rows; ++i) {
        data[i] = new float[columns];
        for(std::size_t j = 0; j < columns; ++j) {
            data[i][j] = M.data[i][j];
        }
    }

    return *this;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& M){
    bool marker = true;
    if(size == M.size) {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < columns; ++j) {
                if(data[i][j] != M.data[i][j]){
                    marker = false;
                }
            }
        }
    } else return false;

    return marker;
}
template <typename T>
bool Matrix<T>::operator!=(const Matrix& M){
    bool marker = false;
    if(size == M.size) {
        for (std::size_t i = 0; i < rows; ++i) {
            for (std::size_t j = 0; j < columns; ++j) {
                if(data[i][j] != M.data[i][j]){
                    marker = true;
                }
            }
        }
    } else return true;

    return marker;
}
template <typename T>
Matrix<T>::~Matrix()
{
    for(std::size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}
template <typename T>
void Matrix<T>::Print(){
    std::cout << "\n";
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++){
            std::cout << data[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
template <typename T>
Matrix<T>& Matrix<T>::Transpose() {
    Matrix Tmp(columns, rows);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            Tmp.data[j][i] = data[i][j];
        }
    }

    for(std::size_t i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    rows = Tmp.rows;
    columns = Tmp.columns;
    size = Tmp.size;

    data = new float*[rows];
    for(std::size_t i = 0; i < rows; ++i) {
        data[i] = new float[columns];
        for(std::size_t j = 0; j < columns; ++j) {
            data[i][j] = Tmp.data[i][j];
        }
    }
    return *this;
}
template <typename T>
float Matrix<T>::Determinant(){
    float result = 0;
    if(rows == columns){
        if(this->size > 4){
            for(int k = 0; k<columns; ++k){
                Matrix tmp(rows-1,columns-1);
                int step = 0;
                for(int j = 0; j<tmp.columns; ++j){
                    if(step == k) step++;
                    for(int i = 0; i<tmp.rows; ++i){
                        tmp(i,j) = data[i+1][step];
                    }
                    step++;
                }
                if(k%2 == 0){
                    result += tmp.Determinant() * data[0][k];
                } else {
                    result += tmp.Determinant() * (-1*data[0][k]);
                }

            }

        } else {
            result = (data[0][0] * data[1][1])-(data[0][1] * data[1][0]);
            return result;
        }

    } else RangeException(std::string("Matrix is not cubic"));
    return result;
}
template <typename T>
void Matrix<T>::Swap_Rows(std::size_t i, std::size_t j)
{
    assert(i >= 0 && i < rows && "The Row index is out of range!\n");
    assert(j >= 0 && j < rows && "The row index is out of range!\n");

    if(i == j) { return; }

    std::swap(data[i], data[j]);
}

template <typename T>
float& Matrix<T>::operator()(std::size_t i, std::size_t j)
{
    return data[i][j];
}
template <typename T>
const float& Matrix<T>::operator()(std::size_t i, std::size_t j) const
{
    return data[i][j];
}

//vector represented as 1xn matrix, thus operator(with single parameter) returns elements from first row when we use it with mxn (m!=1) matrix
template <typename T>
float& Matrix<T>::operator()(std::size_t i)
{
    return data[0][i];
}
template <typename T>
const float& Matrix<T>::operator()(std::size_t i) const
{
    return data[0][i];
}
template <typename T>
std::size_t Matrix<T>::get_rows() const { return rows; }
template <typename T>
std::size_t Matrix<T>::get_columns() const { return columns; }
template <typename T>
std::size_t Matrix<T>::get_size() const { return size; }
template <typename T>
std::size_t Matrix<T>::get_number() const {return number; }

template <typename T>
void Matrix<T>::set_rows(std::size_t r) { rows = r; }
template <typename T>
void Matrix<T>::set_columns(std::size_t c) { columns = c; }
template <typename T>
void Matrix<T>::set_size(std::size_t s) { size = s; }
template <typename T>
void Matrix<T>::set_number(std::size_t n) { number = n; }

template <typename T>
std::istream &operator>>(std::istream &os, Matrix<T> &m) {
    for(int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++) {
            os >> m.data[i][j];
        }
    }
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &m) {
    std::ostringstream output_text;    // Declare an output stringstream
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++) {
            output_text << m.data[i][j] << ' ';
        }
        output_text << '\n';
        }
    os << output_text.str();

    return os;
}


template <typename T>
Result<T>::Result () : Matrix<T>(), state("")
{
}
template <typename T>
Result<T>::Result(std::string s, std::size_t r, std::size_t c)
        : Matrix<T>(r, c), state(s)
{
}
template <typename T>
Result<T>::Result(const Result& R)
        :Matrix<T>(R) , state(R.state)
{
}
template <typename T>
Result<T>& Result<T>::operator=(const Result& R)
{
    Matrix<T>::operator=(R);
    state = R.state;

    return *this;
}

template <typename T>
void Result<T>::set_state(std::string s) { state = s; }
template <typename T>
std::string Result<T>::get_state() const { return state; }

