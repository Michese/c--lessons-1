#include <iostream> // библиотека для работы с консолью
#include <cmath> // библиотека для работы с математическими операциями
using namespace std; // для сокращения записи std::cout и т.п.

// объявление класса
class Function
{
    // спецификатор доступа protected. 
    // Поля и методы могут быть вызваны только внутри класса.
    // Наследуются.
protected:
    // параметры функции
    int a, b, c, x;
    // спецификатор доступа protected. 
    // Поля и методы могут быть вызваны только внутри класса.
    // Наследуются.
public:
    // конструктор класса по умолчанию.
    Function() {}
    // возвращает число, которое ввел пользователь.
    int getNumber()
    {
        int number = 0;
        cin >> number;
        return number;
    }
    // задаёт параметры функции. Реализован в классах - наследниках.
    virtual void setParams() = 0; 
    // возвращает результат функции. Реализован в классах - наследниках.
    virtual int result() = 0;
    // выводит в консоль результат функции. Реализован в классах - наследниках.
    virtual void print() = 0;
};

class Logarithm : public Function
{
public:
    // задаёт параметры функции.
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
        // возвращает результат функции.
    int result() override
    {
        return a * log(b * x) + c;
    }
    // выводит в консоль результат функции.
    void print() override
    {
        cout << a << " * lg ( " << b << " * " << x << " ) + " << c << " = " << result() << endl;
    }
};

class Cosine : public Function
{
public:
    // возвращает результат функции.
    int result() override
    {
        return a * sin(x * b) + c;
    }
    // выводит в консоль результат функции.
    void print() override
    {
        cout << a << " * Cos ( " << b << " * " << x << " ) + " << c << " = " << result() << endl;
    }
    // задаёт параметры функции.
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
    setlocale(LC_ALL, "ru"); // используем русские буквы
    cout << "Введите размерность вектор-функции: ";
    int N = 0,      // N - размерность вектор-функции
        number = 0; // номер функции
    cin >> N;
    Function **y = new Function *[N]; // объявление вектор-фукции
    Function *func;                   // экземпляр класса функции, которую выберет пользователь
    bool isWin = true;                // проверка условия выбора функции
    while (isWin)
    {
        cout << "Введите номер функции, результаты которой хотите посчитать:" << endl;
        cout << "1. a * cos ( b * x ) + c" << endl;
        cout << "2. a * lg ( b * x ) + c" << endl;
        cin >> number;
        switch (number)
        {
        case 1:
            func = new Cosine;
            isWin = false;
            break;
        case 2:
            func = new Logarithm;
            isWin = false;
            break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        y[i] = func;
        y[i]->setParams();
        y[i]->print();
    }
    delete func;
    for (int i = 0; i < N; i++)
    {
        delete[] y[i];
    }
    delete[] y;
    system("pause");
    return 0;
}