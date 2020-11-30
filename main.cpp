#include <iostream> // подключаем библиотеку для работы с консолью
#include <iomanip> // подключаем библиотеку для красивого расположения цифр внутри матрицы в консоли

// используем пространство имен std, чтобы каждый раз не вводить std::cout и т.п.
using namespace std;

// Объявляем класс Matrix
class Matrix
{
    /*
спецификатор доступа protected, все свойства и методы,
объявленные под ним могут быть использованы только внутри класса.
Свойства и методы наследуются.
*/
    protected:
    // количество колонок в матрице
    int currentColumns;
    // количество строк в матрице
    int currentRows;
    // массив, хранящий в себе значения матрицы
    double **matrix;

    // количество колонок в матрице по умолчанию
    static const int DEFAULT_COLUMNS = 5;
    // количество строк в матрице по умолчанию
    static const int DEFAULT_ROWS = 5;
    // максимальное количество строк и столбцов для матриц
    static const int SIZE_LIMIT = 30;
    // объявление значения матрицы по умолчанию
    static const double DEFAULT_VALUES;

    /*
 спецификатор доступа public, все свойства и методы,
 объявленные под ним могут быть использованы как внутри, так и вне класса.
 Свойства и методы наследуются.
 */

public:
    /*
Конструктор класса с двумя аргументами. row -
количество строк в матрице, columns - количество
колонок в матрице. DEFAULT_VALUES - значения
матрицы по умолчанию.
*/
    Matrix(int rows, int columns)
    {
        // Проверяет, что количество строк и колонок меньше максимального значения
        try {
            if (rows > Matrix::SIZE_LIMIT || columns > Matrix::SIZE_LIMIT) {
                throw "Количество колонок или строк больше возможного!";
            }
        }
        catch (exception exp) {
            cout << exp.what() << endl;
            cerr << exp.what() << endl;
            return;
        }

        this->currentColumns = columns;
        this->currentRows = rows;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                this->set(Matrix::DEFAULT_VALUES, row, column);
            }
        }
    }

    /*
 Конструктор класса по умолчанию. Количество строк
 и столбцов в матрице будет равно значениям по умолчанию
 DEFAULT_ROWS и DEFAULT_COLUMNS соответственно.
 DEFAULT_VALUES - значения матрицы по умолчанию.
 */
    Matrix()
    {
        this->currentColumns = Matrix::DEFAULT_COLUMNS;
        this->currentRows = Matrix::DEFAULT_ROWS;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                this->set(Matrix::DEFAULT_VALUES, row, column);
            }
        }
    }

    // Конструктор создания копии.Создает экземпляр класса с такими же свойствами, что и у otherMatrix.
    Matrix(Matrix &otherMatrix)
    {
        this->currentColumns = otherMatrix.getCurrentColumns();
        this->currentRows = otherMatrix.getCurrentRows();

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(otherMatrix.get(row, column), row, column);
            }
        }
    }

    /*
 Конструктор класса с тремя аргументами. row -
 количество строк в матрице, columns - количество
 колонок в матрице. Значения матрицы берутся
 из массива matrix.
 */
    Matrix(double **matrix, int rows, int columns)
    {
        try {
            if (rows > Matrix::SIZE_LIMIT || columns > Matrix::SIZE_LIMIT) {
                throw "Количество колонок или строк больше возможного!";
            }
        }
        catch (exception exp) {
            cerr << exp.what() << endl;
            return;
        }

        this->currentColumns = columns;
        this->currentRows = rows;

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(matrix[row][column], row, column);
            }
        }
    }
    
    /*
 Деструктор класса, нужен для очистки памяти.
 Удаляет динамически выделенный массив.
 */
    ~Matrix()
    {
        for (int count = 0; count < this->currentRows; count++)
            free(this->matrix[count]);
        free(this->matrix);
    }
    
    // Перегрузка оператора индексации
    double *operator[](const int row)
    {
        return this->matrix[row];
    }

    // Перегрузка оператора присваивания.Матрице слева присваиваются свойства матрицы справа от оператора присваивания.
    Matrix operator=(Matrix &otherMatrix)
    {
        for (int count = 0; count < this->currentRows; count++)
            delete[](this->matrix[count]);
        delete[](this->matrix);

        this->currentColumns = otherMatrix.getCurrentColumns();
        this->currentRows = otherMatrix.getCurrentRows();

        this->matrix = new double *[this->currentRows];
        for (int row = 0; row < this->currentRows; row++)
            this->matrix[row] = new double[this->currentColumns];

        for (int row = 0; row < this->currentRows; row++)
        {
            for (int column = 0; column < this->currentColumns; column++)
            {
                Matrix::set(otherMatrix.get(row, column), row, column);
            }
        }
        return *this;
    }
    // объявление перегрузки оператора деления матрицы на вещественное число. 
    friend Matrix &operator/(Matrix &otherMatrix, double number);
    // объявление перегрузки оператора сложения матрицы с вещественным числом.
    friend Matrix &operator+(Matrix &otherMatrix, double number);
    // объявление перегрузки оператора сложения двух матриц.
    friend Matrix &operator+(Matrix &firstMatrix, Matrix &secondMatrix);
    // объявление перегрузки оператора разности двух матриц.
    friend Matrix &operator-(Matrix &firstMatrix, Matrix &secondMatrix);
    // объявление перегрузки оператора умножения двух матриц.
    friend Matrix &operator*(Matrix &firstMatrix, Matrix &secondMatrix);
    // объявление перегрузки оператора умножения матрицы на число.
    friend Matrix &operator*(Matrix &otherMatrix, double number);

    /*
Геттер двумерного массива matrix. row - номер строки,
column - номер колонки значения, которого мы хотим получить.
*/
    double get(int row, int column)
    {
        double result;
        // Проверяет нет ли выхода за пределы массива
        try
        {
            if (row >= this->currentRows || row < 0 || column >= this->currentColumns || column < 0)
            {
                throw "Error. Array element not found";
            }
            result = this->matrix[row][column];
        }
        catch (...)
        {
            result = 0.0;
        }

        return result;
    }

    // геттер количества строк данной матрицы
    int getCurrentRows()
    {
        return this->currentRows;
    }

    // геттер количества колонок данной матрицы
    int getCurrentColumns()
    {
        return this->currentColumns;
    }

    /*
сеттер двумерного массива matrix. row - номер строки, column - номер колонки значения, которого мы хотим заменить на значение value.
*/
    bool set(double value, int row, int column)
    {
        bool result;
        // Проверяет нет ли выхода за пределы массива
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

    // метод, который выводит матрицу в консоль.
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

// присваивание значения матрицы по умолчанию
const double Matrix::DEFAULT_VALUES = 0.0;

// Описание перегрузки оператора деления матрицы на вещественное число
Matrix &operator/(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) / number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}

// Описание перегрузки оператора сложения матрицы и числа
Matrix &operator+(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) + number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}

// Описание перегрузки оператора сложения двух матрицы
Matrix &operator+(Matrix &firstMatrix, Matrix &secondMatrix)
{
    int rows = (firstMatrix.getCurrentRows() > secondMatrix.getCurrentRows()) ? firstMatrix.getCurrentRows() : secondMatrix.getCurrentRows();
    int columns = (firstMatrix.getCurrentColumns() > secondMatrix.getCurrentColumns()) ? firstMatrix.getCurrentColumns() : secondMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = firstMatrix.get(row, column) + secondMatrix.get(row, column);
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

// Описание перегрузки оператора разности двух матриц
Matrix &operator-(Matrix &firstMatrix, Matrix &secondMatrix)
{
    int rows = (firstMatrix.getCurrentRows() > secondMatrix.getCurrentRows()) ? firstMatrix.getCurrentRows() : secondMatrix.getCurrentRows();
    int columns = (firstMatrix.getCurrentColumns() > secondMatrix.getCurrentColumns()) ? firstMatrix.getCurrentColumns() : secondMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (firstMatrix.get(row, column) == 0 && secondMatrix.get(row, column) == 0)
            {
                newArray[row][column] = 0.0;
            }
            else
            {
                newArray[row][column] = firstMatrix.get(row, column) - secondMatrix.get(row, column);
            }
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

// Описание перегрузки оператора умножения двух матриц
Matrix &operator*(Matrix &firstMatrix, Matrix &secondMatrix)
{
    if (firstMatrix.getCurrentColumns() != secondMatrix.getCurrentRows() || firstMatrix.getCurrentRows() != secondMatrix.getCurrentColumns())
    {
        Matrix *newMatrix = new Matrix();
        return *newMatrix;
    }
    int rows = firstMatrix.getCurrentRows();
    int columns = firstMatrix.getCurrentRows();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = 0.0;
            for (int index = 0; index < firstMatrix.getCurrentColumns(); index++)
            {
                newArray[row][column] += firstMatrix.get(row, index) * secondMatrix.get(index, column);
            }
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;

    return *newMatrix;
}

// Описание перегрузки оператора умножения матрицы на число
Matrix &operator*(Matrix &otherMatrix, double number)
{
    int rows = otherMatrix.getCurrentRows();
    int columns = otherMatrix.getCurrentColumns();

    double **newArray = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        newArray[row] = new double[columns];
    }

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            newArray[row][column] = otherMatrix.get(row, column) * number;
        }
    }

    Matrix *newMatrix = new Matrix(newArray, rows, columns);
    for (int row = 0; row < rows; row++)
        delete[] newArray[row];
    delete[] newArray;
    return *newMatrix;
}

int main()
{
    // Обяъвляем вещественное число b и задаем ему значение
    double b = 2.0;
    cout << "b = " << b << ';' << endl;
    
    // Обяъвляем экземпляр матрицы A и задаем ей значения
    Matrix A(3, 2);
    A.set(4.0, 0, 0);
    A.set(2.0, 0, 1);
    A.set(3.0, 1, 0);
    A.set(1.0, 1, 1);
    A.set(1.0, 2, 0);
    A.set(1.0, 2, 1);
    cout << "A =" << endl;
    A.print();

    cout << endl;

    // Обяъвляем экземпляр матрицы B и задаем ей значения
    Matrix B(3, 3);
    B.set(5.0, 0, 0);
    B.set(2.0, 0, 1);
    B.set(2.0, 0, 2);
    B.set(3.0, 1, 0);
    B.set(1.0, 1, 1);
    B.set(1.0, 1, 2);
    B.set(1.0, 2, 0);
    B.set(1.0, 2, 1);
    B.set(0.0, 2, 2);
    cout << "B =" << endl;
    B.print();

    cout << endl;

    // Обяъвляем экземпляр матрицы C
    Matrix C;
    // сложение двух матриц
    cout << "C = A + B =" << endl;
    C = A + B;
    C.print();
    cout << endl;

    // разность двух матриц
    cout << "C = A - B =" << endl;
    C = A - B;
    C.print();
    cout << endl;

    // произведение двух матриц
    cout << "C = A * B =" << endl;
    C = A * B;
    C.print();
    cout << endl;

    // деление матрицы на число
    cout << "C = A / b =" << endl;
    C = A / b;
    C.print();
    cout << endl;

    // сложение матрицы с число
    cout << "C = A + b =" << endl;
    C = A + b;
    C.print();
    cout << endl;

    // произведение матрицы на число
    cout << "C = A * b =" << endl;
    C = A * b;
    C.print();
    cout << endl;
}