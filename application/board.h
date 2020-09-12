namespace application // используем пространство имен application
{
    // создаем класс Board
    class Board
    {
    private:                       // спецификатор доступа private
    // игровое поле
    // const unsigned short ROWS - количество строк поля(в config.h),
    // const unsigned short COLUMNS - количество столбцов поля(в config.h).
        char board[ROWS][COLUMNS]; 

    public: // спецификатор доступа public
        // конструктор класса без аргументов,
        // используется для создания пустого игрового поля.
        Board()
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    this->board[i][j] = EMPTY;
                }
            }
        }

        // конструктор класса с одним аргументом -
        // двумерным массивом со стандартным вражеским
        // игровым полем со всеми кораблями (в config.h)
        // const char array[ROWS][COLUMNS].
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

        // метод с тремя аргументами:
        // unsigned short x - координата x на игровом поле(число),
        // unsigned short y - координата y на игровом поле(символ),
        // const char mark - константа, обозначающая отметку на игровом поле (в config.h).
        // Используется для изменения символа на игровом поле по координатам (x, y).
        void mark(unsigned short &x, unsigned short &y, const char &mark)
        {
            if (this->getCeil(x, y) == mark)
            {
                string exp = "there's already a " + mark;
                exp += " here";
                throw exp;
            }
            this->board[y][x] = mark;
        }

        // Метод без аргументов.
        // Выводит игровое поле в консоль
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

        // метод с двумя аргументами:
        // unsigned short x - координата x на игровом поле(число),
        // unsigned short y - координата y на игровом поле(символ).
        // Возвращает символ, находящийся на игровом поле по координатам (x, y).
        char getCeil(unsigned short &x, unsigned short &y)
        {
            return this->board[y][x];
        }

        // Метод без аргументов.
        // Возвращает количество кораблей на игровом поле.
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

        // статический метод с тремя переменными:
        // unsigned short x - координата x на игровом поле(число),
        // unsigned short y - пустая переменная, которая станет координатой y на игровом поле(символ),
        // char z - временная переменная, необходимая для ввода пользователем сивола координаты y.
        // Валидация переменных.
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