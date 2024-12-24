#include "sound_manager.h"

typedef struct SoundManager_Context {
    int soundCount;
    float volume;
} SoundManager_Context;

void SoundManager_Context_init(SoundManager_Context* context){
    context->soundCount = 0;
    context->volume = 1.0;
}
