#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <stddef.h> // For size_t
#include "linked_list.h" // Assuming you have a linked list implementation

// Define the initial size of the hashmap
#define HashMap_INITIAL_SIZE 256

typedef struct{
    void* key;
    void* value;
    int (*key_comparator_function)(void* key1, void* key2);
    int (*key_free_function)(void* key);
    int (*value_free_function)(void* value);
} HashMap_KeyValuePair;

int HashMap_noFree(void* data);
int HashMap_free(void* data);
int HashMap_equals(void* key01, void* key02);

int HashMap_KeyValuePair_init(
    HashMap_KeyValuePair* pair,
    void* key,
    void* value,
    int (*key_comparator_function)(void* key01, void* key02),
    int (*key_free_function)(void* key),
    int (*value_free_function)(void* value)
);
int HashMap_KeyValuePair_delete(HashMap_KeyValuePair* pair);
int HashMap_KeyValuePair_deleteWithData(HashMap_KeyValuePair* pair);
int HashMap_KeyValuePair_deleteGeneric(void* pair);
int HashMap_KeyValuePair_deleteWithDataGeneric(void* pair);
int HashMap_KeyValuePair_comparator(HashMap_KeyValuePair* pair, void* key);
int HashMap_KeyValuePair_comparatorGeneric(void* pair,void* key);


typedef struct {
    size_t (*hash_function)(void* key); // Pointer to a hash function
    int (*key_comparison_function)(void* key01, void* key02); // Pointer to a comparison function
    int (*key_free_function)(void*);
    int (*value_free_function)(void*);
    size_t capacity;                   // Capacity of the hashmap
    LinkedList_List* _array;           // Array of linked lists for collision resolution
} HashMap_Map;

int HashMap_Map_init(
    HashMap_Map* map, 
    size_t (*hash_function)(void* key), 
    int (*key_comparison_function)(void* key01, void* key02), 
    int (*key_free_function)(void*),
    int (*value_free_function)(void*),
    size_t initial_capacity
);
int HashMap_Map_insert(HashMap_Map* map, void* key, void* value);
void* HashMap_Map_get(HashMap_Map* map, void* key);
int HashMap_Map_deleteFrom(HashMap_Map* map, void* key);
int HashMap_Map_deleteFromWithData(HashMap_Map* map, void* key);
int HashMap_Map_delete(HashMap_Map* map);
int HashMap_Map_deleteWithData(HashMap_Map* map);
#endif // HASHMAP_H