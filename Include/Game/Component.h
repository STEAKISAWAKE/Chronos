#ifndef __UPSILON_GAME_COMPONENT_H__
#define __UPSILON_GAME_COMPONENT_H__

#include "json.hpp"

using namespace nlohmann;

struct Component
{
    virtual json GetSerialized() { return json(); }
    virtual void SetSerialized(json setInfo) {}
};

#endif // __UPSILON_GAME_COMPONENT_H__