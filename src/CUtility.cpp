#include "CUtility.hpp"

namespace Game
{
    int CUtility::iGetRandom(int low, int high)
    {
        return std::max((rand() % high), low);
    }
    void CUtility::vPrintCoordinates(PointConfig::Point Pos)
    {
        std::cout << "(x, y) : "
                  << "(" << Pos.x << ", " << Pos.y << ")" << std::endl;
    }
}