#ifndef CPOSITION_HPP
#define CPOSITION_HPP

#include "IPosition.hpp"
#include "IComponent.hpp"
#include "IConfig.hpp"
#include "CUtility.hpp"

namespace Game
{
    class CPosition : public IPosition, IComponent
    {
    public:
        CPosition();
        ~CPosition();

        void vCreateComponent() override;
        void vDestroyComponent() override;

        void vSetUp() override;
        void vSetDown() override;
        void vSetRight() override;
        void vSetLeft() override;

        void vSetPosition(PointConfig::Point);
        PointConfig::Point pointGetPosition();

    private:
        PointConfig::Point m_position;
    };
}

#endif
