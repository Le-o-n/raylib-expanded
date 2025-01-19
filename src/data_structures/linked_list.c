#include "data_structures/linked_list.h"

int LinkedList_genericFree(void* data){
    free(data);
    return 0;
}

int LinkedList_noFree(void* data){
    return 0;
}

// Initialize a node with given data
int LinkedList_Node_init(
    LinkedList_Node* node, 
    int (*data_free_function)(void*),
    void *data
) {
    if (!node){ 
        return 1; //fail
    }

    if (!data_free_function){
        data_free_function = &LinkedList_noFree;
    }

    node->data = data;
    node->data_free_function = data_free_function;
    node->next = NULL;
    node->prev = NULL;
    return 0; //success
}

// Unload a node (free memory if applicable)
int LinkedList_Node_delete(
    LinkedList_Node *node
) {
    if (!node){ 
        return 1; //fail
    }

    LinkedList_Node* prev_node = node->prev;
    LinkedList_Node* next_node = node->next;

    if (LinkedList_Node_delete(node)){
        return 1; //fail
    }

    if (prev_node){
        prev_node->next = next_node;
    }

    if (next_node){
        next_node->prev = prev_node;
    }

    free(node);
    return 0; //success
} 

int LinkedList_Node_deleteWithData(
    LinkedList_Node *node
) {

    if (!node->data){
        return 1; //fail
    }

    if (!node->data_free_function){
        return 2; //fail
    } 

    if (node->data_free_function(node->data)){
        return 3; //fail
    }

    if (LinkedList_Node_delete(node)){
        return 4; //fail
    }
    return 0; //success
}

int LinkedList_Node_remove(
    LinkedList_Node *node
){
    LinkedList_Node* prev_node = node->prev;
    LinkedList_Node* next_node = node->next;

    if (LinkedList_Node_delete(node)){
        return 1; //fail
    }

    prev_node->next = next_node;
    next_node->prev = prev_node;

    return 0; //success
}

int LinkedList_Node_removeUnload(
    LinkedList_Node *node
){
    LinkedList_Node* prev_node = node->prev;
    LinkedList_Node* next_node = node->next;

    if (LinkedList_Node_delete(node)){
        return 1; //fail
    }

    prev_node->next = next_node;
    next_node->prev = prev_node;

    return 0; //success
}

int LinkedList_List_init(
    LinkedList_List* list, 
    int (*data_free_function)(void*)
) {
    if (!list) {
        return 1; //fail
    }

    if (!data_free_function){
        data_free_function = &LinkedList_noFree;
    }

    list->head = NULL;
    list->tail = NULL;
    list->data_free_function = data_free_function;
    list->size = 0;

    return 0; //success
}

int LinkedList_List_delete(
    LinkedList_List *list
) {
    if (!list) {
        return 1; //fail
    }
    LinkedList_Node *current = list->head;
    while (current) {
        LinkedList_Node *next = current->next;
        if (LinkedList_Node_delete(current)){
            return 2; //fail
        }
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->data_free_function = NULL;
    list->size = 0;

    return 0; //success
}

int LinkedList_List_deleteWithData(
    LinkedList_List *list
) {
    if (!list){ 
        return 1; //fail
    }
    LinkedList_Node *current = list->head;
    while (current) {
        LinkedList_Node *next = current->next;
        if (LinkedList_Node_deleteWithData(current)){
            return 2;  //fail
        }
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->data_free_function = NULL;
    list->size = 0;
    return 0; //success
}



// Insert a new node at the head of the list
int LinkedList_List_pushHead(
    LinkedList_List *list, 
    void *data
) {
    if (!list){ 
        return 1;  //fail
    }

    LinkedList_Node *new_node = (LinkedList_Node *)malloc(sizeof(LinkedList_Node));
    if (!new_node) {
        return 2; //fail
    }

    if (LinkedList_Node_init(new_node, list->data_free_function, data)){
        return 3; //fail
    }

    new_node->next = list->head;
    if (list->head) {
        list->head->prev = new_node;
    }
    list->head = new_node;

    if (!list->tail) {
        list->tail = new_node;
    }

    list->size++;
    return 0; //success
}

// Insert a new node at the tail of the list
int LinkedList_List_pushTail(
    LinkedList_List *list, 
    void *data
) {
    if (!list) {
        return 1; //fail
    }

    LinkedList_Node *new_node = (LinkedList_Node *)malloc(sizeof(LinkedList_Node));
    if (!new_node){
        return 2; //fail
    }

    if (LinkedList_Node_init(new_node, list->data_free_function, data )){
        return 3; //fail
    }
    new_node->prev = list->tail;
    if (list->tail) {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    if (!list->head) {
        list->head = new_node;
    }

    list->size++;
    return 0; //success
}

// Pop a node from the tail of the list
void* LinkedList_List_popTail(
    LinkedList_List *list
) {
    if (!list || !list->tail) {
        return NULL;
    }

    LinkedList_Node *node = list->tail;
    void *data = node->data;

    list->tail = node->prev;
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    if (LinkedList_Node_delete(node)){
        return NULL; //fail
    }
    list->size--;

    return data;
}

// Pop a node from the head of the list
void* LinkedList_List_popHead(
    LinkedList_List *list
) {
    if (!list || !list->head){
        return NULL;
    }

    LinkedList_Node *node = list->head;
    void *data = node->data;

    list->head = node->next;
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    if (LinkedList_Node_delete(node)){
        return NULL; //fail
    }
    list->size--;

    return data;
}

// Find a node with data matching the comparator function
LinkedList_Node* LinkedList_List_findNode(
    LinkedList_List *list, 
    void *data, 
    int (*comparator)(void *, void *)
) {
    if (!list || !comparator) return NULL;

    LinkedList_Node *current = list->head;
    while (current) {
        if (comparator(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}
void* LinkedList_List_find(
    LinkedList_List* list, 
    void *data, 
    int (*comparator)(void *, void *)
){
    if (!list || !comparator) return NULL;

    LinkedList_Node *current = list->head;
    while (current) {
        if (comparator(current->data, data) == 0) {
            return current->data;
        }
        current = current->next;
    }

    return NULL;
}
void* LinkedList_List_pop(
    LinkedList_List* list, 
    void *data, 
    int (*comparator)(void *, void *)
){
    if (!list || !comparator) return NULL;

    LinkedList_Node *current = list->head;
    while (current) {
        if (comparator(current->data, data) == 0) {

            if (LinkedList_Node_delete(current)){
                return NULL; //fail
            }
            return current->data;
        }
        current = current->next;
    }

    return NULL;
}

int LinkedList_List_deleteFrom(
    LinkedList_List* list, 
    void *data, 
    int (*comparator)(void *other, void *data)
){
    if (!list || !comparator) return 1;

    LinkedList_Node *current = list->head;
    while (current) {
        if (comparator(current->data, data) == 0) {

            if (LinkedList_Node_delete(current)){
                return 2; //fail
            }
            return 0;
        }
        current = current->next;
    }

    return -1;
}

int LinkedList_List_deleteFromWithData(
    LinkedList_List* list, 
    void *data, 
    int (*comparator)(void *, void *)
){
    if (!list || !comparator) return 1;

    LinkedList_Node *current = list->head;
    while (current) {
        if (comparator(current->data, data) == 0) {

            if (LinkedList_Node_deleteWithData(current)){
                return 2; //fail
            }
            return 0;
        }
        current = current->next;
    }

    return -1;
}


// Get the size of the list
size_t LinkedList_List_size(
    LinkedList_List *list
) {
    if (!list) return 0;
    return list->size;
}

// Peek at the head of the list without removing it
void* LinkedList_List_peakHead(
    LinkedList_List *list
) {
    if (!list || !list->head) return NULL;
    return list->head->data;
}

// Peek at the tail of the list without removing it
void* LinkedList_List_peakTail(
    LinkedList_List *list
) {
    if (!list || !list->tail) return NULL;
    return list->tail->data;
}

// Access a specific index in the list, optionally iterating forward or backward
void* LinkedList_List_peakIndex(
    LinkedList_List *list, 
    size_t index, 
    bool iter_forward
) {
    if (!list || index >= list->size) return NULL;

    LinkedList_Node *current = iter_forward ? list->head : list->tail;
    size_t i = iter_forward ? 0 : list->size - 1;

    while (current && i != index) {
        current = iter_forward ? current->next : current->prev;
        i = iter_forward ? i + 1 : i - 1;
    }

    return current ? current->data : NULL;
}

LinkedList_Node* LinkedList_List_index(
    LinkedList_List *list, 
    size_t index, 
    bool iter_forward
) {
    if (!list || index >= list->size) return NULL;

    LinkedList_Node *current = iter_forward ? list->head : list->tail;
    size_t i = iter_forward ? 0 : list->size - 1;

    while (current && i != index) {
        current = iter_forward ? current->next : current->prev;
        i = iter_forward ? i + 1 : i - 1;
    }

    return current;
}
