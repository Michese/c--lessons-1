namespace application
{
    class Board
    {
    private:
        char board[ROWS][COLUMNS];

    public:
        Board()
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    this->board[i][j] = '0';
                }
            }
        }

        Board(const char (&array)[ROWS][COLUMNS])
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    this->board[i][j] = array[i][j];
                }
            }
        }

        void mark(unsigned short &x, unsigned short &y, const char &mark)
        {
            if (mark == SHIP && this->getCeil(x, y) == SHIP)
            {
                throw "there's already a ship here";
            }
            this->board[y][x] = mark;
        }

        void render()
        {
            char alph = 'A';

            cout << endl;
            for (int i = 0; i <= COLUMNS; i++)
            {
                if (i == 0)
                {
                    cout << " |";
                }
                else
                {
                    cout << i;
                }

                cout << ' ';
            }

            cout << endl;

            for (int i = 0; i <= COLUMNS; i++)
            {
                cout << "__";
            }

            cout << endl;

            for (int i = 0; i < ROWS; i++)
            {
                cout << alph << "| ";
                for (int j = 0; j < COLUMNS; j++)
                {
                    cout << this->board[i][j] << ' ';
                }
                ++alph;
                cout << endl;
            }

            cout << endl;
        }

        char getCeil(unsigned short &x, unsigned short &y)
        {
            return this->board[y][x];
        }

        unsigned short countScore()
        {
            unsigned short score = 0;
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    if (this->board[i][j] == SHIP)
                    {
                        score++;
                    }
                }
            }
            return score;
        }

        static void preparePoint(unsigned short &x, unsigned short &y, char &z)
        {
            z = toupper(z);
            y = (int)(z - 'A');
            --x;

            if (x >= COLUMNS || x < 0 || y >= ROWS || y < 0)
            {
                throw "incorrect values";
            }
        }
    };
} // namespace application