#include <iostream>
#include <cassert>
using namespace std;
/*
This code implements a Linked Queue in C++ using a singly linked list. A queue follows the FIFO (First In, First Out) principle.
The class provides operations to:

1- Enqueue: Add an element to the rear of the queue.
2- Dequeue: Remove the element from the front of the queue.
3- getfront: Display the front element.
4- getrear: Display the rear element.
5- getsize: Show the current number of elements in the queue.
6- display: Print all elements from front to rear.
7- ClearQueue: Remove all elements from the queue.
*/
class LinkedQueue
{
private:
    struct Node {
        int item;      // Data stored in the node (queue element)
        Node* next;    // Pointer to the next node in the queue
    };

    Node* front, * rear;  // front points to the front element, rear points to the last element
    int length;           // Tracks the current size of the queue

public:
    // Constructor: Initializes an empty queue
    LinkedQueue() 
    {
        front = rear = nullptr;
        length = 0;
    }

    // Checks if the queue is empty (if length is 0)
    bool isEmpty() 
    {
        return length == 0;
    }

    // Adds an element to the end of the queue (rear)
    void Enqueue(int element)
    {
        if (isEmpty()) 
        {
            // If the queue is empty, initialize front and rear to the new node
            front = new Node;
            front->item = element;
            front->next = nullptr;
            rear = front;
        } 
        else 
        {
            // If the queue is not empty, add a new node to the rear
            Node* newnode = new Node;
            newnode->item = element;
            newnode->next = nullptr;
            rear->next = newnode; 
            rear = newnode;
        }
        length++;
    }

    // Removes the front element from the queue
    void Dequeue()
    {
        if (isEmpty()) 
            cout << "Can't Dequeue Empty Queue.....!\n"; 
        else 
        {
            Node* temp = front;
            front = front->next;
            temp = temp->next = nullptr;
            delete temp;
        }
        length--;
    }

    // Displays the front element of the queue
    void getfront()
    {
        assert(!isEmpty());   // Ensure the queue is not empty before accessing the front
        cout << "Front = " << front->item << endl;
    }

    // Displays the rear element of the queue
    void getrear()
    {
        assert(!isEmpty());   // Ensure the queue is not empty before accessing the rear
        cout << "Rear = " << rear->item << endl;
    }

    // Displays the current size of the queue
    void getsize()
    {
        cout << "Size of Queue = " << length << endl;
    }

    // Displays all the elements in the queue
    void display()
    {
        Node* cur = front;
        cout << "Elements of Queue: [ ";
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }

    // Clears all elements from the queue
    void ClearQueue()
    {
        Node* current;
        while (front != nullptr)
        {
            current = front;
            front = front->next;
            delete current;
        }
        rear = nullptr;
    }
};

int main()
{
    LinkedQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Dequeue();
    q.display();
    q.getsize();
    q.getfront();
    q.getrear();
    q.ClearQueue();
    q.display();
}
