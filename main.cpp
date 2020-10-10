#include <iostream>  // подключаем библиотеку ввода-вывода в консоль
#include <vector>    // подключаем библиотеку с классом vector
#include <ctime>     // подключаем библиотеку, содержащую функции для работы со временем и датой
using namespace std; // используем пространство имен std для сокращения записи типа std::cout

const int CHEKERS = 4;            // Количество фишек у каждого игрока
const int COLUMNS = 8;            // Количество колонок игрового поля
const int ROWS = CHEKERS * 2 + 1; // Количество строк игрового поля
const char BLACK_MARK = 'B';      // символ, обозначающий черную фишку
const char WHITE_MARK = 'W';      // символ, обозначающий белую фишку
const char NULL_MARK = '0';       // символ, обозначающий, что на данной позиции нет фишек
const char EMPTY_MARK = ' ';      // символ, обозначающий пустой символ
const char LINE_MARK = '-';       // символ, разделяющий доску

const string NAME_FIRST_PLAYER = "First player";   // имя первого игрока
const string NAME_SECOND_PLAYER = "Second player"; // имя второго игрока

/*
    Обяъвление класса Board
*/
class Board
{
    /*
        Спецификатор доступа, обозначающий, 
        что все свойства и методы класса, объявленые под ним, 
        могут быть вызваны только внутри данного класса
    */
private:
    char board[ROWS][COLUMNS]; // игровое поле

    /*
        Спецификатор доступа, обозначающий, 
        что все свойства и методы класса, объявленые под ним, 
        могут быть вызваны внутри данного класса, а также вне его
    */
public:
    /*
    метод, выводящий игровое поле на экран
    */
    void print()
    {
        int count = COLUMNS + 1;
        for (int column = 0; column < COLUMNS; column++)
        {
            cout << COLUMNS - column << ' ';
        }
        cout << endl;
        for (int column = 0; column < COLUMNS; column++)
        {
            cout << "__";
        }
        cout << endl;

        for (int row = 0; row < ROWS; row++)
        {
            for (int column = 0; column < COLUMNS; column++)
            {
                cout << board[row][column] << ' ';
            }
            cout << endl;
        }

        for (int column = 0; column < COLUMNS; column++)
        {
            cout << "__";
        }
        cout << endl;
        for (int column = 0; column < COLUMNS; column++, count++)
        {
            while (count >= 10)
            {
                count -= 10;
            }
            cout << count << ' ';
        }
        cout << endl;
    }
    /*
        метод, принимающий целочисленный массив с позициями фигур первого игрока и второго игрока,
        а также символы, обозначающие их фигуры, и расставляющий эти фигуры согласно массивам.
    */
    void setBoard(vector<int> firstPlayer, const char &markFirstPlayer, vector<int> secondPlayer, const char &markSecondPlayer)
    {
        for (int row = 0; row < ROWS; row++)
        {
            for (int column = 0; column < COLUMNS; column++)
            {
                if (row < ROWS / 2 && firstPlayer[COLUMNS - column] > 0)
                {
                    board[row][column] = markFirstPlayer;
                    firstPlayer[COLUMNS - column]--;
                }
                else if (row < ROWS / 2 && secondPlayer[COLUMNS - column] > 0)
                {
                    board[row][column] = markSecondPlayer;
                    secondPlayer[COLUMNS - column]--;
                }
                else if (row > ROWS / 2 && firstPlayer[COLUMNS + column + 1] > 0 && firstPlayer[COLUMNS + column + 1] >= ROWS - row)
                {
                    board[row][column] = markFirstPlayer;
                    firstPlayer[COLUMNS + column + 1]--;
                }
                else if (row > ROWS / 2 && secondPlayer[COLUMNS + column + 1] > 0 && secondPlayer[COLUMNS + column + 1] >= ROWS - row)
                {
                    board[row][column] = markSecondPlayer;
                    secondPlayer[COLUMNS + column + 1]--;
                }
                else if (row == 0 || row == ROWS - 1)
                {
                    board[row][column] = NULL_MARK;
                }
                else if (ROWS / 2 == row)
                {
                    board[row][column] = LINE_MARK;
                }
                else
                {
                    board[row][column] = EMPTY_MARK;
                }
            }
        }
    }
};

/*
    объявление класса Player
*/
class Player
{
    /*
        Спецификатор доступа, обозначающий, 
        что все свойства и методы класса, объявленые под ним, 
        могут быть вызваны внутри данного класса, а также вне его
    */
private:
    char mark;           // символ, обозначающий фишку данного игрока
    string name;         // имя игрока
    vector<int> cube;    // массив чисел, выпавших на двух кубиках
    vector<int> chekers; // целочисленный массив с позициями фигур данного игрока
    /*
        Спецификатор доступа, обозначающий, 
        что все свойства и методы класса, объявленые под ним, 
        могут быть вызваны внутри данного класса, а также вне его
    */
public:
    /*
    Конструктор - метод, который реализуется при создании экземпляра класса
    */
    Player(const string newName, const char newMark)
    {
        name = newName;
        mark = newMark;
        chekers.resize(COLUMNS * 2 + 1);
        for (int count = 0; count < COLUMNS * 2 + 1; count++)
        {
            chekers[count] == 0;
        }

        if (newMark == BLACK_MARK)
        {
            chekers[1] = CHEKERS;
        }
        else
        {
            chekers[COLUMNS + 1] = CHEKERS;
        }
    }
    /*
        метод, возвращающий символ, обозначающий фишку данного игрока
    */
    char getMark()
    {
        return mark;
    }

    /*
        метод, возвращающий целое число, находящееся на позиции position из целочисленного массива с позициями фигур данного игрока
    */
    int getChekers(int position)
    {
        return chekers[position];
    }

    /*
        метод, возвращающий имя игрока
    */
    string getName()
    {
        return name;
    }
    /*
        метод, возвращающий целочисленный массив с позициями фигур данного игрока
    */
    vector<int> &getChekers()
    {
        return chekers;
    }

    /*
        метод, который реализует бросок кубиков
    */
    void roll()
    {
        int firstCube, secondCube;
        firstCube = rand() % 6 + 1;
        secondCube = rand() % 6 + 1;
        if (firstCube == secondCube)
        {
            for (int count = 0; count < 4; count++)
            {
                cube.push_back(firstCube);
            }
        }
        else
        {
            cube.push_back(firstCube);
            cube.push_back(secondCube);
        }
    }

    /*
        метод, инкрементирующий или декрементирующий количество фигур на заданной позиции position
    */
    void setChekers(int position, bool add)
    {
        if (add)
        {
            chekers[position]++;
        }
        else
        {
            chekers[position]--;
        }
    }

    /*
    метод, реализующий ход игрока. Просит игрока ввести позицию своей фишки, а затем
    позицию, на которую игрок хочет поставить выбранную фишку.
    */
    void move(Board &board, Player &otherPlayer)
    {
        char enter = 'W';
        int position1, position2;

        while (cube.size() > 0)
        {
            system("cls");
            board.print();
            cout << endl;
            cout << "Ход игрока " << name << endl;
            cout << "На кубиках выпало ";
            for (int count = 0; count < cube.size(); count++)
            {
                cout << cube[count] << ' ';
            }
            cout << endl;
            cout << "Введите 0, чтобы пропустить ход или любое число, чтобы продолжить." << endl;
            cin >> enter;
            if (enter == '0')
            {
                break;
            }

            cout << "Выберите номер ячейки, на которой у вас стоит фигура: ";
            cin >> position1;
            cout << "Выберите номер ячейки, на которую вы хотите пойти выбранной фигурой: ";
            cin >> position2;

            bool result = false;
            for (int count = 0; count < cube.size(); count++)
            {
                if (COLUMNS * 2 - position1 + position2 == cube[count] || position2 - position1 == cube[count])
                {
                    result = true;
                }
                if (result)
                {
                    break;
                }
            }

            if (!result || !moveCheker(position1, position2, otherPlayer))
            {
                cout << "Попробуйте еще раз\nНажмите Q" << endl;
                char enter = 'W';
                while (enter != 'Q' && enter != 'q')
                {
                    cin >> enter;
                }
                move(board, otherPlayer);
            }
            board.setBoard(getChekers(), getMark(), otherPlayer.getChekers(), otherPlayer.getMark());
            for (int count = 0; count < cube.size(); count++)
            {
                if (COLUMNS * 2 - position1 + position2 == cube[count] || position2 - position1 == cube[count])
                {
                    cube.erase(cube.begin() + count);
                    break;
                }
            }
        }
        cube.clear();
    }

    /*
        Метод, проверяющий валидацию заданных позиций.
        В случае удовлетворения всех условий фишка переместится
        на заданную позицию и вернет true.
    */
    bool moveCheker(int position1, int position2, Player &orderPlayer)
    {
        bool result;
        if (position1 < 0 || position1 > COLUMNS * 2 || position2 < 0 || position2 > COLUMNS * 2)
        {
            result = false;
        }
        else if (getChekers(position1) == 0 || orderPlayer.getChekers(position2) > 0)
        {
            result = false;
        }
        else
        {
            result = true;
            setChekers(position1, false);
            setChekers(position2, true);
        }
        return result;
    }
    /*
        Проверка, является ли игрок победителем.
        Игрок победил, если все его фигуры находятся в заданной области
    */
    bool isWin()
    {
        bool result = false;
        int countChekers = 0;
        if (mark == WHITE_MARK)
        {
            for (int count = COLUMNS / 2 + 1; count <= COLUMNS; count++)
            {
                countChekers += chekers[count];
            }
            if (countChekers == CHEKERS)
            {
                result = true;
            }
        }
        else
        {
            for (int count = COLUMNS * 2 + COLUMNS / 2 + 1; count <= COLUMNS * 2; count++)
            {
                countChekers += chekers[count];
            }
            if (countChekers == CHEKERS)
            {
                result = true;
            }
        }
        return result;
    }
};
/*
    Обяъвление класса Game
*/
class Game
{
    /*
        Спецификатор доступа, обозначающий, 
        что все свойства и методы класса, объявленые под ним, 
        могут быть вызваны внутри данного класса, а также вне его
    */
public:
    /*
        Метод, запускающий игру
    */
    void start()
    {
        Board board;
        Player firstPlayer(NAME_FIRST_PLAYER, WHITE_MARK);
        Player secondPlayer(NAME_SECOND_PLAYER, BLACK_MARK);
        board.setBoard(firstPlayer.getChekers(), firstPlayer.getMark(), secondPlayer.getChekers(), secondPlayer.getMark());
        bool who = true; // определяет очередность хода
        bool win = false; // определяет, есть ли победитель
        while (!win)
        {
            if (who)
            {
                firstPlayer.roll();
                firstPlayer.move(board, secondPlayer);
                win = firstPlayer.isWin();
            }
            else
            {
                secondPlayer.roll();
                secondPlayer.move(board, firstPlayer);
                win = secondPlayer.isWin();
            }
            if (!win)
            {
                who = !who;
            }
        }
        if (who)
        {
            cout << "Поздравляю игрока " << firstPlayer.getName() << " с победой!";
        }
        else
        {
            cout << "Поздравляю игрока " << secondPlayer.getName() << " с победой!";
        }

        system("pause");
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Game game;
    game.start();
    return 0;
}