#include <iostream>

#include "World.h"

struct PositionComponent
{
    int x;
    int y;
};

class PositionSystem 
    : public System
{
public:

};

int main()
{
    World world;

    world.Initalize();

    world.RegisterComponent<PositionComponent>();

    // Register system with the world
    auto positionSystem = world.RegisterSystem<PositionSystem>();
    {
        Signature signature;

        // Registers components with a system
        signature.set(world.GetComponentType<PositionComponent>());

        // Tell the system manager what the signature of the system is
        world.SetSystemSignature<PositionSystem>(signature);
    }

    Entity sprite = world.CreateEntity();

    world.AddComponent(sprite, PositionComponent{0, 0});

    world.GetComponent<PositionComponent>(sprite).x = 2;
    world.GetComponent<PositionComponent>(sprite).y = 3;

    std::cout << "X Pos: " << world.GetComponent<PositionComponent>(sprite).x << std::endl;
    std::cout << "Y Pos: " << world.GetComponent<PositionComponent>(sprite).y << std::endl;
}
