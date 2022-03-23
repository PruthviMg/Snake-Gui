#ifndef IGAME_HPP
#define IGAME_HPP

namespace Game
{
    class IGame
    {
    public:
        virtual void vStart() = 0;

    private:
        virtual void vMovement() = 0;
        virtual void vRender() = 0;
        virtual void vEvent() = 0;
        virtual void vLogic() = 0;
        virtual void vControl() = 0;

    protected:
        IGame() = default;
        virtual ~IGame() = default;
    };
}

#endif