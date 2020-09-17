#include "matrix.h"

int main()
{
    Matrix matr1(3, 3);
    matr1.set(3.3, 0, 1);
    matr1.set(3.3, 0, 2);
    matr1.set(3.4, 2, 1);
    matr1.print();

    cout << endl;

    Matrix matr2(matr1);
    matr2.set(0.23, 1, 0);
    matr2.print();

    cout << endl;

    Matrix matr3(3, 3);
    matr3.print();

    cout << endl;

    matr3 = matr1/4.4;
    matr3.print();

    cout << endl;

    Matrix matr4;
    double num = 3.3;
    matr4 = matr1/num;
    matr4.print();
}