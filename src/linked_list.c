#include "data_structures/linked_list.h"
#include <stdlib.h>
#include <string.h>

// Initialize a node with given data
void LinkedList_Node_init(
    LinkedList_Node *node, 
    void *data
) {
    if (!node) return;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
}

// Unload a node (free memory if applicable)
void LinkedList_Node_unload(
    LinkedList_Node *node
) {
    if (!node) return;
    free(node);
}

// Initialize an empty doubly linked list
void LinkedList_List_init(
    LinkedList_List *list
) {
    if (!list) return;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Unload a doubly linked list (free all nodes)
void LinkedList_List_unload(
    LinkedList_List *list
) {
    if (!list) return;
    LinkedList_Node *current = list->head;
    while (current) {
        LinkedList_Node *next = current->next;
        LinkedList_Node_unload(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Insert a new node at the head of the list
int LinkedList_List_pushHead(
    LinkedList_List *list, 
    void *data
) {
    if (!list) return -1;

    LinkedList_Node *new_node = (LinkedList_Node *)malloc(sizeof(LinkedList_Node));
    if (!new_node) return -1;

    LinkedList_Node_init(new_node, data);

    new_node->next = list->head;
    if (list->head) {
        list->head->prev = new_node;
    }
    list->head = new_node;

    if (!list->tail) {
        list->tail = new_node;
    }

    list->size++;
    return 0;
}

// Insert a new node at the tail of the list
int LinkedList_List_pushTail(
    LinkedList_List *list, 
    void *data
) {
    if (!list) return -1;

    LinkedList_Node *new_node = (LinkedList_Node *)malloc(sizeof(LinkedList_Node));
    if (!new_node) return -1;

    LinkedList_Node_init(new_node, data);

    new_node->prev = list->tail;
    if (list->tail) {
        list->tail->next = new_node;
    }
    list->tail = new_node;

    if (!list->head) {
        list->head = new_node;
    }

    list->size++;
    return 0;
}

// Pop a node from the tail of the list
void* LinkedList_List_popTail(
    LinkedList_List *list
) {
    if (!list || !list->tail) return NULL;

    LinkedList_Node *node = list->tail;
    void *data = node->data;

    list->tail = node->prev;
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    LinkedList_Node_unload(node);
    list->size--;

    return data;
}

// Pop a node from the head of the list
void* LinkedList_List_popHead(
    LinkedList_List *list) {
    if (!list || !list->head) return NULL;

    LinkedList_Node *node = list->head;
    void *data = node->data;

    list->head = node->next;
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    LinkedList_Node_unload(node);
    list->size--;

    return data;
}

// Find a node with data matching the comparator function
LinkedList_Node* LinkedList_List_find(
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

// Get the size of the list
size_t LinkedList_List_size(
    LinkedList_List *list
) {
    if (!list) return 0;
    return list->size;
}

// Peek at the head of the list without removing it
void* LinkedList_List_peakHead(LinkedList_List *list) {
    if (!list || !list->head) return NULL;
    return list->head->data;
}

// Peek at the tail of the list without removing it
void* LinkedList_List_peakTail(LinkedList_List *list) {
    if (!list || !list->tail) return NULL;
    return list->tail->data;
}

// Access a specific index in the list, optionally iterating forward or backward
void* LinkedList_List_peakIndex(LinkedList_List *list, size_t index, bool iter_forward) {
    if (!list || index >= list->size) return NULL;

    LinkedList_Node *current = iter_forward ? list->head : list->tail;
    size_t i = iter_forward ? 0 : list->size - 1;

    while (current && i != index) {
        current = iter_forward ? current->next : current->prev;
        i = iter_forward ? i + 1 : i - 1;
    }

    return current ? current->data : NULL;
}

LinkedList_Node* LinkedList_List_index(LinkedList_List *list, size_t index, bool iter_forward) {
    if (!list || index >= list->size) return NULL;

    LinkedList_Node *current = iter_forward ? list->head : list->tail;
    size_t i = iter_forward ? 0 : list->size - 1;

    while (current && i != index) {
        current = iter_forward ? current->next : current->prev;
        i = iter_forward ? i + 1 : i - 1;
    }

    return current;
}
