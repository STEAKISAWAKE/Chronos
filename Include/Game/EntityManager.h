#ifndef __UPSILON_GAME_ENTITYMANAGER_H__
#define __UPSILON_GAME_ENTITYMANAGER_H__

#include <assert.h>
#include <queue>
#include <array>

#include "Types.h"

class EntityManager
{

public:
    EntityManager()
    {
        // Initalize the queue with all possible entity IDs
        for(Entity entity = 0; entity < MAX_ENTITIES; ++entity)
        {
            mAvailableEntities.push(entity);
        }
    }

    Entity CreateEntity()
    {
        assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities alive!");

        // Take an IDfrom the front of the queue
        Entity id = mAvailableEntities.front();
        mAvailableEntities.pop();
        ++mLivingEntityCount;

        return id;
    }

    void DestroyEntity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range!");

        mSignatures[entity].reset();

        mAvailableEntities.push(entity);
        --mLivingEntityCount;
    }

    void SetSignature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range!");

        mSignatures[entity] = signature;
    }

    Signature GetSignature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entities out of range!");

        return mSignatures[entity];
    }


private:
    // Queue of unused entity IDs
    std::queue<Entity> mAvailableEntities{};

    // Array of signatures where the index corresponds to the entity ID
    std::array<Signature, MAX_ENTITIES> mSignatures{};

    uint32_t mLivingEntityCount{};
};

#endif // __UPSILON_GAME_ENTITYMANAGER_H__