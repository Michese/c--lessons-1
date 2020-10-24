#include <iostream> // Подключаем библиотеку для ввода-вывода в консоль
#include <iomanip> // Подключаем библиотеку для работы с консолью
#include <vector> // Подключаем библиотеку для работы с объектом класса vector
#include <algorithm> // Подключаем библиотеку для сортировки элементов объекта класса vector

using namespace std; // Используем пространство имен std для сокращения записи std::cout и тп

// описание собственного класса string
class MyString
{
    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны только внутри этого класса.
private:
    // массив символов для хранения символов строки
    char* myString;
    // длина массива символов
    int length;
    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны как внутри, так и вне этого класса.
public:
    // Конструктор по умолчанию
    MyString()
    {
        length = 0;
        myString = new char[length];
    }
    // Конструктор копирования
    MyString(MyString& other)
    {
        this->length = other.length;
        this->myString = new char[this->length];

        for (int count = 0; count < this->length; count++)
        {
            this->myString[count] = other.get(count);
        }
    }
    // Перегрузка оператора присваивания
    MyString operator=(MyString& other)
    {
        delete[] this->myString;
        this->length = other.length;
        this->myString = new char[this->length];

        for (int count = 0; count < this->length; count++)
        {
            this->myString[count] = other.get(count);
        }
        return *this;
    }
    // деструктор
    ~MyString()
    {
        delete[] myString;
    }
    // Метод, добавляющий элемент в конец строки.
    MyString &add(char newSymbol)
    {
        try
        {
            char* newString = new char[++length];
            for (int count = 0; count < length - 1; count++)
            {
                newString[count] = myString[count];
            }
            delete[] myString;
            myString = newString;
            myString[length - 1] = newSymbol;
        }
        catch (...)
        {
            cerr << "Ошибка добавления элемента в строку!" << endl;
        }
        return *this;
    }

    MyString& add(string newStr)
    {
        try
        {
            int oldSize = length;
            length += newStr.size();
            char* newString = new char[length];
            for (int count = 0; count < oldSize; count++)
            {
                newString[count] = myString[count];
            }
            delete[] myString;
            myString = newString;
            for (int count = oldSize; count < length; count++)
            {
                myString[count] = newStr[count - oldSize];
            }
        }
        catch (...)
        {
            cerr << "Ошибка добавления элемента в строку!" << endl;
        }
        return *this;
    }

    // метод, выводящий элементы строки в консоль.
    string render()
    {
        string result = "";
        for (int count = 0; count < length; count++)
        {
            result = result + myString[count];
        }
        return result;
    }
    // Перегрузка оператора суммирования.
    MyString& operator+(MyString& other)
    {
        MyString* newString = new MyString();
        for (int count = 0; count < this->length; count++)
        {
            newString->add(this->myString[count]);
        }
        for (int count = 0; count < other.length; count++)
        {
            newString->add(other.get(count));
        }
        return *newString;
    }
    // Геттер, возвращающий символ строки, находящийся по индексу index.
    char get(int index)
    {
        return myString[index];
    }

    int getLength() {
        return this->length;
    }
};

// описание собственного класса set
class MySet
{
    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны только внутри этого класса.   
private:
    // массив символов, хранящий элементы множества.
    vector<char> hello;

    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны как внутри, так и вне этого класса.
public:
    // Конструктор класса по умолчанию
    MySet() {}
    // Конструктор класса, принимающий параметр типа string.
    MySet(string newString)
    {
        for (int count = 0; count < newString.size(); count++)
        {
            hello.push_back(newString[count]);
        }
        sort(hello.begin(), hello.end());
    }
    // Конструктор копирования.
    MySet(MySet& other)
    {
        for (int count = 0; count < other.hello.size(); count++)
        {
            this->hello.push_back(other.hello[count]);
        }
    }
    // Перегрузка оператора присваивания.
    MySet& operator=(MySet& other)
    {
        for (int count = 0; count < other.hello.size(); count++)
        {
            this->add(other[count]);
        }
        return *this;
    }
    // Перегрузка оператора суммирования.
    MySet& operator+(MySet& other)
    {

        string newString = "";
        for (int count = 0; count < this->hello.size(); count++)
        {
            newString += this->hello[count];
        }
        for (int count = 0; count < other.hello.size(); count++)
        {
            newString += other.hello[count];
        }
        MySet* newSet = new MySet(newString);
        return *newSet;
    }
    // метод, принимающий параметр типа string, добавляет один или несколько элементов во множество.
    void add(string newString)
    {
        for (int count = 0; count < newString.size(); count++)
        {
            hello.push_back(newString[count]);
        }
        sort(hello.begin(), hello.end());
    }
    // перегрузка метода, принимающий параметр типа char, добавляет один элемент во множество.
    void add(char symbol)
    {
        hello.push_back(symbol);
        sort(hello.begin(), hello.end());
    }
    // метод, выводящий элементы множества в консоль.
    string render()
    {
        string result = "[";

        for (int count = 0; count < hello.size(); count++)
        {
            if (hello.size() - 1 == count) {
                result = result + hello[count];
                break;
            }
            result = result + hello[count] + ", ";
        }

        result = result + "]";
        return result;
    }
    // перегрзка оператора индексирования.
    char& operator[](int index) {
        return this->hello[index];
    }
    int getLength() {
        return this->hello.size() * 3 - 2;
    }
};

// шаблон класса
template <class T>
// реализация класса матрицы
class Matrix
{
    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны только внутри этого класса.
private:
    // двумерный массив, хранящий в себе элементы матрицы.
    vector<vector<T>> matr;

    // спецификатор доступа private. Члены класса, объявленные под ним,
    // могут быть вызваны как внутри, так и вне этого класса.
public:
    // Конструктор класса по умолчанию
    Matrix() {}
    // Конструктор класса, принимающий параметр типа int, обозначающий размер квадратной матрицы.
    Matrix(int size)
    {
        matr.resize(size, vector<T>(size));
    }
    // Конструктор копирования
    Matrix(Matrix& other) {
        this->matr.resize(other.getSize(), vector<T>(other.getSize()));
        for (int row = 0; row < other.getSize(); row++)
        {
            for (int column = 0; column < other.getSize(); column++)
            {
                this->set(row, column, other[row][column]);
            }
        }
    }

    // Перегрузка оператора индексирования.
    vector<T>& operator[](int index)
    {
        return matr[index];
    }

    // Геттер, возвращающий размер квадратной матрицы.
    int getSize() {
        return matr.size();
    }

    // Перегрузка оператора суммирования.
    Matrix& operator+(Matrix& other) {
        int size = this->getSize();
        Matrix* newMatrix = new Matrix(size);
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                newMatrix->set(row, column, matr[row][column] + other[row][column]);
            }
        }
        return *newMatrix;
    }

    // Перегрузка оператора присваивания.
    Matrix& operator=(T& other) {
        for (int row = 0; row < this->getSize(); row++)
        {
            for (int column = 0; column < this->getSize(); column++)
            {
                this->set(row, column, other);
            }
        }
        return *this;
    }

    // сеттер, присваивающий элементу матрицы новое значение.
    // row - номер строки, изменяемого элемента матрицы,
    // column - номер столбца, изменяемого элемента матрицы,
    // row - новое значение элемента матрицы.
    void set(int row, int column, T& other) {
        this->matr[row][column] = other;
    }

    // метод, вводящий элементы матрицы в консоль.
    void render() {
        vector<int>sizeFill(this->getSize());
        for (int column = 0; column < this->getSize(); column++)
        {
            for (int row = 0; row < this->getSize(); row++)
            {
                if (this->matr[row][column].getLength() > sizeFill[column]) {
                    sizeFill[column] = this->matr[row][column].getLength();
                }
            }
        }

        for (int row = 0; row < this->getSize(); row++)
        {

            cout << "( ";
            for (int column = 0; column < this->getSize(); column++)
            {
                cout << setw(sizeFill[column] + 2) << setfill(' ');
                cout << this->matr[row][column].render();
                cout << ' ';
            }
            cout << ')' << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Типы матриц:" << endl;
    cout << "1. Строка;" << endl;
    cout << "2. Множество." << endl;

    int number = 0;
    while (true) {
        cout << "Введите номер типа матрицы: ";
        try {
            cin >> number;


            if (number == 1 || number == 2) {
                break;
            }
            else {
                throw "Не корректныйномер типа матрицы!";
            }
        }
        catch (string e) {
            cerr << e << endl;
        }
        catch (exception exp) {
            cerr << exp.what() << endl;
        }
        catch (...) {}
    }

    int size = 0;
    while (true) {
        cout << "Введите размер квадратных матриц: ";
        try {
            cin >> size;
            break;
        }
        catch (...) {
            cerr << "Не корректный размер!";
        }

    }

    if (number == 1) {
        Matrix<MyString> A(size);
        string newString;
        cout << "Введите значения матрицы A:" << endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                cout << "A[" << row << "][" << column << "] = ";
                cin >> newString;
                A[row][column].add(newString);
            }
        }

        Matrix<MyString> B(size);
        cout << "Введите значения матрицы B:" << endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                cout << "B[" << row << "][" << column << "] = ";
                cin >> newString;
                B[row][column].add(newString);
            }
        }

        Matrix<MyString> C;
        C = A + B;

        A.render();
        cout << '+' << endl;
        B.render();
        cout << '=' << endl;
        C.render();
    }
    else if(number == 2) {
        Matrix<MySet> A(size);
        string newString;
        cout << "Введите значения матрицы A:" << endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                cout << "A[" << row << "][" << column << "] = ";
                cin >> newString;
                A[row][column].add(newString);
            }
        }

        Matrix<MySet> B(size);
        cout << "Введите значения матрицы B:" << endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                cout << "B[" << row << "][" << column << "] = ";
                cin >> newString;
                B[row][column].add(newString);
            }
        }

        Matrix<MySet> C;
        C = A + B;

        A.render();
        cout << '+' << endl;
        B.render();
        cout << '=' << endl;
        C.render();
    }

    return 0;
}