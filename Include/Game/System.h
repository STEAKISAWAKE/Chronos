#ifndef __UPSILON_GAME_SYSTEM_H__
#define __UPSILON_GAME_SYSTEM_H__

#include <set>

#include "Types.h"

class System
{
public:
    std::set<Entity> mEntities;

public:
    virtual void Begin() {}
    virtual void BeginEntity(Entity entity) {}
    virtual void PreUpdate() {}
    virtual void Update() {}
    virtual void Draw() {}
    virtual void PostDraw() {}
    virtual void EndEntity(Entity entity) {}
    virtual void End() {}
};

#endif // __UPSILON_GAME_SYSTEM_H__