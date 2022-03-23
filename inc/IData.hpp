#ifndef IDATA_HPP
#define IDATA_HPP

#include "IConfig.hpp"
#include <utility>
#include <iostream>
#include <memory>
#include <unistd.h>
#include </usr/include/SFML/Graphics.hpp>

namespace Game
{
    template <typename T>
    struct Point
    {
    public:
        T x, y, z, radius, theta;

        Point() = default;
        Point(const T &x, const T &y, const T &z = 0, const T &radius = 0, const T &theta = 0)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->radius = radius;
            this->theta = theta;
        }

        ~Point() = default;
    };

    enum class eDIRECTION
    {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT,
        QUIT,
        UNKNOWN
    };
}

#endif