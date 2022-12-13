#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node
{
    void* value;
    struct node* next;
} node_t;

node_t* CreateNode(void* value, size_t value_size)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));

    new_node->value = malloc(value_size);
    memcpy(new_node->value, value, value_size);

    new_node->next = NULL;

    return new_node;
}

void InsertNode(node_t** head, node_t* to_insert)
{
    to_insert->next = *head;
    *head = to_insert;
}

node_t* AddNode(node_t** head, void* value, size_t value_size)
{
    node_t* new_node = CreateNode(value, value_size);

    InsertNode(head, new_node);

    return new_node;
}

void InsertAfter(node_t* node_after, node_t* to_insert)
{
    to_insert->next = node_after->next;
    node_after->next = to_insert;
}

node_t* Find(node_t* head, int (check)(void*, void*), void* value)
{
    node_t* temp = head;

    while(temp != NULL)
    {
        if(check(temp->value, value))
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

node_t* Get(node_t* head, unsigned int index)
{
    node_t* temp = head;

    for(unsigned int i = 0; temp != NULL; i++)
    {
        if(i == index)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Remove last element
void RemoveLast(node_t* head)
{
    node_t* temp = head;
        
    head = head->next;

    free(temp);
}

void Remove(node_t* head, int (check)(void*, void*), void* value)
{
    node_t *temp = head;
    int has_found = 0;

    while (temp != NULL)
    {
        if (temp->next != NULL && check(temp->next->value, value))
        {
            has_found = 1;
            break;
        }

        temp = temp->next;
    }

    // if has_found = 1;
    // temp => 1 position before value you like find

    if (!has_found)
    {
        return;
    }

    node_t *objective = temp->next;

    temp->next = objective->next; // => temp->next = temp->next->next;

    free(objective);
}

void RemoveIndex(node_t* head, unsigned int index)
{
    if (index == 0)
    {
        RemoveLast(head);
        return;
    }

    node_t *temp = head;
    int has_found = 0;

    for (unsigned int i = 0; temp != NULL; i++)
    {
        if (temp->next != NULL && (i + 1) == index)
        {
            has_found = 1;
            break;
        }

        temp = temp->next;
    }

    // if has_found = 1;
    // temp => 1 position before value you like find

    if (!has_found)
    {
        return;
    }

    node_t *objective = temp->next;

    temp->next = objective->next; // => temp->next = temp->next->next;

    free(objective);
}

void Clear(node_t** head)
{
    node_t* temp = *head;

    while(temp != NULL)
    {
        node_t* next = temp->next;

        free(temp);

        temp = next;
    }

    *head = NULL;
}

void Print(node_t* head, void (print_function)(unsigned int*, node_t*))
{
    node_t* temp = head;
    int end = 0;

    printf("[");

    for (unsigned int i = 0; temp != NULL; i++)
    {
        print_function(&i, temp);

        if(temp->next != NULL)
        {
            printf(", ");
        }

        temp = temp->next;
    }

    printf("]\n");
}