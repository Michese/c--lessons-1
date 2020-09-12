namespace application // используем пространство имен application
{
    // Создаем класс Game
    class Game
    {
    public: // спецификатор доступа public
        // метод, запускающий игру
        void start()
        {
            cout << "Start game!" << endl;
            system("pause"); // Для продолжения нажмите Enter

            Player player1(NAME_PLAYER_1, BOARD_PLAYER_2); // Экземпляр класса игрока #1
            Player player2(NAME_PLAYER_2, BOARD_PLAYER_1); // Экземпляр класса игрока #2

            // переменная определяет очередность хода игроков
            bool currentPlayer = true;
            // требуется для выхода из цикла while в том случае,
            // если какой-либо из игроков победит
            bool win = false;

            player1.setEnemyBoard(player2);
            player2.setEnemyBoard(player1);

            // Для победы игрокам требуется уничтожить
            // const unsigned short SCORE_FOR_WIN (в config.h)
            // кораблей.
            while (!win)
            {
                system("cls"); // Чистим консоль

                // Проверяем очередность хода игроков:
                // true - ходит игрок #1,
                // false - ходит игрок #2.
                if (currentPlayer)
                {
                    if (player1.shot())
                    {
                        win = player1.isWin();
                    }
                    else
                    {
                        currentPlayer = !currentPlayer;
                    }
                }
                else
                {
                    if (player2.shot())
                    {
                        win = player2.isWin();
                    }
                    else
                    {
                        currentPlayer = !currentPlayer;
                    }
                }
            }

            system("cls"); // Чистим консоль

            // Проверяем какой из игроков победил:
            // true - победил игрок #1,
            // false - победил игрок #2.
            if (currentPlayer)
            {
                player1.getEnemyBoard()->render();
                player1.getBoard()->render();
                cout << player1.getName() << ", you is win!\nCongratulation!" << endl;
            }
            else
            {
                player2.getEnemyBoard()->render();
                player2.getBoard()->render();
                cout << player2.getName() << ", you is win!\nCongratulation!" << endl;
            }

            system("pause");
        }
    };
} // namespace application