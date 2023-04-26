#include "headers/Matrix.h"
#include "headers/file_writer.h"
#include "headers/gaussian_elimination.h"
#include "headers/utility.h"
#include "headers/rational.h"

#include <iostream>
#include <sstream>

void TerminalMatrix();

void FileMatrix();

using namespace std;

int main() {
    cout << "Enter input method\n"
                 "\n1) Enter matrix by terminal.\n2) Read from file.\n";
    int method;
    bool selected = false;
    while (!selected) {
        cin >> method;
        switch (method) {
            case 1:
                selected = true;
                TerminalMatrix();
                break;
            case 2:
                selected = true;
                FileMatrix();
                cout << "\nYour matrix from file\n";
                break;
            default:
                cout << "\nYou selected wrong method, try again\n";
                break;
        }
    }
    return 0;
}

void FileMatrix() {
    ifstream infile("../Data/A.txt");
    string line_A;
    getline(infile, line_A);
    stringstream line_stream(line_A);
    int columns_A = 0;
    float value_A;
    while (line_stream >> value_A) {
        columns_A++;
    }

    infile.clear();
    infile.seekg(0, ios::beg);
    int rows_A = 0;
    while (getline(infile, line_A)) {rows_A++;}
    Matrix A(rows_A, columns_A);
    infile.clear();
    infile.seekg(0, ios::beg);
    infile >> A;

    ifstream infile_B("../Data/B.txt");
    string line_B;
    getline(infile_B, line_B);
    stringstream line_stream_B(line_B);
    int columns_B = 0;
    float value_B;
    while (line_stream_B >> value_B) {
        columns_B++;
    }
    infile_B.clear();
    infile_B.seekg(0, ios::beg);
    int rows_B = 0;
    while (getline(infile_B, line_B)) {rows_B++;}

    Matrix B(rows_B, columns_B);
    infile_B.clear();
    infile_B.seekg(0, ios::beg);
    infile_B >> B;
    if (B.get_columns() > 1) B = B.Transpose();
    cout << A;
    cout << B;

    File_Writer FW_G("../Data/SLE_Solution.txt");
    Result X;
    float epsilon = 0.0001;
    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);
        cout << "The result for Gaussian Elimination is presented in \"SLE_Solution.txt\" file (Data folder)!\n";
    }
}

void TerminalMatrix() {
    File_Writer FW_G("../Data/SLE_Solution.txt");
    int rows, columns;
    cout << "\nEnter matrix A size: (rows, columns)\n";
    cin >> rows >> columns;
    Matrix A(rows, columns);
    A.set_number(1);
    cin >> A;
    cout << "Matrix A:\n";
    A.Print();
    cout << "\nEnter matrix B size: (rows, columns)\n";
    cin >> rows >> columns;
    Matrix B(rows, columns);
    B.set_number(2);
    cin >> B;
    cout << "Matrix B:\n";
    B.Print();
    if (B.get_columns() > 1) B = B.Transpose();
    Result X;
    X.set_number(1);
    float epsilon = 0.0001;
    {
        Gaussian_Elimination(A, B, X, epsilon);
        Write_SLE_Solution(FW_G, X);
        cout << "The result for Gaussian Elimination is presented in \"SLE_Solution.txt\" file (Data folder)!\n";
    }
    cout << "Result: "<< X.get_state() << "\n";
    X.Print();
}