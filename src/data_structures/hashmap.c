
#include "data_structures/hashmap.h"

void HashMap_KeyValuePair_init(
    HashMap_KeyValuePair* pair,
    void* key,
    void* value
){
    if (!pair){
        return;
    }

    pair->key = key;
    pair->value = value;
}

void HashMap_KeyValuePair_unload(
    HashMap_KeyValuePair* pair
){
    if (!pair){
        return;
    }
    free(pair);
}

void HashMap_KeyValuePair_unloadAll(
    HashMap_KeyValuePair* pair
){
    if (!pair){
        return;
    }
    if (pair->key){
        free(pair->key);
    }
    if (pair->value){
        free(pair->value);
    }
    free(pair);
}
// Initializes the hashmap
void HashMap_Map_init(
    HashMap_Map* map, 
    size_t (*hash_function)(
        void* key
    ),
    size_t (*comparison_function)(
        void* key01, 
        void* key02
    ),
    size_t capacity
){
    map->hash_function = hash_function;
    map->comparison_function = comparison_function;
    map->capacity = capacity;
    map->_array = (LinkedList_List*)malloc(
        sizeof(LinkedList_List) * capacity
    );
    
    // Initialize each linked list in the array
    for (size_t i = 0; i < capacity; i++) {
        LinkedList_List_init(
            &map->_array[i]
        );
    }
}

// Inserts a key-value pair into the hashmap
void HashMap_Map_insert(
    HashMap_Map* map, 
    void* key, 
    void* value
){
    size_t hash_val = map->hash_function(key);
    hash_val = hash_val % map->capacity;

    LinkedList_List hit_linked_list = map->_array[hash_val];

    HashMap_KeyValuePair* key_value_pair;
    key_value_pair = (HashMap_KeyValuePair*)malloc(
        sizeof(HashMap_KeyValuePair)
    );

    HashMap_KeyValuePair_init(
        key_value_pair,
        key,
        value
    );

    LinkedList_List_pushHead(
        &hit_linked_list,
        (void*)key_value_pair
    );
    
}

// Retrieves a value by key from the hashmap
void* HashMap_Map_get(
    HashMap_Map* map, 
    void* key
){

    size_t key_hash = map->hash_function(key);
    key_hash = key_hash % map->capacity;

    LinkedList_List hit_linked_list = map->_array[key_hash];

    LinkedList_Node* cur_node = hit_linked_list.head;

    while (cur_node != 0){
        
        HashMap_KeyValuePair* key_value_pair;
        key_value_pair = (HashMap_KeyValuePair*)cur_node->data;

        size_t key_comparison = map->comparison_function(
            key, 
            key_value_pair->key
        );

        if (key_comparison == 0){ // match
            return key_value_pair->value;
        }


        cur_node = cur_node->next;
    }

    return 0;
}

// Deletes a key-value pair from the hashmap
void HashMap_Map_delete(
    HashMap_Map* map, 
    void* key
){

}

// Frees the hashmap and its resources
void HashMap_Map_unload(HashMap_Map* map) {
    for (size_t i = 0; i < map->capacity; i++) {
        LinkedList_Node* current_node = map->_array[i].head;
        LinkedList_Node* next;

        HashMap_KeyValuePair* key_value_pair;
        // Free each key-value pair in the linked list
        while (current_node != NULL) {
            next = current_node->next; // Store the next node
            key_value_pair = current_node->data;
            HashMap_KeyValuePair_unloadAll(key_value_pair);  // Free the key-value pair
            LinkedList_Node_unloadAll(current_node);        // Free the linked list node
            current_node = next;      // Move to the next node
        }
    }
    free(map->_array); // Free the array of linked lists
    map->_array = NULL; // Avoid dangling pointer
}