#include "sounds/sound_manager.h"
#include "assets.h"


int SoundManager_Context_init(SoundManager_Context* sound_manager){
    if (!sound_manager){
        return 1; //fail
    }
    
    sound_manager->soundCount = 0;
    sound_manager->volume = 1.0;
    Raylib_Sound_initAudioDevice();

    HashMap_Map* sound_hashmap = (HashMap_Map*)malloc(sizeof(HashMap_Map));

    if (!sound_hashmap){
        return 2; //fail
    }

    HashMap_Map_init(
        sound_hashmap, 
        &Hashing_stringSum,
        &Compare_string,
        &HashMap_dataNoFree,
        &HashMap_dataNoFree, // should be some generic sound unload (assume create a sound struct wrapper)
        (size_t)25
    );

    sound_manager->sound_hashmap = sound_hashmap;
    
    Raylib_Sound meow = Raylib_Sound_load(
        ASSETS_AUDIO_CAT_MEOW_01
    );
    
    Raylib_Sound_play(meow);
        
    
    return 0; //success
}

int SoundManager_Context_delete(SoundManager_Context* sound_manager){
    
    if (!sound_manager){
        return 1; //fail
    }

    // clear all data structures

    // clear all data

    Raylib_Sound_closeAudioDevice();

    free(sound_manager);
    return 0; //success
}
