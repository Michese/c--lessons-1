#include <vector>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
class Function
{
protected:
    int a, b, c, x;

public:
    int getNumber()
    {
        return rand() % 10 + 1;
    }
    virtual void setParams() = 0;
    virtual int result() = 0;
    virtual void print() = 0;
};

class logarithm : public Function
{
public:
    void setParams() override
    {
        cout << "Введите значение параметров:" << endl;
        cout << "a = ";
        a = getNumber();

        cout << "b = ";
        b = getNumber();

        cout << "c = ";
        c = getNumber();

        cout << "x = ";
        c = getNumber();
    }
    int result() override
    {
        return a * log(b * x) + c;
    }
    void print() override
    {
        cout << a << " * lg ( " << b << " * " << x << " ) + " << c << " = " << result() << endl;
    }
};

class Сosine : public Function
{
public:
    int result() override
    {
        return a * sin(x * b) + c;
    }
    void print() override
    {
        cout << a << " * Cos ( " << b << " * " << x << " ) + " << c << " = " << result() << endl;
    }
    void setParams() override
    {
        cout << "Введите значение параметров:" << endl;
        cout << "a = ";
        a = getNumber();

        cout << "b = ";
        b = getNumber();

        cout << "c = ";
        c = getNumber();

        cout << "x = ";
        c = getNumber();
    }
};

int main()
{
    srand(time(NULL));
    cout << "Введите размерность вектор-функции: ";
    int N = 0,number = 0;
    cin >> N;
    vector<Function> y(N);
    Function *func;
    bool isWin = true;
    while (isWin) {
    cout << "Введите номер функции, результаты которой хотите посчитать:" << endl;
    cout << "1. a * cos ( b * x ) + c" << endl;
    cout << "2. a * lg ( b * x ) + c" << endl;
    cin >> number;
    switch(number) {
        case 1:
        func = Cosine;
        
    }
    }

    for (int i = 0; i < N; i++)
    {
        y[i]
    }
    

    system("pause");
    return 0;
}