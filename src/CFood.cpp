#include "CFood.hpp"

namespace Game
{
    CFood::CFood(PointConfig::Point Dimension) : m_pointDimension(Dimension)
    {
    }

    CFood::~CFood()
    {
    }

    void CFood::vCreateComponent()
    {
    }

    void CFood::vDestroyComponent()
    {
    }

    PointConfig::Point CFood::pointGetFood()
    {
        PointConfig::Point location;

        location.x = CUtility::iGetRandom(FoodConfig::MIN_COORDINATE, m_pointDimension.x - FoodConfig::ROW_ADJUSTMENT);
        location.y = CUtility::iGetRandom(FoodConfig::MIN_COORDINATE, m_pointDimension.y - FoodConfig::ROW_ADJUSTMENT);

        return location;
    }
}