#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib. h>
#include <stddef.h> // For size_t
#include "linked_list.h" // Assuming you have a linked list implementation

// Define the initial size of the hashmap
#define HashMap_INITIAL_SIZE 256

typedef struct{
    void* key;
    void* value;
} HashMap_KeyValuePair;

void HashMap_KeyValuePair_init(
    HashMap_KeyValuePair* pair,
    void* key,
    void* value
);

void HashMap_KeyValuePair_unload(
    HashMap_KeyValuePair* pair
);

void HashMap_KeyValuePair_unloadAll(
    HashMap_KeyValuePair* pair
);




// HashMap namespace
typedef struct {
    size_t (*hash_function)(void* x); // Pointer to a hash function
    size_t capacity;                   // Capacity of the hashmap
    LinkedList_List* _array;           // Array of linked lists for collision resolution
} HashMap_Map;

// Function prototypes

// Initializes the hashmap
void HashMap_Map_init(
    HashMap_Map* map, 
    size_t (*hash_function)(void* x), 
    size_t initial_capacity
);

// Inserts a key-value pair into the hashmap
void HashMap_Map_insert(
    HashMap_Map* map, 
    void* key, 
    void* value
);

// Retrieves a value by key from the hashmap
void* HashMap_Map_get(
    HashMap_Map* map, 
    void* key
);

// Deletes a key-value pair from the hashmap
void HashMap_Map_delete(
    HashMap_Map* map, 
    void* key
);

// Frees the hashmap and its resources
void HashMap_Map_unload(
    HashMap_Map* map
);

#endif // HASHMAP_H