#include "C++/LinkedList.hpp"

#include <iostream>

using namespace std;

int main()
{
    LinkedList<unsigned int> myList = LinkedList<unsigned int>();

    for (unsigned int i = 5; i < 10; i++)
    {
        myList.Add(i);
    }

    cout << myList << endl;

    cout << "Add 50 after 7" << endl;

    myList.AddAfter(
        myList.Find(7),
        myList.CreateNode(50)
    );

    cout << myList << endl;

    cout << "Remove 50" << endl;

    myList.Remove(50);

    cout << myList << endl;

    cout << "Clear all nodes" << endl;

    myList.Clear();

    cout << myList << endl;

    return 0;
}