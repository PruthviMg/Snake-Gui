#ifndef CFOOD_HPP
#define CFOOD_HPP

#include "IComponent.hpp"
#include "IConfig.hpp"
#include "CUtility.hpp"

namespace Game
{
    // using Point = PointConfig::Point;

    class CFood : public IComponent
    {
    public:
        CFood(PointConfig::Point);
        ~CFood();

        PointConfig::Point pointGetFood();

        void vCreateComponent() override;
        void vDestroyComponent() override;

    private:
        PointConfig::Point m_pointDimension;
    };
}

#endif