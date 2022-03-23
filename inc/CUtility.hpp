#ifndef CUTILITY_HPP
#define CUTILITY_HPP

#include "IConfig.hpp"

namespace Game
{
    class CUtility
    {
    public:
        static int iGetRandom(int low, int high);

        static void vPrintCoordinates(PointConfig::Point Pos);
    };
}

#endif