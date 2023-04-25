#include "headers/Matrix.h"
#include "headers/file_writer.h"
#include "headers/gaussian_elimination.h"
#include "headers/utility.h"
#include "headers/rational.h"

#include <iostream>
#include <sstream>

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

    std::ifstream infile("../Data/A.txt");

    // read first line to get number of columns
    std::string line;
    std::getline(infile, line);
    std::stringstream line_stream(line);
    int columns = 0;
    float value;
    while (line_stream >> value) {
        columns++;
    }

    // rewind file and count number of rows
    infile.clear();
    infile.seekg(0, std::ios::beg);
    int rows = 0;
    while (std::getline(infile, line)) {
        rows++;
    }

    // create Matrix with correct size
    Matrix A(rows, columns);

    // read values from file into Matrix
    infile.clear();
    infile.seekg(0, std::ios::beg); //sets the file position pointer to the beginning of the file infile.
    infile >> A;


    std::ifstream infile_B("../Data/B.txt");

    // read first line to get number of columns
    std::string line_B;
    std::getline(infile_B, line_B);
    std::stringstream line_stream_B(line_B);
    int columns_B = 0;
    float value_B;
    while (line_stream_B >> value_B) {
        columns_B++;
    }

    // rewind file and count number of rows
    infile_B.clear();
    infile_B.seekg(0, std::ios::beg); //sets the file position pointer to the beginning of the file infile.
    int rows_B = 0;
    while (std::getline(infile_B, line_B)) {
        rows_B++;
    }

    // create Matrix with correct size
    Matrix B(rows_B, columns_B);

    // read values from file into Matrix
    infile_B.clear();
    infile_B.seekg(0, std::ios::beg);
    infile_B >> B;
    if(B.get_columns() > 1) B = B.Transpose();
    cout << A;
    cout << B;

    File_Writer FW_G("../Data/SLE_Solution.txt");
    Result X;

    float epsilon = 0.0001;

    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);

        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Solution.txt\" file (Data folder)!\n";
    }
}

void TerminalMatrix() {
    File_Writer FW_G("../Data/SLE_Solution.txt");
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

        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Solution.txt\" file (Data folder)!\n";
    }
}

void Debug() {

    Matrix A(2,2);
    cout << "Enter Matrix 2x2\n";
    cin >> A;
    cout <<"Matrix A:\n" << A << "\n";
    Matrix B(2,1);
    cout << "Enter Matrix 2x2\n";
    cin >> B;
    cout <<"Matrix B:\n" << B << "\n";

    File_Writer FW_G("../Data/SLE_Solution.txt");
    Result X;

    float epsilon = 0.0001;

    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);

        std::cout << "The result for Gaussian Elimination is presented in \"SLE_Solution.txt\" file (Data folder)!\n";
    }
    /*std::cout << "\nEnter rational A: (numerator, denominator)\n";
    int numerator, denominator;
    //std::cin >> numerator >> denominator;
    rational A(0);
    cin >> A;
    //cout << "\nA: " << A.getNum() << "/" << A.getDenom() << "\n";
    cout << A;
    std::cout << "\nEnter rational B: (numerator, denominator)\n";
    //std::cin >> numerator >> denominator;
    rational B(0);
    //cout << "\nB: " << B.getNum() << "/" << B.getDenom() << "\n";
    cin >> B;
    cout << B;
    cout << "==: {}" << bool(A==B) << endl;
    cout << "!=: {}" << bool(A!=B) << endl;
    rational tests = A + B;
    cout << "+: {}" << tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A - B;
    cout << "-: {}" << tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A * B;
    cout << "*: {}" <<  tests.getNum() <<"/"<<tests.getDenom() << endl;
    tests = A / B;
    cout << "/: {}" <<  tests.getNum() <<"/"<<tests.getDenom() << endl;*/


}
