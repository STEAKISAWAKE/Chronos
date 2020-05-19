#ifndef __UPSILON_GAME_TYPES_H__
#define __UPSILON_GAME_TYPES_H__

#include <stdint.h>
#include <bitset>

using Entity = uint32_t;

const Entity MAX_ENTITIES = 20000;

/* Max amount of components is 65536 */
using ComponentType = uint16_t;

/* Max components per entity, another nice limit to be changed */
const ComponentType MAX_COMPONENTS = 64;

using Signature = std::bitset<MAX_COMPONENTS>;



#endif /* __UPSILON_GAME_TYPES_H__ */