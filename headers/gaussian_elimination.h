//
// Created by gosha on 10/26/2022.
//

#ifndef MATRIX_GAUSSIAN_ELIMINATION_H
#define MATRIX_GAUSSIAN_ELIMINATION_H

#include "Matrix.h"
#include <string>


//solution of a system of linear equations by Gauss elimination
//1st input_parameter: System coefficients matrix (A)
//2nd input_parameter: vector (B)
//3rd output_parameter: solution vector (X)
//4th input_parameter: epsilon. epsilon is necessary to take into account the behavioral deviations of float number.
template <typename T>
void Gaussian_Elimination(Matrix<T>&, Matrix<T>&, Result<T>&, float);

#endif //MATRIX_GAUSSIAN_ELIMINATION_H
