#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include <exception>
#include <string>
#include "Exception.cpp"
using namespace std;
const double eps = 1e-9;
template <typename temp>
class BaseMatrix
{
protected:
    temp** arr;
    int row, columns;
public:
    BaseMatrix(int r = 2, int cl = 2) : row(r), columns(cl) //Construct
    {
        //cout << "BaseMatrixConstructing\n";
        if (row <= 0 || columns <= 0)
        {
            throw WrongSizeException("Matrix size error", row, columns);
        }

        //создание массива
        arr = new temp * [row];

        for (int i = 0; i < row; ++i)
        {
            arr[i] = new temp[columns];
        }
    }

    BaseMatrix(const BaseMatrix& matrix) //Construct
    {
        //cout << "BaseMatrixConstructing\n";
        row = matrix.row;
        columns = matrix.columns;


        arr = new temp * [row];

        for (int i = 0; i < row; ++i)
        {
            arr[i] = new temp[columns];
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                arr[i][j] = matrix.arr[i][j];
            }
        }
    }

    virtual ~BaseMatrix()
    {
        //cout << "BaseMatrix_Destructing\n";
        if (arr != nullptr)
        {
            for (int i = 0; i < row; ++i)
            {
                delete[] arr[i];
            }
            delete[] arr;
            arr = nullptr;
        }
    } //Destruct

    virtual void print()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                cout << std::left << std::setw(9) << std::setprecision(3) << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    BaseMatrix& operator=(const BaseMatrix& mtr)
    {
        if (this != &mtr)
        {
            if (arr != nullptr)
            {
                for (int i = 0; i < row; ++i)
                    delete[] arr[i];
                delete[] arr;
            }

            row = mtr.row;
            columns = mtr.columns;

            arr = new temp * [row];
            for (int i = 0; i < row; i++)
            {
                arr[i] = new temp[columns];
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < columns; j++)
                {
                    arr[i][j] = mtr.arr[i][j];
                }
            }
        }
        else
        {
            return *this;
        }
    }


    virtual temp& operator()(int rw, int cln) const
    {
        if (rw < 0 || cln < 0 || rw > row || cln > columns)
        {
            throw IndexOutOfBoundsException("Index access error -> ", rw, cln);
        }
        return arr[rw][cln];
    }

/*
    template<typename T1>
    friend ostream& operator<<(ostream& out, BaseMatrix<T1>& matrix)
    {
        if (typeid(out) != typeid(ofstream))
        {
            for (int i = 0; i < matrix.row; i++)
            {
                for (int j = 0; j < matrix.columns; j++)
                {
                    out << matrix.arr[i][j] << " ";
                }

                out << "\n";
            }
        }
        else
        {
            out << " " << matrix.row << " " << matrix.columns << " ";

            for (int i = 0; i < matrix.row; i++)
            {
                for (int j = 0; j < matrix.columns; j++)
                {
                    out << matrix.arr[i][j];

                    if (matrix.row != i + 1 || matrix.columns != j + 1)
                    {
                        out << " ";
                    }
                }
            }
        }

        return out;
    }

    template<typename T1>
    friend istream& operator>>(istream& in, BaseMatrix<T1> matrix)
    {
        if (typeid(in) != typeid(ifstream))
        {
            for (int i = 0; i < matrix.row; i++)
            {
                for (int j = 0; j < matrix.columns; j++)
                {
                    try
                    {
                        in >> matrix.arr[i][j];
                    }
                    catch (...)
                    {
                        cout << "Invalid input\n";
                    }
                }
            }
        }
        else
        {
            int row, columns;

            in >> row >> columns;

            if (row == matrix.row && columns == matrix.columns)
            {
                for (int i = 0; i < matrix.row; i++)
                {
                    for (int j = 0; j < matrix.columns; j++)
                    {
                        try
                        {
                            in >> matrix.arr[i][j];
                        }
                        catch (...)
                        {
                            cout << "Invalid input\n";
                        }
                    }
                }

            }
            else {
                if (in.eof()) {
                    cout << "No items\n";
                }
                else {
                    cout << "Sizes don't match\n";
                }

            }
        }

        return in;
    }
*/
};


template<typename T1>
class Matrix : public BaseMatrix<T1>
{
public:
    Matrix(int row = 2, int columns = 2) : BaseMatrix<T1>(row, columns) {
        //cout << "MatrixConstructing\n";
    }

    Matrix(istream& in)
    {
        //cout << "MatrixConstructing\n";
        in >> this->row >> this->columns;

        if (this->row <= 0 || this->columns <= 0)
        {
            throw WrongSizeException("Matrix size error -> ", this->row, this->columns);
        }

        this->arr = new T1 * [this->row];

        for (int i = 0; i < this->row; ++i)
        {
            this->arr[i] = new T1[this->columns];
        }

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                in >> this->arr[i][j];
            }
        }
    }
    ~Matrix()
    {
        //cout << "Matrix_Destructing\n";
        if (this->arr != nullptr)
        {
            for (int i = 0; i < this->row; ++i)
            {
                delete[] this->arr[i];
            }
            delete[] this->arr;
            this->arr = nullptr;
        }
    } //Destruct
    int getRows(){
        return this->row;
    }
    int getColumns(){
        return this->columns;
    }
    void rewrite_matrix(istream& in)
    {
        if (this->arr != nullptr)
        {
            for (int i = 0; i < this->row; ++i)
            {
                delete[] this->arr[i];
            }
            delete[] this->arr;
            this->arr = nullptr;
        }

        in >> this->row >> this->columns;

        if (this->row <= 0 || this->columns <= 0)
        {
            throw WrongSizeException("Matrix size error -> ", this->row, this->columns);
        }

        this->arr = new T1 * [this->row];
        for (int i = 0; i < this->row; ++i)
        {
            this->arr[i] = new T1[this->columns];
        }

        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                in >> this->arr[i][j];
            }
        }
    }

    Matrix<T1> RowMultiy(T1 num, int row){
        for (int i = 0; i < this->columns; ++i)
        {
            this(row, i) *= num;
        }
        return this;
    }

    Matrix<T1> Sum_Vector()
    {
        T1* tmp = new T1[this->row]; //массив суммы значений из каждой строки матрицы
        T1 sum = 0;
        for (int i = 0; i < this->row; ++i)
        {
            tmp[i] = 0;
        }

        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->columns; j++)
            {
                tmp[i] = tmp[i] + this->arr[i][j];
            }

        }

        Matrix<T1> answer(this->row, 1); //матрица ответа

        for (int i = 0; i < answer.row; ++i)
        {
            answer.arr[i][0] = tmp[i]; //заполняем матрицу ответа
        }

        delete[] tmp; //очищаем массив суммы значений

        return answer;
    }



    void RandomNums()
    {
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {
                this->arr[i][j] = (T1)((rand() % 100));
            }
        }
    }

    virtual void print()
    {
        cout << endl;
        for (int i = 0; i < this->row; ++i)
        {
            for (int j = 0; j < this->columns; ++j)
            {

                cout << std::left << std::setw(9) << std::setprecision(3) << this->arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void swapRows (int index1, int index2) //Поменять местами две строки
    {
        if (index1 < 0 || index2 < 0 || index1 >= this->row || index2 >= this->row)
            return ;
        for (int i = 0; i < this->columns; ++ i)
            swap (this->arr[index1][i], this->arr[index2][i]);
        //this->print();
    }

    void swapColumns (int index1, int index2) //Поменять местами два столбца
    {
        if (index1 < 0 || index2 < 0 || index1 >= this->columns || index2 >= this->columns)
            return ;
        for (int i = 0; i < this->row; ++ i)
            swap (this->arr[i][index1], this->arr[i][index2]);
        //this->print();
    }

    Matrix<T1> gauss(){ //Приведение матрицы к треугольному виду, метод Гаусса  с главным элементом
        cout << "gauss\n";
        int i, j, k;
        T1 countSwaps = 1;
        Matrix<T1> a = *this;
        for(i = 0; i < this->row; ++ i){
            //Находим строку с максимальным первым элементом
            int iMax = i;
            for (j = i + 1; j < this->row; ++ j)
                if (abs (a.arr[j][i]) > abs (a.arr[iMax][i]))
                    iMax = j;
            if (abs (a.arr[iMax][i]) < eps)
                continue;
            for (k = 0; k < this->columns; ++ k)
                swap (a.arr[i][k], a.arr[iMax][k]);
            countSwaps = - countSwaps * (i != iMax ? 1 : - 1);

            //  вычитаем текущую строку из всех остальных
            for (j = i + 1; j < this->row; ++ j)
            {
                double q = - a.arr[j][i] / a.arr[i][i];
                for (k = this->columns - 1; k >= i; -- k)
                    a.arr[j][k] += q * a.arr[i][k];
            }
            cout << "iMax: " << iMax << endl;
        }
        // умножаем матрицу на -1, если мы сделали  нечётное количество перестановок строк
        // в итоге определитель результирующей матрицы  будет равен определителю начальной матрицы
        cout << "gauss result\n";
        a = countSwaps * a;
        a.print();
        return a;
    }
};


/*template<typename T>
Matrix<T> operator*(const int a, const Matrix<T>& b){
    Matrix<T> tempMat = b;
    for(int row = 0; row < tempMat.getRows(); row++){
        for(int column = 0; column < tempMat.getColumns(); column++){
            tempMat(row,column) *= a;
        }
    }
    return tempMat;
}*/

template<typename T>
Matrix<T> operator*(const T a, const Matrix<T>& b){
    Matrix<T> tempMat = b;
    for(int row = 0; row < tempMat.getRows(); row++){
        for(int column = 0; column < tempMat.getColumns(); column++){
            tempMat(row,column) *= a;
        }
    }
    return tempMat;
}

/*template<typename T>
Matrix<T> operator*(const Matrix<T>& b, const int a){
    Matrix<T> tempMat = b;
    for(int row = 0; row < tempMat.getRows(); row++){
        for(int column = 0; column < tempMat.getColumns(); column++){
            tempMat(row,column) *= a;
        }
    }
    return tempMat;
}*/

template<typename T>
Matrix<T> operator*(const Matrix<T>& b, const T a){
    Matrix<T> tempMat = b;
    for(int row = 0; row < tempMat.getRows(); row++){
        for(int column = 0; column < tempMat.getColumns(); column++){
            tempMat(row,column) *= a;
        }
    }
    return tempMat;
}


template <typename T>
class Sole{
private:
    int rows;
    int columns; //unknowns
    Matrix<T> A, B;
public:
    Sole(Matrix<T> a, Matrix<T> b){
        /*if(b.getColumns() > 1){
            throw WrongSizeOfMatrixB("Matrix B have more than 1 colunm of coefs", )
        }*/
        if(a.getRows() != b.getRows()){
            throw WrongSizeExceptionOfTwoMatrixs("Matrix size error -> ", a.getRows(), b.getRows());
        } else {
            A = a;
            B = b;
            rows = a.getRows();
            columns = a.getColumns();
        }
    }
    void FindSolution(){
        T sum = 0;
        for(int column = 0; column < columns; column++) {
            sum += B(0,column);
        }
         if(sum == 0){
             cout << "\nHomogeneous solution";
         }
         if(sum != 0){
             cout << "\nInhomogeneous solution";
         }
     }

    void print(){
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                cout << A(row, column) << "x_" << column+1 << " ";
            }
            cout << " = " << B(row, 0) << "\n";
        }
    }

    Matrix<T> GetExtendedMatrix(){ //расширенная матрица
        Matrix<T> newMatrix(rows, columns + 1);
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                newMatrix(row, column) = A(row,column);
            }
            newMatrix(row, columns +1) = B(row, 0);
        }
        return newMatrix;
    }
};

int main() {
    setlocale(LC_ALL, "Ru-ru");
    //setlocale(LC_ALL, "Russian");

    //ofstream out("OutPut.txt");

    //TODO
    /*
     * Добавить методы решения
     * Проверку наличия .txt, генирить если их нет
     * http://mathdep.ifmo.ru/mathdep1/wp-content/uploads/2018/09/5.-%D0%A1%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D1%8B-%D0%BB%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D1%85-%D1%83%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D0%B9-%D0%B8-%D0%BC%D0%B5%D1%82%D0%BE%D0%B4%D1%8B-%D0%B8%D1%85-%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%B8%D1%8F.pdf
     */
    ifstream inA("MatrixA.txt");
    ifstream inB("MatrixB.txt");
    Matrix<double> A(inA);
    A.print();
    Matrix<int> B(inB);
    B.print();
    cout << "\nMatrix added\n" ;
    A.gauss();
    //A.swapRows(0, 1);
    //A.swapColumns(0, 1);
    A.print();
    //Matrix<double> newMatrix = A&;
    //cout << "\nТест\n";
    //Sole<int>  newSole(A,B);
    //newSole.print();

    //Matrix<int> newMatrix = newSole.GetExtendedMatrix();
    //newMatrix.print();
    /*newSole.FindSolution();
    newMatrix = 4 * newMatrix;
    newMatrix.print();
    newMatrix = newMatrix*4;
    newMatrix.print();
    newSole.FindSolution();*/
    return 0;
}
