#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix
{
protected:
    int currentColumns;
    int currentRows;
    double **matrix;

    static const int DEFAULT_COLUMNS = 5;
    static const int DEFAULT_ROWS = 5;
    static const double DEFAULT_VALUES;

public:
    Matrix(int rows, int columns)
    {
        this->currentColumns = columns;
        this->currentRows = rows;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                this->set(0.0, row, column);
            }
        }
    }
    Matrix()
    {
        this->currentColumns = Matrix::DEFAULT_COLUMNS;
        this->currentRows = Matrix::DEFAULT_ROWS;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                this->set(0.0, row, column);
            }
        }
    }
    Matrix(Matrix &otherMatrix)
    {
        this->currentColumns = otherMatrix.getCurrentColumns();
        this->currentRows = otherMatrix.getCurrentRows();

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(otherMatrix.get(row, column), row, column);
            }
        }
    }
    Matrix(double **matrix, int rows, int columns)
    {
        this->currentColumns = columns;
        this->currentRows = rows;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(matrix[row][column], row, column);
            }
        }
    }
    Matrix(vector<vector<double>> matrix)
    {
        try
        {
            this->currentColumns = matrix.size();
            this->currentRows = matrix[0].size();

            this->matrix = new double *[this->currentRows];
            for (int row = 0; row < this->currentRows; row++)
                this->matrix[row] = new double[this->currentColumns];

            for (int row = 0; row < this->currentRows; row++)
            {
                for (int column = 0; column < this->currentColumns; column++)
                {
                    this->set(matrix[row][column], row, column);
                }
            }
        }
        catch (...)
        {
            cout << "Error. Values in vector not found!" << endl;
            cout << "Create default matrix." << endl;
            Matrix();
        }
    }
    ~Matrix()
    {
        for (int count = 0; count < this->currentRows; count++)
            free(this->matrix[count]);
        free(this->matrix);
    }
    double *operator[](const int row)
    {
        return this->matrix[row];
    }
    Matrix operator=(Matrix &otherMatrix)
    {
        for (int count = 0; count < this->currentRows; count++)
            delete[](this->matrix[count]);
        delete[](this->matrix);

        this->currentColumns = otherMatrix.getCurrentColumns();
        this->currentRows = otherMatrix.getCurrentRows();

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(otherMatrix.get(row, column), row, column);
            }
        }
        return *this;
    }
    friend Matrix &operator/(Matrix &otherMatrix, double number);
    friend Matrix &operator+(Matrix &otherMatrix, double number);
    friend Matrix &operator+(Matrix &firstMatrix, Matrix &secondMatrix);
    friend Matrix &operator-(Matrix &firstMatrix, Matrix &secondMatrix);
    friend Matrix &operator*(Matrix &firstMatrix, Matrix &secondMatrix);
    friend Matrix &operator*(Matrix &otherMatrix, double number);
    double get(int row, int column)
    {
        double result;
        try
        {
            if (row >= this->currentRows || row < 0 || column >= this->currentColumns || column < 0)
            {
                throw "Error. Array element not found";
            }
            result = this->matrix[row][column];
        }
        catch (...)
        {
            result = 0.0;
        }

        return result;
    }
    int getCurrentRows()
    {
        return this->currentRows;
    }
    int getCurrentColumns()
    {
        return this->currentColumns;
    }
    bool set(double value, int row, int column)
    {
        bool result;
        try
        {
            this->matrix[row][column] = value;
            result = true;
        }
        catch (...)
        {
            result = false;
        }
        return result;
    }
    void print()
    {
        cout << setprecision(5);
        for (int row = 0; row < this->currentRows; row++)
        {
            cout << "| ";
            for (int column = 0; column < this->currentColumns; column++)
            {
                cout << setfill(' ') << setw(7) << this->matrix[row][column] << ' ';
            }
            cout << '|' << endl;
        }
    }
};

const double Matrix::DEFAULT_VALUES = 0.0;

Matrix &operator/(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) / number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}

Matrix &operator+(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) + number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}

Matrix &operator+(Matrix &firstMatrix, Matrix &secondMatrix)
{
    int rows = (firstMatrix.getCurrentRows() > secondMatrix.getCurrentRows()) ? firstMatrix.getCurrentRows() : secondMatrix.getCurrentRows();
    int columns = (firstMatrix.getCurrentColumns() > secondMatrix.getCurrentColumns()) ? firstMatrix.getCurrentColumns() : secondMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = firstMatrix.get(row, column) + secondMatrix.get(row, column);
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

Matrix &operator-(Matrix &firstMatrix, Matrix &secondMatrix)
{
    int rows = (firstMatrix.getCurrentRows() > secondMatrix.getCurrentRows()) ? firstMatrix.getCurrentRows() : secondMatrix.getCurrentRows();
    int columns = (firstMatrix.getCurrentColumns() > secondMatrix.getCurrentColumns()) ? firstMatrix.getCurrentColumns() : secondMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (firstMatrix.get(row, column) == 0 && secondMatrix.get(row, column) == 0)
            {
                newArray[row][column] = 0.0;
            }
            else
            {
                newArray[row][column] = firstMatrix.get(row, column) - secondMatrix.get(row, column);
            }
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

Matrix &operator*(Matrix &firstMatrix, Matrix &secondMatrix)
{
    if (firstMatrix.getCurrentColumns() != secondMatrix.getCurrentRows() || firstMatrix.getCurrentRows() != secondMatrix.getCurrentColumns())
    {
        Matrix *newMatrix = new Matrix();
        return *newMatrix;
    }
    int rows = firstMatrix.getCurrentRows();
    int columns = firstMatrix.getCurrentRows();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = 0.0;
            for (int index = 0; index < firstMatrix.getCurrentColumns(); index++)
            {
                newArray[row][column] += firstMatrix.get(row, index) * secondMatrix.get(index, column);
            }
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

Matrix &operator*(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) * number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}