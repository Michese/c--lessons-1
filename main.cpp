#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;
class BaseFunction
{
protected:
    vector<double> a;
    int countParams;
    double x;

public:
    double getNumber(char symbolOfNumber)
    {
        double result = 0.0;
        cout << "Введите значение параметра " << symbolOfNumber << ": ";
        try
        {
            cin >> result;
        }
        catch (...)
        {
            cout << "Не корректное значение параметра " << symbolOfNumber << '!' << endl;
            result = getNumber(symbolOfNumber);
        }

        return result;
    }
    void set()
    {
        char symbolParam = 'a';
        for (int count = 0; count < countParams; count++, symbolParam++)
        {
            a.push_back(getNumber(symbolParam));
        }
        x = getNumber('x');
    }
    void set(vector<double> params, double x)
    {
        if (this->countParams > params.size())
        {
            throw "Параметров не достаточно!";
        }
        for (int count = 0; count < countParams; count++)
        {
            this->a.push_back(params[count]);
        }
        this->x = x;
    }
    virtual int getResult() = 0;
    virtual void print() = 0;
};

class Exponent : public BaseFunction
{
public:
    Exponent()
    {
        countParams = 2;
    }
    int getResult() override
    {
        return this->a[0] * exp(this->a[1] * this->x);
    }
    void print() override
    {
        cout << this->a[0] << " * exp^( " << this->a[1] << " * " << this->x << " ) = " << this->getResult() << endl;
    }
};

class Sine : public BaseFunction
{
public:
    Sine()
    {
        countParams = 2;
    }
    int getResult()
    {
        return this->a[0] * sin(this->x * this->a[1]);
    }
    void print() override
    {
        cout << this->a[0] << " * sin( " << this->a[1] << " * " << this->x << " ) = " << this->getResult() << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int size = 0;
    bool flag = true;
    while (flag)
    {
        cout << "Введите размерность вектора: ";
        try
        {
            cin >> size;
            flag = false;
        }
        catch (...)
        {
            cout << "Не корректная размерность вектора!" << endl;
        }
    }
    cout << "Введите число соответствующее номеру нужной Вам функции:" << endl;

    BaseFunction **vector = new BaseFunction *[size];
    flag = true;
    while ()

        return 0;
}