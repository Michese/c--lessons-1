#include "board.h"

namespace player
{
    using namespace std;
    using namespace board;

    class Player
    {
    private:
        Board *board;
        char enemyBoard[ROWS][COLUMNS];
        unsigned short score;
        string name;

    public:
        Player(const string name, const char (&array)[ROWS][COLUMNS])
        {
            this->name = name;
            this->board = new Board();
            this->score = 0;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    this->enemyBoard[i][j] = array[i][j];
                }
            }
        }
        Board *getBoard()
        {
            return this->board;
        }
        bool shot()
        {
            bool result = true;
            int x, y;
            char z;
            try
            {
                cout << "X-coordinate(number): ";
                cin >> x;
                cout << "Y-coordinate(symbol): ";
                cin >> z;
                Player::preparePoint(x, y, z);
            }
            catch (...)
            {
                cout << "incorrect values!" << endl;
                system("PAUSE");
                system("CLS");
                cout << this->name << endl;
                this->board->render();
                this->shot();
            }

            cout << x << ' ' << y << endl;
            if (this->enemyBoard[y][x] == SHIP)
            {
                this->board->mark(x, y, SHIP);
                this->score++;
                result = true;
            }
            else
            {
                this->board->mark(x, y, MISS);
                result = false;
            }
            return result;
        }

        static void preparePoint(int &x, int &y, char &z)
        {
            z = toupper(z);
            y = (int)(z - 'A');
            --x;
            if (x >= COLUMNS || x < 0 || y >= ROWS || y < 0)
            {
                throw "incorrect values";
            }
        }
        bool isWin()
        {
            bool result;
            if (this->score == SCORE_FOR_WIN)
            {
                result = true;
            }
            else
            {
                result = false;
            }
            return result;
        }

        string getName()
        {
            return this->name;
        }
    };

} // namespace player