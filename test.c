#include "C/LinkedList.h"

#include <stdio.h>
#include <memory.h>

void mytype_print(unsigned int* index, node_t* current)
{
    unsigned int* value = current->value;

    printf("%d -> %u\n", *index, *value);
}

int main()
{
    node_t* head = NULL;
    //node_t* temp;

    for (unsigned int i = 5; i < 10; i++)
    {
        // temp = NewNode(&i, sizeof(unsigned int));
        // InsertNode(&head, temp);
        InsertNode(&head, NewNode(&i, sizeof(unsigned int)));
    }
    
    NodeListPrint(head, mytype_print);

    return 0;
}