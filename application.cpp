// подключаем все необходимые заголовочные файлы
#include "application/config.h"
#include "application/board.h"
#include "application/player.h"
#include "application/game.h"

using namespace application; // Включаем пространство имен application в область видимости
// Точка входа в программу
int main()
{
    Game game; // Экземпляр класса Game
    game.start();
    return 0;
}