//
// Created by gosha on 10/26/2022.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <cstddef>    //size_t
#include <string>
#include "rational.h"
class Matrix {
    friend std::istream& operator>>(std::istream & is, Matrix  &m);
    friend std::ostream& operator<<(std::ostream &os, Matrix const &m);
public:
    Matrix();
    explicit Matrix(std::size_t i, std::size_t j = 0);

    //Matrix(Matrix&&);
    //Matrix& operator=(Matrix&&);

    Matrix(const Matrix&);
    Matrix& operator+(const Matrix&);
    Matrix& operator-(const Matrix&);
    Matrix& operator*(const Matrix&);
    Matrix& operator*(const size_t&);
    Matrix& operator*(const float&);
    Matrix& operator/(const Matrix&);
    Matrix& operator=(const Matrix&);
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);
    Matrix& Transpose();
    ~Matrix();

    void Swap_Rows(std::size_t, std::size_t);

    float& operator()(std::size_t, std::size_t);
    const float& operator()(std::size_t, std::size_t) const;



    float& operator()(std::size_t);
    const float& operator()(std::size_t) const;

    float Determinant();

    [[nodiscard]] std::size_t get_rows() const;
    [[nodiscard]] std::size_t get_columns() const;
    [[nodiscard]] std::size_t get_size() const;
    [[nodiscard]] std::size_t get_number() const;

    void Print();
    void set_rows(std::size_t);
    void set_columns(std::size_t);
    void set_size(std::size_t);
    void set_number(std::size_t);

private:
    std::size_t rows;
    std::size_t columns;
    std::size_t size;
    std::size_t number;
    float ** data;


};

class Result : public Matrix
{
public:
    Result();
    Result(std::string s, std::size_t r, std::size_t c);

    Result(const Result&);
    Result& operator=(const Result&);

    void set_state(std::string s);
    [[nodiscard]] std::string get_state() const;

private:
    std::string state;
};



#endif //MATRIX_MATRIX_H
