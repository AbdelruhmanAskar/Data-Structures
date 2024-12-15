#include <iostream>
#include <cassert>
using namespace std;

// Class for Doubly Linked List
class Doublylist
{
private:
    // Define a structure for the nodes in the doubly linked list
    struct Node
    {
        int item;       // Data stored in the node
        Node* prv;      // Pointer to the previous node
        Node* next;     // Pointer to the next node
    };

    Node* first; // Pointer to the first node in the list
    Node* last;  // Pointer to the last node in the list
    int length;  // Number of elements in the list

public:
    // Constructor: Initialize an empty list
    Doublylist()
    {
        first = last = nullptr;
        length = 0;
    }

    // Check if the list is empty
    bool isEmpty()
    {
        return length == 0;
    }

    // Insert a new element at the beginning of the list
    void InsertFirst(int element)
    {
        Node* newnode = new Node;
        newnode->item = element;
        if (isEmpty()) // If the list is empty
        {
            first = last = newnode;
            newnode->next = newnode->prv = nullptr;
        }
        else
        {
            newnode->next = first;
            newnode->prv = nullptr;
            first->prv = newnode;
            first = newnode;
        }
        length++;
    }

    // Insert a new element at the end of the list
    void InsertLast(int element)
    {
        Node* newnode = new Node;
        newnode->item = element;
        if (isEmpty()) // If the list is empty
        {
            first = last = newnode;
            newnode->next = newnode->prv = nullptr;
        }
        else
        {
            newnode->next = nullptr;
            newnode->prv = last;
            last->next = newnode;
            last = newnode;
        }
        length++;
    }

    // Insert a new element at a specific position
    void InsertAtPos(int pos, int element)
    {
        Node* newnode = new Node;
        newnode->item = element;

        // Validate position
        if (pos < 0 || pos > length)
        {
            cout << "Out of Range on InsertAtPos...!\n";
            return;
        }

        if (isEmpty()) // If the list is empty
        {
            first = last = newnode;
            newnode->next = newnode->prv = nullptr;
            length++;
        }
        else if (pos == 0)
            InsertFirst(element); // Insert at the beginning
        else if (pos == length)
            InsertLast(element); // Insert at the end
        else
        {
            Node* cur = first;
            for (int i = 1; i < pos; i++)
                cur = cur->next; // Traverse to the position

            // Insert in the middle
            newnode->next = cur->next;
            newnode->prv = cur;
            cur->next = newnode;
            newnode->next->prv = newnode;
            length++;
        }
    }

    // Remove the first element from the list
    void RemoveFirst()
    {
        if (isEmpty()) // Cannot remove from an empty list
        {
            cout << "Can't Delete Empty List on RemoveFirst...!\n";
            return;
        }
        else if (length == 1) // If the list has only one element
        {
            delete first;
            first = last = nullptr;
        }
        else
        {
            Node* cur = first;
            first = first->next;
            first->prv = nullptr;
            delete cur;
        }
        length--;
    }

    // Remove the last element from the list
    void RemoveLast()
    {
        if (isEmpty()) // Cannot remove from an empty list
        {
            cout << "Can't Delete Empty List on RemoveLast...!\n";
            return;
        }
        else if (length == 1) // If the list has only one element
        {
            delete first;
            first = last = nullptr;
        }
        else
        {
            Node* cur = last;
            last = last->prv;
            last->next = nullptr;
            delete cur;
        }
        length--;
    }

    // Remove a specific element from the list
    void Remove(int element)
    {
        if (isEmpty()) // Cannot remove from an empty list
        {
            cout << "Can't Delete Empty List on Remove...!\n";
            return;
        }
        else if (first->item == element) // If the first element matches
            RemoveFirst();
        else
        {
            Node* cur = first->next;

            // Traverse the list to find the element
            while (cur != nullptr && cur->item != element)
                cur = cur->next;

            if (cur == nullptr) // Element not found
            {
                cout << "The Element is Not Found Here on Remove...!\n";
                return;
            }
            else if (cur->next == nullptr) // Element is the last node
                RemoveLast();
            else
            {
                // Remove the element
                cur->prv->next = cur->next;
                cur->next->prv = cur->prv;
                delete cur;
                length--;
            }
        }
    }

    // Display the elements of the list from beginning to end
    void Display()
    {
        Node* cur = first;
        cout << "Doubly Linked List Elements are : [ ";
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }

    // Display the elements of the list in reverse order
    void ReversedDisplay()
    {
        Node* cur = last;
        cout << "Doubly Linked List Elements After Reversed are : [ ";
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->prv;
        }
        cout << "]\n";
    }

    // Destructor: Clean up dynamically allocated memory
    ~Doublylist()
    {
        Node* cur;
        while (first != nullptr)
        {
            cur = first;
            first = first->next;
            delete cur;
        }
        last = nullptr;
        length = 0;
    }
};

// Test the Doubly Linked List functionality
int main()
{
    Doublylist d;
    d.InsertFirst(0);
    d.InsertAtPos(1, 10);
    d.InsertAtPos(2, 20);
    d.InsertLast(30);
    d.InsertLast(40);
    d.InsertLast(50);
    d.Display();
    d.ReversedDisplay();
    d.RemoveFirst();
    d.RemoveLast();
    d.Display();
    d.Remove(20);
    d.Display();
}
