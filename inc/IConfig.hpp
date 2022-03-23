#ifndef ICONFIG_HPP
#define ICONFIG_HPP

#include "IData.hpp"

namespace Game
{
    namespace PointConfig
    {
        using Point = Point<double>;

    };

    namespace UtilityConfig
    {
    };

    namespace ColorConfig
    {
        constexpr auto BLACK = 0x0000FFFF;
        constexpr auto GREY = 0x373737FF;
        constexpr auto GREEN = 0XB9E0CFFF;
        constexpr auto RED = 0x00FF0000;
    };

    namespace BoundaryConfig
    {
        constexpr auto BOUNDARY_HEIGHT = 600;
        constexpr auto BOUNDARY_WIDTH = 600;
        constexpr auto UI_NAME = "Snake Game";
        constexpr auto BOUNDARY_COLOR = ColorConfig::GREY;
        constexpr auto NEEDED_BOUNDARY = true;
        constexpr auto TIME_AFTER_GAMEOVER = 5000000;
    };

    namespace FoodConfig
    {
        constexpr auto MIN_COORDINATE = 2;
        constexpr auto ROW_ADJUSTMENT = 3;
        constexpr auto COL_ADJUSTMENT = 4;

        constexpr auto FOOD_IMAGE = "/home/pruthvi/amaterasu/Snake-Gui/image/food.png";

        //FoodDesign
        constexpr auto FOOD_SHAPE_IMAGE = true;
        constexpr auto IMAGE_SCALE_X = 0.15;
        constexpr auto IMAGE_SCALE_Y = 0.15;
        using FoodShape = sf::RectangleShape;
        constexpr auto FOOD_SIZEX = 10.0;
        constexpr auto FOOD_SIZEY = 10.0;
        constexpr auto FOOD_COLOR = ColorConfig::GREEN;

    };

    namespace SnakeConfig
    {

        //Environment variables
        constexpr auto SNAKE_SPEED = 1000;
        constexpr auto InitialX = BoundaryConfig::BOUNDARY_HEIGHT / 2;
        constexpr auto InitialY = BoundaryConfig::BOUNDARY_WIDTH / 2;
        constexpr auto SNAKE_IMAGE = "/home/pruthvi/amaterasu/Snake-Gui/image/snake.png";
        constexpr auto TEXT_FONT = "/home/pruthvi/amaterasu/Snake-Gui/image/arial/arial.ttf";

        //Controls
        constexpr auto UP = sf::Keyboard::Up;
        constexpr auto DOWN = sf::Keyboard::Down;
        constexpr auto LEFT = sf::Keyboard::Left;
        constexpr auto RIGHT = sf::Keyboard::Right;
        constexpr auto QUIT = sf::Keyboard::Escape;
        constexpr auto SPLASH = sf::Keyboard::P;

        //Snake Design
        constexpr auto SNAKE_SHAPE_IMAGE = true;
        constexpr auto IMAGE_SCALE_X = 0.1;
        constexpr auto IMAGE_SCALE_Y = 0.1;
        using SnakeShape = sf::RectangleShape;
        constexpr auto SNAKEHEAD_SIZEX = 15.0;
        constexpr auto SNAKEHEAD_SIZEY = 15.0;
        constexpr auto SNAKE_COLOR = ColorConfig::BLACK;

        //typedef
        using SnakeBody = std::vector<sf::Vector2f>;

    };
}

#endif