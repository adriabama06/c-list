#include <iostream>
#include <vector>

template <typename T>
class LinkedList
{
public:
    typedef struct node {
        T value;
        struct node* next;
    } node_t;

    node_t* head = nullptr;

    node_t* CreateNode(T value)
    {
        node_t* new_node = new node_t;

        new_node->value = value;
        new_node->next = nullptr;

        return new_node;
    }

    void Insert(node_t* to_add)
    {
        to_add->next = head;
        head = to_add;
    }

    void Add(T value)
    {
        node_t* new_node = CreateNode(value);
        Insert(new_node);
    }

    void InsertAfter(node_t* node_after, node_t* to_insert)
    {
        to_insert->next = node_after->next;
        node_after->next = to_insert;
    }

    node_t* Find(T value)
    {
        node_t* temp = head;

        while(temp != nullptr)
        {
            if(temp->value == value)
            {
                return temp;
            }

            temp = temp->next;
        }

        return nullptr;
    }

    node_t* Get(unsigned int index)
    {
        node_t* temp = head;

        for(unsigned int i = 0; temp != nullptr; i++)
        {
            if(i == index)
            {
                return temp;
            }

            temp = temp->next;
        }

        return nullptr;
    }

    // Remove last element
    void Remove()
    {
        node_t* temp = head;
        
        head = head->next;

        delete temp;
    }

    void Remove(T value)
    {
        node_t* temp = head;
        int has_found = 0;

        while(temp != nullptr)
        {
            if(temp->next != nullptr && temp->next->value == value)
            {
                has_found = 1;
                break;
            }

            temp = temp->next;
        }

        // if has_found = 1;
        // temp => 1 position before value you like find

        if(!has_found)
        {
            return;
        }

        node_t* objective = temp->next;

        temp->next = objective->next; // => temp->next = temp->next->next;

        delete objective;
    }

    void RemoveIndex(unsigned int index)
    {
        if(index == 0)
        {
            Remove();
            return;
        }

        node_t* temp = head;
        int has_found = 0;

        for(unsigned int i = 0; temp != nullptr; i++)
        {
            if(temp->next != nullptr && (i+1) == index)
            {
                has_found = 1;
                break;
            }

            temp = temp->next;
        }

        // if has_found = 1;
        // temp => 1 position before value you like find

        if(!has_found)
        {
            return;
        }

        node_t* objective = temp->next;

        temp->next = objective->next; // => temp->next = temp->next->next;

        delete objective;
    }

    void Clear()
    {
        while(head != nullptr)
        {
            Remove();
        }
    }

    // On create don't need any
    LinkedList() {}

    ~LinkedList()
    {
        Clear();
    }

    friend std::ostream& operator<<(std::ostream& os, LinkedList const& object)
    {
        os << "[";

        node_t* temp = object.head;

        while(temp != nullptr)
        {
            os << temp->value;

            if(temp->next != nullptr)
            {
                os << ", ";
            }

            temp = temp->next;
        }

        return os << "]";
    }
};