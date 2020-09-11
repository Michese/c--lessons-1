#include <iostream>
namespace application
{
    using namespace std;
    
    const unsigned short COLUMNS = 9;
    const unsigned short ROWS = 9;
    const unsigned short SCORE_FOR_WIN = 3;
    const char SHIP = 'X';
    const char MISS = '*';

    const std::string NAME_PLAYER_1 = "First player";
    const char BOARD_PLAYER_1[ROWS][COLUMNS] = {
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', 'X', 'X', 'X', 'X', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', 'X', '0', '0', 'X', '0', 'X', 'X', 'X'},
        {'0', 'X', '0', '0', 'X', '0', '0', '0', '0'},
        {'0', 'X', '0', '0', 'X', '0', '0', '0', '0'},
        {'0', 'X', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', 'X', 'X', 'X', 'X', 'X'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'}};

    const std::string NAME_PLAYER_2 = "Second player";
    const char BOARD_PLAYER_2[ROWS][COLUMNS] = {
        {'X', '0', '0', '0', '0', 'X', 'X', 'X', '0'},
        {'X', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'X', '0', 'X', 'X', 'X', 'X', 'X', '0', '0'},
        {'X', '0', '0', '0', '0', '0', '0', '0', '0'},
        {'X', '0', '0', '0', '0', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', 'X', '0', '0', '0'},
        {'0', 'X', 'X', 'X', '0', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', 'X', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '0'}};
} // namespace application