#include "sound_manager.h"


void SoundManager_Context_init(SoundManager_Context* context){
    if (context == 0){
        return;
    }
    
    context->soundCount = 0;
    context->volume = 1.0;
}

void SoundManager_Context_unload(SoundManager_Context* context){
    if (context == 0){
        return;
    }


}
