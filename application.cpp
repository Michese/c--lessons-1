#include <iostream>
#include <vector>

using namespace std;

const int NUMBER_OF_SCORE_TO_WIN = 5;
const int SIZE = 7;
const char EMPTY_SYMBOL = '-';
const string NAME_FIRST_PLAYER = "игрок №1";
const string NAME_SECOND_PLAYER = "игрок №2";
const char FIRST_PLAYER_SYMBOl = 'X';
const char SECOND_PLAYER_SYMBOl = 'O';

class Board
{
private:
    vector<vector<char>> board;
    int size;

public:
    Board(const int &newSize)
    {
        size = newSize;
        board.resize(size, vector<char>(size));
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                board[row][column] = EMPTY_SYMBOL;
            }
        }
    }

    void print()
    {
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                cout << board[row][column] << ' ';
            }
            cout << endl;
        }
    }

    bool setCeil(int &row, int &column, char &symbol)
    {
        bool result = false;
        if (prepareNumber(row) && prepareNumber(column) && board[row][column] == EMPTY_SYMBOL)
        {
            board[row][column] = symbol;
            result = true;
        }
        return result;
    }

    bool prepareNumber(int &number)
    {
        bool result = false;
        if (number < size && number >= 0)
        {
            result = true;
        }
        return result;
    }

    bool isWin(int &row, int &column, char &symbol)
    {
        bool result = false;
        int score = 0;
        for (int count = row; count >= 0; count--)
        {
            if (board[count][column] != symbol)
            {
                break;
            }
            score++;
        }
        for (int count = row + 1; count < size; count++)
        {
            if (board[count][column] != symbol)
            {
                break;
            }
            score++;
        }
        if (score >= NUMBER_OF_SCORE_TO_WIN)
        {
            cout << "pop1";
            result = true;
        }
        else
        {
            score = 0;
            for (int count = column; count >= 0; count--)
            {
                if (board[row][count] != symbol)
                {
                    break;
                }
                score++;
            }
            for (int count = column + 1; count < size; count++)
            {
                if (board[row][count] != symbol)
                {
                    break;
                }
                score++;
            }
            if (score >= NUMBER_OF_SCORE_TO_WIN)
            {
                cout << "pop2";
                result = true;
            }
            else
            {
                score = 0;
                for (int count = 0; count <= row && count <= column; count++)
                {
                    if (board[row - count][column - count] != symbol)
                    {
                        break;
                    }
                    score++;
                }
                for (int count = 1; (count < size - row) && count < size - column; count++)
                {
                    if (board[row + count][column + count] != symbol)
                    {
                        break;
                    }
                    score++;
                }
                if (score >= NUMBER_OF_SCORE_TO_WIN)
                {
                    cout << "pop3";
                    result = true;
                }
                else
                {
                    score = 0;
                    for (int count = 0; (count <= row) && count < size - column; count++)
                    {
                        if (board[row - count][column + count] != symbol)
                        {
                            break;
                        }
                        score++;
                    }
                    for (int count = 1; (count < size - row) && count <= column; count++)
                    {
                        if (board[row + count][column - count] != symbol)
                        {
                            break;
                        }
                        score++;
                    }
                    if (score >= NUMBER_OF_SCORE_TO_WIN)
                    {
                        cout << "pop4";
                        result = true;
                    }
                }
            }
        }
        return result;
    }
};

class Player
{
private:
    Board *board;
    char playerSymbol;
    string playerName;

public:
    Player(string newPlayerName, const char &newPlayerSymbol, Board *newBoard)
    {
        playerName = newPlayerName;
        playerSymbol = newPlayerSymbol;
        board = newBoard;
    }
    bool move()
    {
        bool success = false;
        int row = 0, column = 0;
        while (!success)
        {
            system("cls");
            board->print();
            cout << "Ходит " << playerName << '!' << endl;

            do
            {
                cout << "Введите координаты по оси ОY(номер строки, начиная с 0):";
                cin >> row;
            } while (!board->prepareNumber(row));

            do
            {
                cout << "Введите координаты по оси ОХ(номер столбца, начиная с 0):";
                cin >> column;
            } while (!board->prepareNumber(column));

            success = board->setCeil(row, column, playerSymbol);
        }
        return board->isWin(row, column, playerSymbol);
    }

    void congratulation()
    {
        system("cls");
        board->print();
        cout << "Поздравляем, " << playerName << " победил!" << endl;
    }
};

class Game
{
private:
    Board *board;
    Player *fisrtPlayer;
    Player *secondPlayer;

public:
    Game()
    {
        board = new Board(SIZE);
        fisrtPlayer = new Player(NAME_FIRST_PLAYER, FIRST_PLAYER_SYMBOl, board);
        secondPlayer = new Player(NAME_SECOND_PLAYER, SECOND_PLAYER_SYMBOl, board);
    }
    ~Game()
    {
        delete board;
        delete fisrtPlayer;
        delete secondPlayer;
    }
    void start()
    {
        bool whoseTurn = false;
        bool isWin = false;
        while (!isWin)
        {
            whoseTurn = !whoseTurn;
            if (whoseTurn)
            {
                isWin = fisrtPlayer->move();
            }
            else
            {
                isWin = secondPlayer->move();
            }
        }
        if (whoseTurn)
        {
            fisrtPlayer->congratulation();
        }
        else
        {
            secondPlayer->congratulation();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Game game;
    game.start();
    return 0;
}