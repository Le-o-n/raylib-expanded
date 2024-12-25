#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h> // For size_t

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
void LinkedList_Node_init(void *data);
void LinkedList_Node_unload(LinkedList_Node *node);

// Function prototypes for LinkedList_List
void LinkedList_Doubly_init(LinkedList_List* list);
void LinkedList_Doubly_unload(LinkedList_List* list);
int LinkedList_Doubly_insertAtHead(LinkedList_List* list, void *data);
int LinkedList_Doubly_insertAtTail(LinkedList_List* list, void *data);
void* LinkedList_Doubly_pop(LinkedList_List* list);
void* LinkedList_Doubly_popHead(LinkedList_List* list);
LinkedList_Node* LinkedList_Doubly_find(LinkedList_List* list, void *data, int (*comparator)(void *, void *));
size_t LinkedList_Doubly_size(LinkedList_List* list);

#endif // LINKED_LIST_H
