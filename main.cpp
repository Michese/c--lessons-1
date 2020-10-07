#include <iostream> // Подключаем библиотеку для работы вводом-выводом в консоль
#include <vector>   // Подключаем библиотеку с классом vector
#include <cmath>    // Подключаем библиотеку для работы с математическими операциями

// Используем пространство имен std для упрощения записи std::cout и другие
using namespace std;
// объявление базового абстрактного класса
class BaseFunction
{
    // Обявленные под этим спецификатором доступа поля и методы класса могут быть вызваны только внутри этого класса и классов - наследников
protected:
    vector<double> a; // массив со всеми параметрами функции (a, b)
    int countParams;  // количество параметров функции, кроме x
    double x;         // переменная функции
    // Обявленные под этим спецификатором доступа поля и методы класса могут быть вызваны как внутри класса, так и вне его
public:
    // возвращает число, которое ввел пользователь. Если пользователь введет некорректное число,
    // в консоле появится ошибка и пользователь заного попытается ввести требующее число
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

    // задает параметры всем переменным
    void set()
    {
        char symbolParam = 'a';
        for (int count = 0; count < countParams; count++, symbolParam++)
        {
            a.push_back(getNumber(symbolParam));
        }
        x = getNumber('x');
    }
    // методы, реализованные в классах - наследниках
    virtual int getResult() = 0;
    virtual void print() = 0;
};
// объявление класса - наследника от BaseFunction
class Exponent : public BaseFunction
{
public:
    // конструктор по умолчанию
    Exponent()
    {
        countParams = 2;
    }
    // считает результат функции и возвращает его
    int getResult() override
    {
        return this->a[0] * exp(this->a[1] * this->x);
    }
    // выводит результат функции в консоль
    void print() override
    {
        cout << this->a[0] << " * exp^( " << this->a[1] << " * " << this->x << " ) = " << this->getResult() << endl;
    }
};
// объявление класса - наследника от BaseFunction
class Sine : public BaseFunction
{
public:
    // конструктор по умолчанию
    Sine()
    {
        countParams = 2;
    }
    // считает результат функции и возвращает его
    int getResult()
    {
        return this->a[0] * sin(this->x * this->a[1]);
    }
    // выводит результат функции в консоль
    void print() override
    {
        cout << this->a[0] << " * sin( " << this->a[1] << " * " << this->x << " ) = " << this->getResult() << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian"); // для работы с кириллицей
    int size = 0,                 // размерность вектора, которую задаст пользователь
        numberFunc;               // номер функции, который задаст пользователь

    cout << "Введите размерность вектора: ";
    cin >> size;
    BaseFunction **vector = new BaseFunction *[size]; // обяъвляем вектор - функцию
    while (true)
    {
        numberFunc = 0;
        cout << "Введите число соответствующее номеру нужной Вам функции:" << endl;
        cout << "1) a * Sin ( b * x );" << endl;
        cout << "2) a * exp^( b * x )." << endl;

        cin >> numberFunc;
        if (numberFunc >= 1 && numberFunc <= 2) // условие выхода из цикла while
        {
            break;
        }
    }
    if (numberFunc == 1) // sin
    {
        for (int count = 0; count < size; count++)
        {
            vector[count] = new Sine();
        }
    }
    else if (numberFunc == 2) // exp
    {
        for (int count = 0; count < size; count++)
        {
            vector[count] = new Exponent();
        }
    }
    for (int count = 0; count < size; count++)
    {
        vector[count]->set();   // задаем значения параметрам
        vector[count]->print(); // выводим результат функции в консоль
    }
    for (int count = 0; count < size; count++) // освобождаем динамически выделенную память
    {
        delete[] vector[count];
    }
    delete[] vector;

    return 0;
}