#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <stdlib.h>
#include "data_structures/hashmap.h"
#include "raylib_wrapper.h"
#include "hashing/string.h"
#include "compare/string.h"

typedef struct SoundManager_Context {
    int soundCount;
    float volume;
    HashMap_Map* sound_hashmap;
} SoundManager_Context;


int SoundManager_Context_init(SoundManager_Context* sound_manager);
int SoundManager_Context_delete(SoundManager_Context* sound_manager);


#endif