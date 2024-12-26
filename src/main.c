//#include "my_game.h"
#include "data_structures/linked_list.h"
#include <stdio.h>

int main(void)
{

    LinkedList_List list;

    LinkedList_List_init(&list);

    LinkedList_List_pushHead(&list, (void*)1);
    LinkedList_List_pushHead(&list, (void*)2);
    LinkedList_List_pushHead(&list, (void*)3);
    LinkedList_List_pushHead(&list, (void*)4);

    LinkedList_List_pushTail(&list, (void*)0);

    LinkedList_List_popTail(&list);

    LinkedList_List_popHead(&list);

    LinkedList_Node* current = list.head;

    size_t index = 0;

    while (current != NULL){
        
        printf("Index %d: %d\n", index, (size_t)current->data);
        index++;
        current = current->next;
    }

    

    //MyGame_run();
    
    
    return 0;
}