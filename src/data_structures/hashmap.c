
#include "data_structures/hashmap.h"


int HashMap_noFree(void* data){
    return 0;
}

int HashMap_free(void* data){
    free(data);
    return 0;
}

int HashMap_equals(
    void* key01, 
    void* key02
){
    return (int)(key01!=key02);
}


int HashMap_KeyValuePair_init(
    HashMap_KeyValuePair* pair,
    void* key,
    void* value,
    int (*key_comparator_function)(void* key01, void* key02),
    int (*key_free_function)(void* key),
    int (*value_free_function)(void* value)
){
    if (!pair){
        return 1; //fail
    }

    if (!key_free_function){
        key_free_function = &HashMap_noFree;
    }

    if (!value_free_function){
        value_free_function = &HashMap_noFree;
    }

    if (!key_comparator_function){
        key_comparator_function = &HashMap_equals;
    }


    pair->key = key;
    pair->value = value;
    pair->key_free_function = key_free_function;
    pair->value_free_function = value_free_function;
    pair->key_comparator_function = key_comparator_function;
    return 0; //success
}

int HashMap_KeyValuePair_delete(
    HashMap_KeyValuePair* pair
){
    if (!pair){
        return 1; //fail
    }
    free(pair);
    return 0;
}

int HashMap_KeyValuePair_deleteWithData(
    HashMap_KeyValuePair* pair
){
    if (!pair){
        return 1; //fail
    }

    if (!pair->key_free_function){
        return 2; //fail
    }

    if (!pair->value_free_function){
        return 3; //fail
    }

    if (pair->key_free_function(pair->key)){
        return 4; //fail
    }
    
    if (pair->value_free_function(pair->value)){
        return 5; //fail
    }
    
    if (HashMap_KeyValuePair_delete(pair)){
        return 6; //fail
    }

    return 0; //sucess
}

int HashMap_KeyValuePair_deleteGeneric(
    void* pair
){
    return HashMap_KeyValuePair_delete(
        (HashMap_KeyValuePair*)pair
    );
}

int HashMap_KeyValuePair_deleteWithDataGeneric(
    void* pair
){
    return HashMap_KeyValuePair_deleteWithData(
        (HashMap_KeyValuePair*)pair
    );
}

int HashMap_KeyValuePair_comparator(
    HashMap_KeyValuePair* pair,
    void* key
){
    return pair->key_comparator_function(pair->key, key);
}

int HashMap_KeyValuePair_comparatorGeneric(
    void* pair,
    void* key
){
    HashMap_KeyValuePair* key_value_pair = (HashMap_KeyValuePair*)pair;
    return HashMap_KeyValuePair_comparator(key_value_pair, key);
}

// Initializes the hashmap
int HashMap_Map_init(
    HashMap_Map* map, 
    size_t (*hash_function)(
        void* key
    ),
    int (*key_comparison_function)(
        void* key01, 
        void* key02
    ),
    int (*key_free_function)(void*),
    int (*value_free_function)(void*),
    size_t capacity
){
    map->hash_function = hash_function;
    map->key_comparison_function = key_comparison_function;
    map->capacity = capacity;
    map->_array = (LinkedList_List*)malloc(
        sizeof(LinkedList_List) * capacity
    );

    if (!key_free_function){
        key_free_function = &HashMap_noFree;
    }
    if (!value_free_function){
        value_free_function = &HashMap_noFree;
    }

    map->key_free_function = key_free_function;
    map->value_free_function = value_free_function;

    // Initialize each linked list in the array
    for (size_t i = 0; i < capacity; i++) {
        LinkedList_List_init(
            &map->_array[i],
            &HashMap_KeyValuePair_deleteGeneric
        );
    }
    return 0;
}

// Inserts a key-value pair into the hashmap
int HashMap_Map_insert(
    HashMap_Map* map, 
    void* key, 
    void* value
){  
    if (!map){
        return 1; //fail
    }

    if (!map->hash_function){
        return 2; //fail
    }

    size_t hash_val = map->hash_function(key);
    size_t linked_list_index = hash_val % map->capacity;

    LinkedList_List *hit_linked_list = &map->_array[linked_list_index];

    HashMap_KeyValuePair* key_value_pair;
    key_value_pair = (HashMap_KeyValuePair*)malloc(
        sizeof(HashMap_KeyValuePair)
    );

    if (!key_value_pair){
        return 3; //fail
    }

    if (HashMap_KeyValuePair_init(
        key_value_pair,
        key,
        value,
        map->key_comparison_function,
        map->key_free_function,
        map->value_free_function
    )){
        return 4; //fail
    }

    if (LinkedList_List_pushHead(
        hit_linked_list,
        (void*)key_value_pair
    )){
        return 5; //fail
    }
    
    return 0;
}

// Retrieves a value by key from the hashmap
void* HashMap_Map_get(
    HashMap_Map* map, 
    void* key
){

    if (!map){
        return NULL; //fail
    }

    if (!map->hash_function){
        return NULL; //fail
    }

    size_t key_hash = map->hash_function(key);
    key_hash = key_hash % map->capacity;

    LinkedList_List hit_linked_list = map->_array[key_hash];

    LinkedList_Node* cur_node = hit_linked_list.head;

    while (cur_node != 0){
        
        HashMap_KeyValuePair* key_value_pair;
        key_value_pair = (HashMap_KeyValuePair*)cur_node->data;

        int key_comparison = map->key_comparison_function(
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
int HashMap_Map_deleteFrom(
    HashMap_Map* map, 
    void* key
){
    if (!map){
        return 1; //fail
    }

    if (!map->hash_function){
        return 2; //fail
    }

    size_t hash_val = map->hash_function(key);
    size_t linked_list_index = hash_val % map->capacity;

    LinkedList_List *hit_linked_list = &map->_array[linked_list_index];

    if (LinkedList_List_deleteFrom(
        hit_linked_list, 
        key, 
        &HashMap_KeyValuePair_comparatorGeneric
    )){
        return 2; //fail
    }

    return 0; //success

}

int HashMap_Map_deleteFromWithData(
    HashMap_Map* map, 
    void* key
){
    if (!map){
        return 1; //fail
    }

    if (!map->hash_function){
        return 2; //fail
    }

    size_t hash_val = map->hash_function(key);
    size_t linked_list_index = hash_val % map->capacity;

    LinkedList_List *hit_linked_list = &map->_array[linked_list_index];

    if (LinkedList_List_deleteFromWithData(
        hit_linked_list, 
        key, 
        &HashMap_KeyValuePair_comparatorGeneric
    )){
        return 2; //fail
    }

    return 0; //success

}


// Frees the hashmap and its resources
int HashMap_Map_delete(HashMap_Map* map) {
    
    if (!map){
        return 1; //fail
    }
    
    for (size_t i = 0; i < map->capacity; i++) {
        LinkedList_List* current_list = &map->_array[i];
        
        if (LinkedList_List_delete(current_list)){
            return 2; //fail
        }

    }

    free(map->_array); // Free the array of linked lists
    map->_array = NULL; // Avoid dangling pointer

    free(map);

    return 0;
}

int HashMap_Map_deleteWithData(HashMap_Map* map) {
    
    if (!map){
        return 1; //fail
    }
    
    for (size_t i = 0; i < map->capacity; i++) {
        LinkedList_List* current_list = &map->_array[i];
        
        if (LinkedList_List_deleteWithData(current_list)){
            return 2; //fail
        }

    }

    free(map->_array); // Free the array of linked lists
    map->_array = NULL; // Avoid dangling pointer

    free(map);

    return 0;
}