namespace board
{
    using namespace std;

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

        void mark(int &x, int &y, const char &mark)
        {
            this->board[y][x] = mark;
        }
        void render()
        {
            char alph = 'A';
            cout << endl;
            for (int i = 0; i <= ROWS; i++)
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

            for (int i = 0; i <= ROWS; i++)
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
    };
} // namespace board