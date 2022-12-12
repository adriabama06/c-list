#include <stdlib.h>
#include <memory.h>

typedef struct node
{
    void* value;
    struct node* next;
} node_t;

void NodeListPrint(node_t* head, void (print_function)(unsigned int*, node_t*))
{
    node_t* temp = head;
    int end = 0;

    for (unsigned int i = 0; !end; i++)
    {
        if(temp->next == NULL) end = 1;

        print_function(&i, temp);

        temp = temp->next;
    }
}

node_t* NewNode(void* value, size_t size)
{
    node_t* temp = (node_t*) malloc(sizeof(node_t));

    temp->value = malloc(size);
    memcpy(temp->value, value, size);

    temp->next = NULL;

    return temp;
}

node_t* InsertNode(node_t** head, node_t* to_insert)
{
    to_insert->next = *head;
    *head = to_insert;
    return to_insert;
}

void InsertNodeAfter(node_t* node_after, node_t* to_insert)
{
    to_insert->next = node_after->next;

    node_after->next = to_insert;
}

node_t* FindNode(node_t* head, int (compare)(void*))
{
    node_t* temp = head;
    
    while (temp->next != NULL)
    {
        if(compare(temp->value)) {
            return temp;
        }

        temp = temp->next;
    }
    
    return NULL;
}

