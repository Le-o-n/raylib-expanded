#ifndef HASHMAP_H
#define HASHMAP_H

#define HashMap_INITIAL_SIZE 1000

typedef struct{
    int (*hash_function)(void* x);
} HashMap_Map;

#endif