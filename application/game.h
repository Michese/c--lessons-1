namespace application
{
    class Game
    {
    public:
        void start()
        {
            Player player1(NAME_PLAYER_1, BOARD_PLAYER_2);
            Player player2(NAME_PLAYER_2, BOARD_PLAYER_1);

            bool currentPlayer = true;
            bool win = false;

            player1.setEnemyBoard(player2);
            player2.setEnemyBoard(player1);
            
            while (!win)
            {
                system("cls");

                if (currentPlayer)
                {
                    cout << player1.getName() << endl;
                    player1.getBoard()->render();
                    currentPlayer = (player1.shot()) ? currentPlayer : !currentPlayer;
                    win = player1.isWin();
                }
                else
                {
                    cout << player2.getName() << endl;
                    player2.getBoard()->render();
                    currentPlayer = (player2.shot()) ? currentPlayer : !currentPlayer;
                    win = player2.isWin();
                }
            }

            system("cls");

            if (currentPlayer)
            {
                player1.getBoard()->render();
                cout << player1.getName() << ", you is win!\nCongratulation!" << endl;
            }
            else
            {
                player2.getBoard()->render();
                cout << player1.getName() << ", you is win!\nCongratulation!" << endl;
            }

            system("pause");
        }
    };
} // namespace application