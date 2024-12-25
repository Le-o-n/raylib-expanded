#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

typedef struct SoundManager_Context {
    int soundCount;
    float volume;
} SoundManager_Context;


void SoundManager_Context_init(
    SoundManager_Context* sound_manager
);
void SoundManager_Context_unload(
    SoundManager_Context* sound_manager
);


#endif