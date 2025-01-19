#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h> // For size_t
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Node structure for a linked list.
 */
typedef struct LinkedList_Node {
    void *data;
    int (*data_free_function)(void*);
    struct LinkedList_Node *next;
    struct LinkedList_Node *prev;
} LinkedList_Node;

/**
 * Doubly linked list structure.
 */
typedef struct LinkedList_List {
    LinkedList_Node *head;
    LinkedList_Node *tail;
    int (*data_free_function)(void*);
    size_t size;
} LinkedList_List;

int LinkedList_genericFree(void* data); // used if data is just some contiguous memory
int LinkedList_noFree(void* data);      // used for primatives

// Function prototypes for LinkedList_Node
int LinkedList_Node_init(LinkedList_Node* node, int (*data_free_function)(void*), void *data);
int LinkedList_Node_delete(LinkedList_Node *node);
int LinkedList_Node_deleteWithData(LinkedList_Node *node);

// Function prototypes for LinkedList_List
int LinkedList_List_init(LinkedList_List* list, int (*data_free_function)(void*));
int LinkedList_List_delete(LinkedList_List* list); // frees struct
int LinkedList_List_deleteWithData(LinkedList_List* list); // frees struct + frees nodes
int LinkedList_List_pushHead(LinkedList_List* list, void *data);
int LinkedList_List_pushTail(LinkedList_List* list, void *data);
void* LinkedList_List_popTail(LinkedList_List* list);
void* LinkedList_List_popHead(LinkedList_List* list);
LinkedList_Node* LinkedList_List_findNode(LinkedList_List* list, void *data, int (*comparator)(void *, void *));
void* LinkedList_List_find(LinkedList_List* list, void *data, int (*comparator)(void *, void *));
void* LinkedList_List_pop(LinkedList_List* list, void *data, int (*comparator)(void *, void *));
int LinkedList_List_deleteFrom(LinkedList_List* list, void *data, int (*comparator)(void *other, void *data));
int LinkedList_List_deleteFromWithData(LinkedList_List* list, void *data, int (*comparator)(void *, void *));

size_t LinkedList_List_size(LinkedList_List* list);
void* LinkedList_List_peakHead(LinkedList_List* list);
void* LinkedList_List_peakTail(LinkedList_List* list);
void* LinkedList_List_peakIndex(LinkedList_List* list, size_t index, bool iter_forward);
LinkedList_Node* LinkedList_List_index(LinkedList_List* list, size_t index, bool iter_forward);

#endif // LINKED_LIST_H
