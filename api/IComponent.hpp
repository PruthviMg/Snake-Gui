#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

namespace Game
{
    class IComponent
    {
    public:
        virtual void vCreateComponent() = 0;
        virtual void vDestroyComponent() = 0;

    protected:
        IComponent() = default;
        virtual ~IComponent() = default;
    };
}

#endif