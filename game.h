#include "player.h"
class Game
{
public:
    void start()
    {
        Board board;
        Player firstPlayer(NAME_FIRST_PLAYER, WHITE_MARK);
        Player secondPlayer(NAME_SECOND_PLAYER, BLACK_MARK);
        board.setBoard(firstPlayer.getChekers(), firstPlayer.getMark(), secondPlayer.getChekers(), secondPlayer.getMark());
        bool who = true;
        bool win = false;
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
                who != who;
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