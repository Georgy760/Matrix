#include "headers/Matrix.h"
#include "headers/file_reader.h"
#include "headers/file_writer.h"
#include "headers/gaussian_elimination.h"
#include "headers/utility.h"
#include "headers/rational.h"

#include <iostream>

void TerminalMatrix();

void FileMatrix();

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
                TerminalMatrix();
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

void FileMatrix() {
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
}

void TerminalMatrix() {
    File_Writer FW_G("../Data/SLE_Gauss_Solutions.txt");
    int rows, columns;
    std::cout << "\nEnter matrix A size: (rows, columns)\n";
    std::cin >> rows >> columns;
    Matrix A(rows, columns);
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
    Matrix B(rows, columns);
    for(int i = 0; i<rows; i++){
        std::cout << "\n";
        for(int j = 0; j<columns; j++){
            std::cin >> B(i,j);
        }
    }
    std::cout << "Matrix B:\n";
    B.Print();

    Result X;

    float epsilon = 0.0001;

    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);

        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Gauss_Solutions.txt\" file (Data folder)!\n";
    }
}

void Debug() {
    std::cout << "\nEnter rational A: (numerator, denominator)\n";
    int numerator, denominator;
    std::cin >> numerator >> denominator;
    rational A(numerator, denominator);
    cout << "\nA: " << A.getNum() << "/" << A.getDenom() << "\n";
    std::cout << "\nEnter rational B: (numerator, denominator)\n";
    std::cin >> numerator >> denominator;
    rational B(numerator, denominator);
    cout << "\nB: " << B.getNum() << "/" << B.getDenom() << "\n";
    cout << "==: {}" << bool(A==B) << endl;
    cout << "!=: {}" << bool(A!=B) << endl;
    rational tests = A + B;
    cout << "+: {}" << tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A - B;
    cout << "-: {}" << tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A * B;
    cout << "*: {}" <<  tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A / B;
    cout << "/: {}" <<  tests.getNum() <<"/"<<tests.getDenom() << endl;


}
