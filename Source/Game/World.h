#ifndef __CHRONOS_GAME_WORLD_H__
#define __CHRONOS_GAME_WORLD_H__

#include <memory>

#include "Types.h"
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"

class World
{

public:
    void Initalize()
    {
        mComponentManager = std::make_unique<ComponentManager>();
        mEntityManager = std::make_unique<EntityManager>();
        mSystemManager = std::make_unique<SystemManager>();
    }

    // ECS

    Entity CreateEntity()
    {
        return mEntityManager->CreateEntity();
    }

    void DestroyEntity(Entity entity)
    {
        mEntityManager->DestroyEntity(entity);

        mComponentManager->EntityDestroyed(entity);

        mSystemManager->EntityDestroyed(entity);
    }

    template<typename T>
    void RegisterComponent()
    {
        mComponentManager->RegisterComponent<T>();
    }

    template<typename T>
    void AddComponent(Entity entity, T component)
    {
        mComponentManager->AddComponent<T>(entity, component);

        auto signature = mEntityManager->GetSignature(entity);
        signature.set(mComponentManager->GetComponentType<T>(), true);
        mEntityManager->SetSignature(entity, signature);

        mSystemManager->EntitySignatureChanged(entity, signature);
    }

    template<typename T>
    T& GetComponent(Entity entity)
    {
        return mComponentManager->GetComponent<T>(entity);
    }

    template<typename T>
    ComponentType GetComponentType()
    {
        return mComponentManager->GetComponentType<T>();
    }

    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        return mSystemManager->RegisterSystem<T>();
    }

    template<typename T>
    void SetSystemSignature(Signature signature)
    {
        mSystemManager->SetSignature<T>(signature);
    }

private:
    std::unique_ptr<ComponentManager> mComponentManager;
    std::unique_ptr<EntityManager> mEntityManager;
    std::unique_ptr<SystemManager> mSystemManager;

};

#endif // __CHRONOS_GAME_WORLD_H__