#ifndef __UPSILON_COMPONENTS_MESHCOMPONENT_H__
#define __UPSILON_COMPONENTS_MESHCOMPONENT_H___

#include "Component.h"

#include "glm/vec3.hpp"

struct MeshComponent
    : public Component
{
    std::vector<glm::vec3> Vertices;
    std::vector<uint16_t> Indices;
};

#endif // __UPSILON_COMPONENTS_MESHCOMPONENT_H__