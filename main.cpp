#include <iostream> // подключение библиотеки для ввода-вывода в консоль
#include <iomanip>  // подключение библиотеки для форматирования текста в консоли
#include <ctime>    // подключение библиотеки для использования функции srand(time(NULL))

// используем для сокращения записи std::cout и std::cin
using namespace std;

// Объявление класса
class Matrix
{
    /*
 private - поля и методы, объявленные под ним могут быть 
 использованы только внутри класса.
 */
private:
    // количество колонок в матрице
    int columns;
    // количество строк в матрице
    int rows;
    /*
     двумерный динамически выделенный массив.
     Он хранит в себе значения матрицы.
    */
    int **array;

    /*
 public - поля и методы, объявленные под ним могут быть 
 использованы как внутри, так и вне класса.
 */
public:
    /*
 Объявление и описание конструктора класса по умолчанию
 (без переданных аргументов). Вызывается, когда создаем 
 экземпляр класса без указания конкретных параметров.
 */
    Matrix()
    {
        columns = 3;
        rows = 3;

        array = new int *[rows];
        for (int row = 0; row < rows; row++)
        {
            array[row] = new int[columns];
        }

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                array[row][column] = 0;
            }
        }
    }

    /*
 Объявление и описание конструктора копирования. 
 Этт метод создёт экземпляр класса с такими же полями,
 что и у копируемого объекта other без побитового копирования.
 */
    Matrix(Matrix &other)
    {
        columns = other.columns;
        rows = other.rows;

        array = new int *[rows];
        for (int row = 0; row < rows; row++)
        {
            array[row] = new int[columns];
        }

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                array[row][column] = other.getCeil(row, column);
            }
        }
    }

    /*
 Объявление и описание конструктора класса, в котором
 переданы 3 аргумента: newRows - количество строк в матрице,
 newColumns - количество колонок в матрице, а newArray - 
 динамически выделенный массив, значения которого будем
 передавать в новую матрицу.
 */
    Matrix(int **newArray, int newRows, int newColumns)
    {
        columns = newColumns;
        rows = newRows;

        array = new int *[rows];
        for (int row = 0; row < rows; row++)
        {
            array[row] = new int[columns];
        }

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                array[row][column] = newArray[row][column];
            }
        }
    }
    /*
 Объявление и описание деструктора класса.
 Этот метод нужен для отчистки динамически выделенной 
 внутри экземпляра класса памяти. В данном случае
 удаляет динамически выделенный двумерный массив
 array.
 */
    ~Matrix()
    {
        for (int row = 0; row < rows; row++)
        {
            delete[] array[row];
        }
        delete[] array;
    }
    /*
 объявление и описание метода перегрузки оператора присваивания. 
 Этот метод нужен для реализации присваивания полей экземпляра класса 
 справа от оператора присваивания другому подобному экземпляру слева
 без побитового копирования.
 */
    Matrix operator=(Matrix &other)
    {
        for (int row = 0; row < rows; row++)
        {
            delete[] array[row];
        }
        delete[] array;

        columns = other.columns;
        rows = other.rows;

        array = new int *[rows];
        for (int row = 0; row < rows; row++)
        {
            array[row] = new int[columns];
        }

        for (int row = 0; row < rows; row++)
        {
            for (int column = 0; column < columns; column++)
            {
                array[row][column] = other.getCeil(row, column);
            }
        }
        return *this;
    }

    // Объявление дружеского метода перегрузки оператора деления матрицы на целое число.
    friend Matrix &operator/(Matrix &otherMatrix, int number);
    /*
    Объявление и описание метода, который возвращает значение матрицы,
    где row - строка матрицы, а column - столбец матрицы.
    */
    int getCeil(int row, int column)
    {
        return array[row][column];
    }

    // Объявление и описание метода, который выводит матрицу в консоли.
    void print()
    {
        cout << setprecision(3);
        for (int row = 0; row < rows; row++)
        {
            cout << "( ";
            for (int column = 0; column < columns; column++)
            {
                cout << setw(4) << array[row][column] << ' ';
            }
            cout << ')' << '\n';
        }
    }
};

// Описание дружеского метода перегрузки оператора деления матрицы на целое число.



int main()
{
    // для использования кириллицы в консоли
    setlocale(LC_ALL, "Russian");
    // для того, чтобы рандомные цифры не повторялись после перезапуска программы
    srand(time(NULL)); 

    int rows, columns;
    cout << "Введите количество строк для матрицы A: ";
    cin >> rows;
    cout << "Введите количество столбцов для матрицы A: ";
    cin >> columns;

    int **newArray = new int*[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new int[columns];
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = rand() % 1000 + 1;
        }
        
    }

    Matrix A(newArray, rows, columns);
    int b = rand() % 100 + 1;
    Matrix C;
    C = A / b;

    A.print();
    cout << '\n' << "/ " << b << " = " << '\n' << '\n';
    C.print();

    system("pause");
    return 0;
}