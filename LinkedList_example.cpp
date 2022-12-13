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

    myList.InsertAfter(
        myList.Find(7),
        myList.CreateNode(50)
    );

    cout << myList << endl;



    cout << "Remove 50" << endl;

    myList.Remove(50);

    cout << myList << endl;



    cout << "Remove element at index 3 (for human, 2 for programing array) (" << myList.Get(2)->value << ")" << endl;
    
    /*
    Elements: [x, x, x, x, x]
    Index:     0, 1, 2, 3, 4
    */
    myList.RemoveIndex(2);

    cout << myList << endl;



    cout << "Clear all nodes" << endl;

    myList.Clear();

    cout << myList << endl;

    return 0;
}
