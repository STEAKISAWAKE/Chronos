#ifndef __CHRONOS_GAME_COMPONENTARRAY_H__
#define __CHRONOS_GAME_COMPONENTARRAY_H__

#include <assert.h>
#include <array>
#include <unordered_map>

#include "Types.h"

class IComponentArray
{
public:
    virtual ~IComponentArray() = default;
    virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray
{

public:
    void InsertData(Entity entity, T component)
    {
        assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end()  && "Component added to same entity more than once!");

        size_t newIndex = mSize;
        mEntityToIndexMap[entity] = newIndex;
        mIndexToEntityMap[newIndex] = entity;
        mComponentArray[newIndex] = component;
        ++mSize;
    }

    void RemoveData(Entity entity)
    {
        assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Removeing non-existent component!");

        size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
        size_t indexOfLastElement = mSize - 1;
        mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];
    
        Entity entityOfLastElement = mIndexToEntityMap[indexOfLastElement];
        mEntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
        mIndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

        mEntityToIndexMap.erase(entity);
        mIndexToEntityMap.erase(indexOfLastElement);

        --mSize;
    }

    T& GetData(Entity entity)
    {
        assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end() && "Retrieving non-existant component!");
    
        return mComponentArray[mEntityToIndexMap[entity]];
    }

    void EntityDestroyed(Entity entity) override
    {
        if(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end())
        {
            RemoveData(entity);
        }
    }

private:
    std::array<T, MAX_ENTITIES> mComponentArray;
    std::unordered_map<Entity, size_t> mEntityToIndexMap;
    std::unordered_map<size_t, Entity> mIndexToEntityMap;

    size_t mSize;
};

#endif // __CHRONOS_GAME_COMPONENTARRAY_H__