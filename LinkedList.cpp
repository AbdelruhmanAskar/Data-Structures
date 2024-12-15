#include <iostream>
#include <cassert>
using namespace std;
/*
This code implements a Singly Linked List in C++ with various operations to manage elements within the list. The list supports the following operations:

1- InsertFirst: Adds an element at the beginning of the list.
2- InsertLast: Adds an element at the end of the list.
3- InsertAtPos: Inserts an element at a specific position.
4- RemoveFirst: Removes the first element in the list.
5- RemoveLast: Removes the last element in the list.
6- Remove: Removes a specific element from the list.
7- reverse: Reverses the order of elements in the list.
8- Search: Searches for an element in the list and displays its index.
9- Display: Displays all elements in the list.
*/
class linkedlist {
private:
    struct Node {
        int item;
        Node* next;
    };
    Node* head;  // Points to the first node in the list
    Node* tail;  // Points to the last node in the list
    int length;  // Tracks the length of the list

public:
    linkedlist() {
        tail = head = nullptr;
        length = 0;
    }

    // Checks if the list is empty
    bool isEmpty() {
        return length == 0; // head == nullptr
    }

    // Inserts a new node at the beginning of the list
    void InsertFirst(int element) {
        Node* newnode = new Node;
        newnode->item = element;
        if (isEmpty()) {
            newnode->next = nullptr;
            head = tail = newnode; // List was empty; set head and tail to new node
        } else {
            newnode->next = head; // Point new node to current head
            head = newnode;       // Update head to the new node
        }
        length++;
    }

    // Inserts a new node at the end of the list
    void InsertLast(int element) {
        Node* newnode = new Node;
        newnode->item = element;
        if (isEmpty()) {
            newnode->next = nullptr;
            head = tail = newnode; // List was empty; set head and tail to new node
        } else {
            tail->next = newnode;  // Append new node to the tail
            newnode->next = nullptr;
            tail = newnode;        // Update tail to the new node
        }
        length++;
    }

    // Inserts a new node at a specific position
    void InsertAtPos(int pos, int element) {
        if (pos < 0 || pos > length) {
            cout << "Out of Range on InsertAtPos...!\n";
        } else {
            Node* newnode = new Node;
            newnode->item = element;
            if (pos == 0) {
                InsertFirst(element); // Insert at head
            } else if (pos == length) {
                InsertLast(element);  // Insert at tail
            } else {
                Node* cur = head;
                for (int i = 1; i < pos; i++)
                    cur = cur->next;  // Navigate to the node before the target position
                newnode->next = cur->next;
                cur->next = newnode;
                length++;
            }
        }
    }

    // Removes the first node in the list
    void RemoveFirst() {
        if (isEmpty()) {
            cout << "Can't delete Empty List on RemoveFirst...!\n";
        } else if (length == 1) { // Special case: single-node list
            delete head;
            head = tail = nullptr;
            length--;
        } else {
            Node* cur = head;
            head = head->next; // Move head to the next node
            delete cur;        // Delete the old head
            length--;
        }
    }

    // Removes the last node in the list
    void RemoveLast() {
        if (isEmpty()) {
            cout << "Can't delete Empty List on RemoveLast...!\n";
        } else if (length == 1) { // Special case: single-node list
            delete head;
            head = tail = nullptr;
            length--;
        } else {
            Node* cur = head->next;
            Node* prv = head;
            while (cur != tail) { // Find the second-to-last node
                prv = cur;
                cur = cur->next;
            }
            delete cur;          // Delete the tail node
            prv->next = nullptr; // Update the new tail
            tail = prv;
            length--;
        }
    }

    // Removes a specific element from the list
    void Remove(int element) {
        if (isEmpty()) {
            cout << "Can't delete Empty List on Remove...!\n";
            return;
        }
        Node* cur, *prv;
        if (head->item == element) { // Special case: element is at the head
            cur = head;
            head = head->next;
            delete cur;
            length--;
            if (isEmpty())
                tail = nullptr; // Reset tail if list becomes empty
        } else {
            cur = head->next;
            prv = head;
            while (cur != nullptr && cur->item != element) {
                prv = cur;
                cur = cur->next; // Traverse to find the target node
            }
            if (cur == nullptr) {
                cout << "The Element Doesn't Exist In The List on Remove...!\n";
            } else {
                prv->next = cur->next; // Unlink the target node
                if (tail == cur) {    // Update tail if the removed node was the last
                    tail = prv;
                }
                delete cur;
                length--;
            }
        }
    }

    // Reverses the linked list
    void reverse() {
        Node* prv = nullptr;
        Node* cur = head;
        Node* next = nullptr;
        tail = head; // Update tail to the old head
        while (cur != nullptr) {
            next = cur->next;  // Save the next node
            cur->next = prv;   // Reverse the link
            prv = cur;         // Move previous forward
            cur = next;        // Move current forward
        }
        head = prv; // Update head to the new head
    }

    // Searches for an element in the list
    void Search(int element) {
        Node* cur = head;
        bool found = false;
        int pos = 0;
        while (cur != nullptr) {
            if (cur->item == element) {
                found = true;
                break;
            }
            cur = cur->next;
            pos++;
        }
        if (found)
            cout << "The Element Found in Index : " << pos << endl;
        else
            cout << "The Element Has not Found on Search...!\n";
    }

    // Displays all elements in the list
    void Display() {
        cout << "Linked List Elements : [ ";
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

int main() {
    linkedlist l;
    l.InsertFirst(10);
    l.InsertAtPos(1, 20);
    l.InsertLast(30);
    l.InsertLast(40);
    l.InsertLast(50);
    l.InsertAtPos(5, 60);
    l.InsertFirst(0);
    l.Display();
    l.RemoveFirst();
    l.RemoveLast();
    l.Remove(30);
    l.Display();
    l.InsertFirst(0);
    l.InsertAtPos(1, 10);
    l.Display();
    l.Remove(10);
    l.Remove(20);
    l.Display();
    l.reverse();
    l.Display();
    l.Search(40);
}
