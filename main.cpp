#include "headers/Matrix.h"
#include "headers/file_reader.h"
#include "headers/file_writer.h"
#include "headers/gaussian_elimination.h"
#include "headers/utility.h"

#include <iostream>

using namespace std;
int main() {

    //setlocale(LC_ALL, "Ru-ru");
    File_Writer FW_G("../Data/SLE_Gauss_Solutions.txt");
    Matrix A, B;
    Result X;
    float epsilon = 0.0001;

    {
        File_Reader FR_SLE("../Data/SLE.txt");
        while(Read_SLE(FR_SLE, A, B)) {
            Gaussian_Elimination(A, B, X, epsilon);
            Write_SLE_Solution(FW_G, X);
        }
        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Gauss_Solutions.txt\" file (Data folder)!\n";
    }
    return 0;
}
