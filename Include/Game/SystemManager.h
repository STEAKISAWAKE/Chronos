#ifndef __UPSILON_GAME_SYSTEMMANAGER_H__
#define __UPSILON_GAME_SYSTEMMANAGER_H__

#include <memory>
#include <unordered_map>

#include "Types.h"
#include "System.h"

class SystemManager
{

public:
    template<typename T>
    std::shared_ptr<T> RegisterSystem()
    {
        const char* typeName = typeid(T).name();

        assert(mSystems.find(typeName) == mSystems.end() && "Registering system more than once!");

        auto system = std::make_shared<T>();
        mSystems.insert({typeName, system});

        return system;
    }

    template<typename T>
    void SetSignature(Signature signature)
    {
        const char* typeName = typeid(T).name();

        assert(mSystems.find(typeName) != mSystems.end() && "System used before registration!");

        mSignatures.insert({typeName, signature});

        mSystems[typeName]->Begin();
    }

    void EntityDestroyed(Entity entity)
    {
        for(auto const& pair : mSystems)
        {
            auto const& system = pair.second;

            system->mEntities.erase(entity);
        }
    }

    void EntitySignatureChanged(Entity entity, Signature entitySignature)
    {
        for(auto const& pair : mSystems)
        {
            auto const& type = pair.first;
            auto const& system = pair.second;
            auto const& systemSignature = mSignatures[type];

            if((entitySignature & systemSignature) == systemSignature)
            {
                system->BeginEntity(entity);
                system->mEntities.insert(entity);
            }
            else
            {
                system->EndEntity(entity);
                system->mEntities.erase(entity);
            }
        }
    }

private:
    std::unordered_map<const char*, Signature> mSignatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};

};

#endif // __UPSILON_GAME_SYSTEMMANAGER_H__