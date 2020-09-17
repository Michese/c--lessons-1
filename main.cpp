#include "matrix.h"

int main()
{
    Matrix matr1(3, 2);
    matr1.set(4.0, 0, 0);
    matr1.set(2.0, 0, 1);
    matr1.set(3.0, 1, 0);
    matr1.set(1.0, 1, 1);
    matr1.set(1.0, 2, 0);
    matr1.set(1.0, 2, 1);
    matr1.print();

    cout << endl;

    Matrix matr2(3,3);
    matr2.set(5.0, 0, 0);
    matr2.set(2.0, 0, 1);
    matr2.set(2.0, 0, 2);
    matr2.set(3.0, 1, 0);
    matr2.set(1.0, 1, 1);
    matr2.set(1.0, 1, 2);
    matr2.set(1.0, 2, 0);
    matr2.set(1.0, 2, 1);
    matr2.set(0.0, 2, 2);
    matr2.print();

    cout << endl;

    Matrix matr3;
    matr3 = matr1 + matr2;
    matr3.print();
}