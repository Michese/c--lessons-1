#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix
{
protected:
    int currentColumns;
    int currentRows;
    static const int COLUMNS = 5;
    static const int ROWS = 5;

public:
    double **matrix;
    Matrix()
    {
        int columns = Matrix::COLUMNS;
        int rows = Matrix::ROWS;
        Matrix(rows, columns);
    }
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
                Matrix::set(0.1, row, column);
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
            delete[](matrix[count]);
        delete[](matrix);
    }
    double get(int row, int column)
    {
        double result;
        try
        {
            result = this->matrix[row][column];
        }
        catch (...)
        {
            cout << "Error. Matrix[" << row << "][" << column << "] not found!" << endl;
            result = 0.0;
        }
        return result;
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