#include "sound_manager.h"


void SoundManager_Context_init(SoundManager_Context* sound_manager){
    if (sound_manager == 0){
        return;
    }
    
    sound_manager->soundCount = 0;
    sound_manager->volume = 1.0;
}

void SoundManager_Context_unload(SoundManager_Context* sound_manager){
    if (sound_manager == 0){
        return;
    }


}
