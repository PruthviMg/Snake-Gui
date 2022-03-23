#ifndef CSNAKE_HPP
#define CSNAKE_HPP

#include "IGame.hpp"
#include "IConfig.hpp"
#include "CFood.hpp"
#include "CPosition.hpp"
#include "CUtility.hpp"
#include "IComponent.hpp"
#include <sstream>

namespace Game
{
    class CSnake : public IComponent, IGame
    {
    public:
        CSnake();
        ~CSnake();

        void vStart() override;

    private:
        std::shared_ptr<CPosition> m_sharedPtrPosition;
        std::shared_ptr<sf::RenderWindow> m_sharedPtrWindow;
        std::shared_ptr<CFood> m_sharedPtrFood;

        int m_iScore;
        bool flag;
        eDIRECTION m_eCurrentDir;

        sf::Event m_event;
        sf::FloatRect m_SnakeBound, m_FoodBound;
        PointConfig::Point Dimension, m_CurrentLocation, m_FoodLocation;

        //shape
        sf::Texture m_snakeImage;
        sf::Sprite m_spriteSnake;
        SnakeConfig::SnakeShape m_SnakeObject;

        sf::Texture m_foodImage;
        sf::Sprite m_spriteFood;
        FoodConfig::FoodShape m_FoodObject;

        std::vector<SnakeConfig::SnakeShape> splash;

        //Functions
        void vCreateComponent() override;
        void vDestroyComponent() override;

        void vMovement() override;
        void vRender() override;
        void vLogic() override;
        void vEvent() override;
        void vControl() override;

        //Internal Functions
        bool bIsRunning();
        void vShape();
        void vBoundary();
        void vSplash();
    };
}

#endif