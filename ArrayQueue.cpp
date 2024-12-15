#include <iostream>
#include <cassert>
using namespace std;
/*
This code implements a circular queue in C++ using a dynamic array, supporting the following features:

1- Enqueue: Adds an element to the rear of the queue, with circular indexing to utilize the array efficiently.
2- Dequeue: Removes an element from the front of the queue.
3- Search: Locates an element in the queue and displays its position if found.
4- Access Front/Rear: Retrieves the front or rear element of the queue.
5- Display: Prints all elements of the queue in order.
6- Size Management: Tracks and displays the current size of the queue.
7- Error Handling: Prevents operations on an empty or full queue with informative messages.
*/
class ArrayQueue {
private:
    int front;      // Index of the front element
    int rear;       // Index of the rear element
    int length;     // Current number of elements in the queue
    int* arr;       // Dynamic array to store queue elements
    int maxsize;    // Maximum capacity of the queue

public:
    // Constructor to initialize the queue with a specific size
    ArrayQueue(int size) {
        if (size <= 0) {
            cout << "The Queue by default let size = 100\n";
            maxsize = 100; // Default size if an invalid size is provided
        } else {
            maxsize = size;
        }
        front = 0; // Initialize front index to 0
        arr = new int[maxsize]; // Allocate memory for the queue array
        rear = maxsize - 1; // Initialize rear index for circular behavior
        length = 0; // Initially, the queue is empty
    }

    // Check if the queue is empty
    bool isEmpty() {
        return length == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return length == maxsize;
    }

    // Adds an element to the rear of the queue
    void enqueue(int Element) {
        if (isFull()) {
            cout << "Queue can't Enqueue!...\n";
        } else {
            rear = (rear + 1) % maxsize; // Move rear index circularly
            arr[rear] = Element; // Insert the element at the rear
            length++; // Increase the length of the queue
        }
    }

    // Removes an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue can't Dequeue!...\n";
        } else {
            front = (front + 1) % maxsize; // Move front index circularly
            length--; // Decrease the length of the queue
        }
    }

    // Displays the size of the queue
    void Size() {
        cout << "Size of Queue = " << length << endl;
    }

    // Displays the element at the rear of the queue
    void rearQueue() {
        assert(!isEmpty()); // Ensure the queue is not empty
        cout << "Rear Element = " << arr[rear] << endl;
    }

    // Displays the element at the front of the queue
    void frontQueue() {
        assert(!isEmpty()); // Ensure the queue is not empty
        cout << "Front Element = " << arr[front] << endl;
    }

    // Prints all elements in the queue
    void print() {
        cout << "Queue Elements : [ ";
        if (isEmpty()) {
            cout << "Empty"; // Indicate the queue is empty
        } else {
            // Traverse the queue in a circular manner
            for (int i = front; i != rear; i = (i + 1) % maxsize) {
                cout << arr[i] << " ";
            }
            cout << arr[rear]; // Print the rear element
        }
        cout << "]\n";
    }

    // Searches for an element in the queue and displays its position
    void QueueSearch(int Element) {
        int pos = -1;
        if (!isEmpty()) {
            // Traverse the queue in a circular manner
            for (int i = front; i != rear; i = (i + 1) % maxsize) {
                if (arr[i] == Element) {
                    pos = i; // Element found at index `i`
                    break;
                }
            }
            if (arr[rear] == Element) {
                pos = rear; // Check the rear element
            }
            cout << "The Element if Found on index : " << pos << endl;
        } else {
            cout << "Queue is Empty!...\n"; // Cannot search in an empty queue
        }
    }
};

int main() {
    ArrayQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(50);
    q.print();
    q.QueueSearch(50);
    q.dequeue();
    q.dequeue();
    q.print();
    q.frontQueue();
    q.rearQueue();
    q.Size();
    q.enqueue(80);
    q.enqueue(90);
    q.QueueSearch(90);
}
