#ifndef __CHRONOS_GAME_TRANSFORMCOMPONENT_H__
#define __CHRONOS_GAME_TRANSFORMCOMPONENT_H__

#include "Component.h"

#include <vector>

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>

struct TransformComponent
    : public Component
{
    glm::vec3 Position;
    glm::vec3 Scale;
    glm::quat Rotation;

    glm::mat4 Matrix;

    json GetSerialized() override
    {
        json serialized;
        serialized["Position"] = {Position.x, Position.y, Position.z};
        serialized["Scale"] =    {Scale.x, Scale.y, Scale.z};
        serialized["Rotation"] = {Rotation.x, Rotation.y, Rotation.z, Rotation.w};
        return serialized;
    }

    void SetSerialized(json serialized) override
    {
        Position = glm::vec3(serialized["Position"][0], serialized["Position"][1], serialized["Position"][2]);
        Scale = glm::vec3(serialized["Scale"][0], serialized["Scale"][1], serialized["Scale"][2]);
        Rotation = glm::quat(serialized["Rotation"][0], serialized["Rotation"][1], serialized["Rotation"][2], serialized["Rotation"][3]);
    }
};

#endif // __CHRONOS_GAME_TRANSFORMCOMPONENT_H__