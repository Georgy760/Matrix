//
// Created by gosha on 10/26/2022.
//

#include "headers/file_reader.h"
#include "headers/file_writer.h"
#include "headers/Matrix.h"

#include <iostream>
#include <cstddef>
#include <cassert>
template <typename T>
bool Read_Matrix_Size (File_Reader& fr, Matrix<T>& M)
{
    char c;
    std::size_t row, col;
    if(fr.char_reading(c) && fr.char_reading(c) &&
       fr.sizet_reading(row) && fr.char_reading(c) &&
       fr.sizet_reading(col) && fr.char_reading(c)) {
        M = Matrix<T>(row, col);
        return true;
    }
    else {
        return false;
    }
}
template <typename T>
bool Read_Matrix_Data(File_Reader& fr, Matrix<T>& M)
{
    char c;
    for(std::size_t i = 0; i < M.get_rows(); ++i) {
        for(std::size_t j = 0; j < M.get_columns(); ++j) {
            if(!(fr.float_reading(M(i, j)) && fr.char_reading(c))) {
                return false;
            }
        }
    }
    return true;
}
template <typename T>
bool Read_SLE(File_Reader& fr, Matrix<T>& A, Matrix<T>& B)
{
    char c;
    std::size_t number;

    if(!(fr.char_reading(c) && fr.sizet_reading(number))) {
        return false;
    }
    if(c != '#') {
        std::cout << "Possibly incomplete data or data type mismatch.\n";
    }

    if(!(Read_Matrix_Size(fr, A) && Read_Matrix_Data(fr, A))) {
        return false;
    }

    if(!(Read_Matrix_Size(fr, B) && Read_Matrix_Data(fr, B))) {
        return false;
    }

    A.set_number(number);
    B.set_number(number);

    assert(A.get_rows() == B.get_rows() && "Size mismatch!");

    return true;
}

template <typename T>
bool Read_Result(File_Reader& fr, Result<T>& R)
{
    std::string s;
    char c;
    std::size_t m, n, number;
    float f;
    if(!(fr.char_reading(c) && fr.sizet_reading(number))) {
        return false;
    }

    if(!fr.string_reading(s)) {
        return false;
    }
    if('N' == s[0]) {
        R = Result<T>(s, 0, 0);
        R.set_number(number);
        return true;
    }

    if(!(fr.char_reading(c) && fr.char_reading(c) && fr.sizet_reading(m) &&
         fr.char_reading(c) && fr.sizet_reading(n) && fr.char_reading(c))) {
        return false;
    }

    R = Result<T>(s, m, n);
    R.set_number(number);

    for(std::size_t i = 0; i < R.get_size(); ++i) {
        if(!(fr.float_reading(f) && fr.char_reading(c))) {
            return false;
        }
        R(i) = f;
    }

    return true;
}

template <typename T>
bool Write_SLE_Solution(File_Writer& fw,const Result<T>& X)
{
    if(!(fw.char_writing('#') && fw.sizet_writing(X.get_number()) && fw.char_writing('\n'))) {
        return false;
    }

    if(!(fw.string_writing(X.get_state()) && fw.char_writing('\n'))) {
        return false;
    }

    if('N' == X.get_state()[0]) {
        if(!fw.char_writing('\n')) {
            return false;
        }
        return true;
    }

    if(!(fw.string_writing("X(") && fw.float_writing(X.get_rows()) &&
         fw.char_writing('x') && fw.float_writing(X.get_columns()) &&
         fw.string_writing(")\n"))) {
        return false;
    }

    for(std::size_t i = 0; i < X.get_size(); ++i) {
        if(!(fw.float_writing(X(i)) && fw.string_writing(", "))) {
            return false;
        }
    }

    if(!fw.string_writing("\n\n")) {
        return false;
    }

    return true;
}
