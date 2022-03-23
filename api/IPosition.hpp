#ifndef IPOSITION_HPP
#define IPOSITION_HPP

namespace Game
{
    class IPosition
    {
    public:
        virtual void vSetUp() = 0;
        virtual void vSetDown() = 0;
        virtual void vSetRight() = 0;
        virtual void vSetLeft() = 0;

    protected:
        IPosition() = default;
        virtual ~IPosition() = default;
    };
}

#endif