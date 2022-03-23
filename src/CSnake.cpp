#include "CSnake.hpp"

namespace Game
{
    CSnake::CSnake() : m_sharedPtrPosition(nullptr),
                       m_sharedPtrWindow(nullptr),
                       m_sharedPtrFood(nullptr),
                       m_iScore(0),
                       Dimension(BoundaryConfig::BOUNDARY_HEIGHT, BoundaryConfig::BOUNDARY_WIDTH), flag(false)
    {
    }

    CSnake::~CSnake()
    {
    }

    void CSnake::vCreateComponent()
    {
        //position
        PointConfig::Point Init(SnakeConfig::InitialX, SnakeConfig::InitialY);

        m_sharedPtrPosition = std::make_shared<CPosition>();
        if (nullptr != m_sharedPtrPosition)
        {
            m_sharedPtrPosition->vCreateComponent();
            m_sharedPtrPosition->vSetPosition(Init);
        }

        //food
        m_sharedPtrFood = std::make_shared<CFood>(Dimension);
        if (nullptr != m_sharedPtrFood)
        {
            m_sharedPtrFood->vCreateComponent();
            m_FoodLocation = m_sharedPtrFood->pointGetFood();
        }

        //sfml
        m_sharedPtrWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(BoundaryConfig::BOUNDARY_HEIGHT, BoundaryConfig::BOUNDARY_WIDTH), BoundaryConfig::UI_NAME);

        vShape();
    }

    void CSnake::vShape()
    {
        if (SnakeConfig::SNAKE_SHAPE_IMAGE)
        {
            try
            {
                m_snakeImage.loadFromFile(SnakeConfig::SNAKE_IMAGE);
                m_foodImage.loadFromFile(FoodConfig::FOOD_IMAGE);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            m_spriteSnake.setTexture(m_snakeImage);
            m_spriteSnake.setScale(SnakeConfig::IMAGE_SCALE_X, SnakeConfig::IMAGE_SCALE_Y);
            m_spriteSnake.setPosition(m_CurrentLocation.x, m_CurrentLocation.y);

            m_spriteFood.setTexture(m_foodImage);
            m_spriteFood.setScale(FoodConfig::IMAGE_SCALE_X, FoodConfig::IMAGE_SCALE_Y);
            m_spriteFood.setPosition(m_FoodLocation.x, m_FoodLocation.y);
        }

        else
        {
            m_SnakeObject.setPosition(m_CurrentLocation.x, m_CurrentLocation.y);
            m_SnakeObject.setSize(sf::Vector2f(SnakeConfig::SNAKEHEAD_SIZEX, SnakeConfig::SNAKEHEAD_SIZEY));
            m_SnakeObject.setFillColor(sf::Color(SnakeConfig::SNAKE_COLOR));
            m_SnakeObject.setOutlineColor(sf::Color(ColorConfig::RED));
            m_SnakeObject.setOutlineThickness(1.f);

            m_FoodObject.setPosition(m_FoodLocation.x, m_FoodLocation.y);
            m_FoodObject.setSize(sf::Vector2f(FoodConfig::FOOD_SIZEX, FoodConfig::FOOD_SIZEY));
            m_FoodObject.setFillColor(sf::Color(FoodConfig::FOOD_COLOR));
            m_FoodObject.setOutlineColor(sf::Color(ColorConfig::RED));
            m_FoodObject.setOutlineThickness(1.f);
        }
    }

    void CSnake::vDestroyComponent()
    {
        m_sharedPtrWindow->close();
    }

    void CSnake::vRender()
    {
        m_sharedPtrWindow->clear(sf::Color(BoundaryConfig::BOUNDARY_COLOR));

        if (SnakeConfig::SNAKE_SHAPE_IMAGE)
        {
            m_sharedPtrWindow->draw(m_spriteSnake);
            m_sharedPtrWindow->draw(m_spriteFood);
        }
        else
        {
            m_sharedPtrWindow->draw(m_SnakeObject);
            m_sharedPtrWindow->draw(m_FoodObject);
        }
        for (auto it : splash)
            m_sharedPtrWindow->draw(it);

        // usleep(10000);

        splash.clear();
        sf::Font font;
        try
        {
            font.loadFromFile(SnakeConfig::TEXT_FONT);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::ostringstream oss;
        oss << m_iScore * 10;
        sf::Text text;
        text.setFont(font);
        text.setString(oss.str());
        text.setCharacterSize(24);
        text.setPosition(500, 20);
        text.setFillColor(sf::Color::Cyan);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        if (flag)
        {
            text.setString("GAME OVER --> " + oss.str());
            text.setCharacterSize(24);
            text.setPosition(200, 300);
            m_sharedPtrWindow->draw(text);
            m_sharedPtrWindow->display();

            usleep(BoundaryConfig::TIME_AFTER_GAMEOVER);
            vDestroyComponent();
        }
        else
            m_sharedPtrWindow->draw(text);

        m_sharedPtrWindow->display();
    }

    void CSnake::vSplash()
    {
        std::cout << "vSplash" << std::endl;
        auto yy = m_FoodLocation.y;
        auto xx = m_FoodLocation.x;
        auto offset = 10.f;
        for (int i = 0; i < 500; i++)
        {
            int val = 50;
            SnakeConfig::SnakeShape shape;
            xx += offset;
            yy += offset;

            auto randomx = CUtility::iGetRandom(xx - val, xx + val);
            auto randomy = CUtility::iGetRandom(yy - val, yy + val);

            shape.setPosition(randomx, randomy);
            shape.setSize(sf::Vector2f(2.f, 2.f));
            shape.setFillColor(sf::Color::White);
            splash.push_back(shape);
        }
    }

    void CSnake::vLogic()
    {
        m_SnakeObject.setPosition(m_CurrentLocation.x, m_CurrentLocation.y);
        m_spriteSnake.setPosition(m_CurrentLocation.x, m_CurrentLocation.y);

        m_FoodObject.setPosition(m_FoodLocation.x, m_FoodLocation.y);
        m_spriteFood.setPosition(m_FoodLocation.x, m_FoodLocation.y);

        m_SnakeBound = m_SnakeObject.getGlobalBounds();
        m_FoodBound = m_FoodObject.getGlobalBounds();

        auto snake = m_spriteSnake.getGlobalBounds();
        auto food = m_spriteFood.getGlobalBounds();

        if (snake.intersects(food) || m_SnakeBound.intersects(m_FoodBound))
        {
            std::cout << "Food eaten" << std::endl;
            vSplash();
            m_iScore++;
            m_FoodLocation = m_sharedPtrFood->pointGetFood();
        }
    }

    void CSnake::vBoundary()
    {

        if (BoundaryConfig::NEEDED_BOUNDARY)
        {
            if (m_CurrentLocation.x < -20 || m_CurrentLocation.y < -20 || m_CurrentLocation.x >= Dimension.x || m_CurrentLocation.y >= Dimension.y)
            {
                // vDestroyComponent();
                flag = true;
            }
        }

        else
        {

            PointConfig::Point tempPoint;

            if (m_CurrentLocation.x <= 0)
            {
                tempPoint.x = Dimension.x - 1;
                tempPoint.y = m_CurrentLocation.y;
                m_sharedPtrPosition->vSetPosition(tempPoint);
            }

            if (m_CurrentLocation.x >= Dimension.x)
            {
                tempPoint.x = 2.0;
                tempPoint.y = m_CurrentLocation.y;
                m_sharedPtrPosition->vSetPosition(tempPoint);
            }

            if (m_CurrentLocation.y <= 0)
            {
                tempPoint.x = m_CurrentLocation.x;
                tempPoint.y = Dimension.y - 1;
                m_sharedPtrPosition->vSetPosition(tempPoint);
            }

            if (m_CurrentLocation.y >= Dimension.y)
            {
                tempPoint.x = m_CurrentLocation.x;
                tempPoint.y = 2.0;
                m_sharedPtrPosition->vSetPosition(tempPoint);
            }
        }
    }

    void CSnake::vMovement()
    {
        switch (m_eCurrentDir)
        {
        case eDIRECTION::LEFT:
            m_sharedPtrPosition->vSetLeft();
            break;

        case eDIRECTION::RIGHT:
            m_sharedPtrPosition->vSetRight();
            break;

        case eDIRECTION::DOWN:
            m_sharedPtrPosition->vSetDown();
            break;

        case eDIRECTION::UP:
            m_sharedPtrPosition->vSetUp();
            break;

        case eDIRECTION::QUIT:
        {
            vDestroyComponent();
            break;
        }

        default:
            break;
        }

        vBoundary();
    }

    void CSnake::vControl()
    {
        if (m_event.key.code == SnakeConfig::QUIT)
            vDestroyComponent();

        if (m_event.key.code == SnakeConfig::RIGHT)
            m_eCurrentDir = eDIRECTION::RIGHT;

        if (m_event.key.code == SnakeConfig::LEFT)
            m_eCurrentDir = eDIRECTION::LEFT;

        if (m_event.key.code == SnakeConfig::UP)
            m_eCurrentDir = eDIRECTION::UP;

        if (m_event.key.code == SnakeConfig::DOWN)
            m_eCurrentDir = eDIRECTION::DOWN;

        if (m_event.key.code == SnakeConfig::SPLASH)
        {
            vSplash();
        }
    }

    void CSnake::vEvent()
    {
        while (m_sharedPtrWindow->pollEvent(m_event))
        {
            switch (m_event.type)
            {
            case sf::Event::Closed:
                vDestroyComponent();
                break;

            case sf::Event::KeyPressed:
                vControl();
                break;
            }
        }
    }

    bool CSnake::bIsRunning()
    {
        return m_sharedPtrWindow->isOpen();
    }

    void CSnake::vStart()
    {
        vCreateComponent();
        srand(time(NULL));

        while (bIsRunning())
        {
            m_CurrentLocation = m_sharedPtrPosition->pointGetPosition();
            vEvent();
            vMovement();
            vLogic();
            // vSplash();
            vRender();

            usleep(SnakeConfig::SNAKE_SPEED);
        }
    }
}