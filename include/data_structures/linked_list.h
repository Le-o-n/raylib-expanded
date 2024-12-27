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
    struct LinkedList_Node *next;
    struct LinkedList_Node *prev;
} LinkedList_Node;

/**
 * Doubly linked list structure.
 */
typedef struct LinkedList_List {
    LinkedList_Node *head;
    LinkedList_Node *tail;
    size_t size;
} LinkedList_List;

// Function prototypes for LinkedList_Node
void LinkedList_Node_init(LinkedList_Node* node, void *data);
void LinkedList_Node_unload(LinkedList_Node *node);

// Function prototypes for LinkedList_List
void LinkedList_List_init(LinkedList_List* list);
void LinkedList_List_unload(LinkedList_List* list);
int LinkedList_List_pushHead(LinkedList_List* list, void *data);
int LinkedList_List_pushTail(LinkedList_List* list, void *data);
void* LinkedList_List_popTail(LinkedList_List* list);
void* LinkedList_List_popHead(LinkedList_List* list);
LinkedList_Node* LinkedList_List_find(LinkedList_List* list, void *data, int (*comparator)(void *, void *));
size_t LinkedList_List_size(LinkedList_List* list);

void* LinkedList_List_peakHead(LinkedList_List* list);
void* LinkedList_List_peakTail(LinkedList_List* list);
void* LinkedList_List_peakIndex(LinkedList_List* list, size_t index, bool iter_forward);
LinkedList_Node* LinkedList_List_index(LinkedList_List* list, size_t index, bool iter_forward);

#endif // LINKED_LIST_H
