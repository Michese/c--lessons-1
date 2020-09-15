#include "matrix.h"

int main()
{
    vector<vector<double>>arr(3, vector<double>(3));
    arr[0][0] = 225.12922222;
    arr[0][2] = 225.12922222;
    Matrix matr(arr);
    matr.print();
    // double **matrix = new double *[5];
    // for (int row = 0; row < 5; row++)
    //     matrix[row] = new double[5];

    // for (int row = 0; row < 5; row++)
    // {
    //     for (int column = 0; column < 5; column++)
    //     {
    //         matrix[row][column] = 3.1;
    //     }
    // }

    //     for (int row = 0; row < 5; row++)
    // {
    //     for (int column = 0; column < 5; column++)
    //     {
    //         cout << matrix[row][column] << ' ';
    //     }
    //     cout << endl;
    // }

    // for (int count = 0; count < 5; count++)
    //     delete[] matrix[count];
    // delete[] matrix;
}