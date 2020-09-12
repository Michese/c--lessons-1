namespace application // используем пространство имен application
{
    // создаем класс Player
    class Player
    {
    private:                  // спецификатор доступа private
        Board *board;         // Экземпляр класса Board с пометками игрока
        Board *enemyBoard;    // Экземпляр класса Board с полем вражеского игрока со всеми его кораблями
        unsigned short score; // Количество уничтоженных игроком кораблей
        string name;          // имя игрока

    public: // спецификатор доступа public
            // конструктор класса с двуми аргументами:
            // const string name - имя игрока (в config.h)
            // const char array[ROWS][COLUMNS] - массив с полем вражеского игрока со всеми его кораблями (в config.h)
        Player(const string &name, const char (&array)[ROWS][COLUMNS])
        {
            this->name = name;
            this->board = new Board();
            this->score = 0;
            this->enemyBoard = new Board(array);
        }

        // метод с одним аргументом:
        // Player enemyPlayer - экземпляр класса вражеского игрока.
        // Игроки добавляют на свое поле дополнительные корабли,
        // вводя соответствующие координаты игрового поля.
        // Их количество можно регулировать с помощью константы
        // const unsigned short MAX_ADD_SHIP (в config.h)
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

        // геттер, возвращающий имя игрока.
        string getName()
        {
            return this->name;
        }

        // геттер, возвращающий указатель на экземпляр класса Board
        // с полем вражеского игрока со всеми его кораблями
        Board *getEnemyBoard()
        {
            return this->enemyBoard;
        }

        // геттер, возвращающий указатель на экземпляр класса Board с пометками игрока
        Board *getBoard()
        {
            return this->board;
        }

        // метод без аргументов.
        // Игрок вводит координаты выстрела и помечает
        // результат этого выстрела на игровом поле.
        // Возвращает true в случае попадания по вражескому кораблю,
        // false - в случае промаха.
        bool shot()
        {
            bool result = true;
            unsigned short x, y;
            char z;

            try
            {
                cout << this->name << endl;
                this->board->render();
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

                this->shot();
            }

            return result;
        }

        // метод без аргументов.
        // Проверяет, набрал ли игрок достаточное
        // количество очков для победы или нет.
        // const unsigned short SCORE_FOR_WIN (в config.h) -
        // количество очков, необходимое для победы.
        // Возвращает true в том случае, если очков
        // для победы оказалось достаточно,
        // false - в обратном случае.
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
    };

} // namespace application