//
// Created by gosha on 10/26/2022.
//

#ifndef MATRIX_UTILITY_H
#define MATRIX_UTILITY_H



#include "file_reader.h"
#include "Matrix.h"
#include "file_writer.h"

#include <string>

template <typename T>
bool Read_SLE(File_Reader&, Matrix<T>&, Matrix<T>&);

//The class Result describes the solution of a system of linear equations.
//The function simply reads the solution data and assigns it to the corresponding class Result object.
template <typename T>
bool Read_Result(File_Reader&, Result<T>&);
template <typename T>
bool Write_SLE_Solution(File_Writer&, const Result<T>&);



#endif //MATRIX_UTILITY_H
