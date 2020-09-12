namespace application
{
    class Player
    {
    private:
        Board *board;
        Board *enemyBoard;
        unsigned short score;
        string name;

    public:
        Player(const string &name, const char (&array)[ROWS][COLUMNS])
        {
            this->name = name;
            this->board = new Board();
            this->score = 0;
            this->enemyBoard = new Board(array);
        }

        void setEnemyBoard(Player &enemyPlayer)
        {
            unsigned short countShip = MAX_ADD_SHIP,
                           x,
                           y;
            bool result = true;
            char z;

            while (countShip > 0)
            {
                system("cls");

                try
                {
                    enemyPlayer.enemyBoard->render();
                    cout << this->name << ", add ship to board: " << countShip << " ships." << endl;
                    cout << "Y-coordinate(symbol): ";
                    cin >> z;
                    cout << "X-coordinate(number): ";
                    cin >> x;
                    Board::preparePoint(x, y, z);
                    enemyPlayer.enemyBoard->mark(x, y, SHIP);
                    --countShip;
                }
                catch (...)
                {
                    cout << "incorrect values!" << endl;
                    system("pause");
                }
            }
            cout << this->name << ", You have added all the ships to your Board!" << endl;
            system("pause");
        }

        Board *getBoard()
        {
            return this->board;
        }

        bool shot()
        {
            bool result = true;
            unsigned short x, y;
            char z;

            try
            {
                cout << "Shot to enemy ship!" << endl;
                cout << "Y-coordinate(symbol): ";
                cin >> z;
                cout << "X-coordinate(number): ";
                cin >> x;
                Board::preparePoint(x, y, z);

                if (this->enemyBoard->getCeil(x, y) == SHIP)
                {
                    this->board->mark(x, y, SHIP);
                    this->score = this->board->countScore();
                    result = true;
                }
                else
                {
                    this->board->mark(x, y, MISS);
                    result = false;
                }
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

            return result;
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

} // namespace application