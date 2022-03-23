#include "CPosition.hpp"

namespace Game
{
    CPosition::CPosition()
    {
    }

    CPosition::~CPosition()
    {
    }

    void CPosition::vCreateComponent()
    {
    }
    void CPosition::vDestroyComponent()
    {
    }

    void CPosition::vSetPosition(PointConfig::Point coordinate)
    {
        m_position = coordinate;
    }

    PointConfig::Point CPosition::pointGetPosition()
    {
        return m_position;
    }

    void CPosition::vSetUp()
    {
        m_position.y--;
    }

    void CPosition::vSetDown()
    {
        m_position.y++;
    }

    void CPosition::vSetRight()
    {
        m_position.x++;
    }

    void CPosition::vSetLeft()
    {
        m_position.x--;
    }
}