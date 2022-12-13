#include "C/LinkedList.h"

#include <stdio.h>
#include <memory.h>

void mytype_print(unsigned int* index, node_t* current)
{
    unsigned int* value = current->value;

    printf("%u", *value);
}

int mytype_check(void* __node_value, void* __value)
{
    unsigned int* node_value = (unsigned int*) __node_value;
    unsigned int* value = (unsigned int*) __value;

    return *node_value == *value;
}

int main()
{
    node_t* head = NULL;
    //node_t* temp;

    for (unsigned int i = 5; i < 10; i++)
    {
        // temp = NewNode(&i, sizeof(unsigned int));
        // InsertNode(&head, temp);
        InsertNode(&head, CreateNode(&i, sizeof(unsigned int)));
    }
    
    Print(head, mytype_print);



    printf("Add 50 after 7\n");

    unsigned int fiveteen = 50;
    unsigned int seven = 7;

    InsertAfter(
        Find(head, mytype_check, (void*) &seven),
        CreateNode(&fiveteen, sizeof(unsigned int))
    );

    Print(head, mytype_print);



    printf("Remove 50\n");

    Remove(head, mytype_check, (void*) &fiveteen);

    Print(head, mytype_print);



    printf("Remove element at index 3 (for human, 2 for programing array) (%d)\n", *(unsigned int*) Get(head, 2)->value);

    /*
    Elements: [x, x, x, x, x]
    Index:     0, 1, 2, 3, 4
    */
    RemoveIndex(head, 2);

    Print(head, mytype_print);



    printf("Clear all nodes\n");

    Clear(&head);

    Print(head, mytype_print);

    return 0;
}
