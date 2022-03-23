#include "CSnake.hpp"

int main()
{
    Game::PointConfig::Point Dim;
    Dim.x = 600;
    Dim.y = 600;

    Game::CSnake Snake;
    Snake.vStart();

    return 0;
}