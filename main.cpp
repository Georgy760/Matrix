#include "headers/Matrix.h"
#include "headers/file_reader.h"
#include "headers/file_writer.h"
#include "headers/gaussian_elimination.h"
#include "headers/utility.h"
#include "headers/rational.h"

#include <iostream>
template <typename T>
void TerminalMatrix();
template <typename T>
void FileMatrix();
template <typename T>
void Debug();

using namespace std;
int main() {

    //setlocale(LC_ALL, "Ru-ru");
    std::cout << "Enter input method\n"
                 "\n1) Enter matrix by terminal.\n2) Read from file.\n";
    int method;
    bool selected = false;
    while (!selected)
    {
        std::cin >> method;
        switch (method) {
            case 1:
                selected = true;
                TerminalMatrix<T>();
                break;
            case 2:
                selected = true;
                FileMatrix();
                std::cout << "\nYour matrix from file\n";
                break;
            case 3:
                Debug();
            default:
                std::cout << "\nYou selected wrong method, try again\n";
                break;
        }
    }
    return 0;
}
template <typename T>
void FileMatrix() {
    File_Writer FW_G("../Data/SLE_Gauss_Solutions.txt");
    Matrix<T> A, B;
    Result<T> X;
    float epsilon = 0.0001;

    {
        File_Reader FR_SLE("../Data/SLE.txt");
        while(Read_SLE(FR_SLE, A, B)) {
            Gaussian_Elimination(A, B, X, epsilon);
            Write_SLE_Solution(FW_G, X);
        }
        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Gauss_Solutions.txt\" file (Data folder)!\n";
    }
}

template <typename T>
void TerminalMatrix() {
    File_Writer FW_G("../Data/SLE_Gauss_Solutions.txt");
    int rows, columns;
    std::cout << "\nEnter matrix A size: (rows, columns)\n";
    std::cin >> rows >> columns;
    Matrix<T> A(rows, columns);
    for(int i = 0; i<rows; i++){
        std::cout << "\n";
        for(int j = 0; j<columns; j++){
            std::cin >> A(i,j);
        }
    }
    std::cout << "Matrix A:\n";
    A.Print();
    std::cout << "\nEnter matrix B size: (rows, columns)\n";
    std::cin >> rows >> columns;
    Matrix<T> B(rows, columns);
    for(int i = 0; i<rows; i++){
        std::cout << "\n";
        for(int j = 0; j<columns; j++){
            std::cin >> B(i,j);
        }
    }
    std::cout << "Matrix B:\n";
    B.Print();

    Result<T> X;

    float epsilon = 0.0001;

    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);

        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Gauss_Solutions.txt\" file (Data folder)!\n";
    }
}

template <typename T>
void Debug() {

    Matrix<T> A(2,2);
    cin >> A;
    cout << A;

    /*std::cout << "\nEnter rational A: (numerator, denominator)\n";
    int numerator, denominator;
    //std::cin >> numerator >> denominator;
    float tmpFloat;
    int tmpInt;
    rational A(0);
    cin >> A;

    //cout << "\nA: " << A.getNumerator() << "/" << A.getDenominator() << "\n";
    cout << A << "\n";
    tmpInt = A;
    tmpFloat = A;
    cout << tmpInt << " " << tmpFloat << "\n";
    std::cout << "\nEnter rational B: (numerator, denominator)\n";
    //std::cin >> numerator >> denominator;
    rational B(0);
    //cout << "\nB: " << B.getNumerator() << "/" << B.getDenominator() << "\n";
    cin >> B;
    cout << B << "\n";
    tmpInt = B;
    tmpFloat = B;
    cout << tmpInt << " " << tmpFloat << "\n";
    cout << "==: {}" << bool(A==B) << endl;
    cout << "!=: {}" << bool(A!=B) << endl;
    rational tests = A + B;
    cout << "+: {}" << tests.getNumerator() << "/" << tests.getDenominator() << endl;
    tests = A - B;
    cout << "-: {}" << tests.getNumerator() << "/" << tests.getDenominator() << endl;
    tests = A * B;
    cout << "*: {}" << tests.getNumerator() << "/" << tests.getDenominator() << endl;
    tests = A / B;
    cout << "/: {}" << tests.getNumerator() << "/" << tests.getDenominator() << endl;
*/

}
