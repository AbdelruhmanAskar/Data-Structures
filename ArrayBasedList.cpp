#include <iostream>
#include <cassert>
using namespace std;
/*
This code implements a dynamic array-based list (arraylist) in C++ with features for inserting,
removing, searching, and managing elements. The class supports:

1- Insertion at specific positions or at the end.
2- Deletion of elements by value or position.
3- Search to find the index of a specific element.
4- Replacement of an element at a given position.
5- Prevention of duplicates using the notDuplicated method.
6- Displaying the list contents, its current size, and maximum capacity.
*/
class arraylist {
private:
    int* arr;      // Pointer to dynamically allocated array
    int maxsize;   // Maximum capacity of the array
    int length;    // Current number of elements in the array

public:
    // Constructor to initialize array with a specified size
    arraylist(int s) {
        if (s < 0)
            maxsize = 10; // Default size if input is invalid
        else
            maxsize = s;
        length = 0;
        arr = new int[maxsize];
    }

    // Check if the array is empty
    bool isEmpty() {
        return length == 0;
    }

    // Check if the array is full
    bool isFull() {
        return length == maxsize;
    }

    // Display the current size of the array (number of elements)
    void getSize() {
        cout << "Length of List = " << length << endl;
    }

    // Display the maximum capacity of the array
    void getMaxSize() {
        cout << "Max Size of List = " << maxsize << endl;
    }

    // Insert an element at a specified position
    void insertAtPos(int pos, int element) {
        if (isFull()) {
            cout << "List is Full on insertAtPos...!\n";
        } else if (pos < 0 || pos > length) {
            cout << "Out of Range on insertAtPos...!\n";
        } else {
            for (int i = length; i > pos; i--) {
                arr[i] = arr[i - 1]; // Shift elements to make space
            }
            arr[pos] = element; // Insert the new element
            length++;           // Increment the size
        }
    }

    // Insert an element at the end of the array
    void insertEnd(int element) {
        if (isFull()) {
            cout << "List is Full on insertAtEnd...!\n";
        } else {
            arr[length++] = element; // Add element and increment size
        }
    }

    // Search for an element and return its index
    int Search(int element) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element)
                return i; // Element found at index `i`
        }
        return -1; // Element not found
    }

    // Remove an element by value
    void Remove(int element) {
        assert(!isEmpty()); // Ensure the array is not empty
        int loc = Search(element);
        if (loc == -1) {
            cout << "The Element to be Deleted is not in the List on Remove...!\n";
        } else {
            RemoveAtPs(loc); // Remove element at the found index
        }
    }

    // Remove an element at a specified position
    void RemoveAtPs(int pos) {
        if (isEmpty()) {
            cout << "List is Empty on RemoveAtPs...!\n";
        } else if (pos < 0 || pos >= length) {
            cout << "Out of Range on RemoveAtPs...!\n";
        } else {
            for (int i = pos; i < length - 1; i++) {
                arr[i] = arr[i + 1]; // Shift elements to fill the gap
            }
            length--; // Decrement the size
        }
    }

    // Display all elements in the array
    void Display() {
        cout << "Elements of This List : [ ";
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " "; // Print each element
        }
        cout << "]\n";
    }

    // Add an element only if it doesn't already exist (notDuplicated)
    void notDuplicated(int element) {
        if (isFull()) {
            cout << "List is Full on notDuplicated...!\n";
        } else {
            int flag = Search(element);
            if (flag == -1) { // Element not found
                insertEnd(element); // Add the element
            } else {
                cout << "No duplicates are allowed on notDuplicated...!\n";
            }
        }
    }

    // Replace the element at a specific position
    void replaceAt(int loc, int element) {
        if (loc < 0 || loc >= length) {
            cout << "Out of Range on replaceAt...!\n";
        } else {
            arr[loc] = element; // Replace the value at the specified location
        }
    }
};

int main() {
    arraylist a(10);
    a.insertAtPos(0, 10);
    a.insertAtPos(1, 20);
    a.insertAtPos(2, 30);
    a.insertAtPos(3, 40);
    a.insertAtPos(4, 50);
    a.Remove(30);
    a.RemoveAtPs(0);
    a.Display();
    a.getMaxSize();
    a.getSize();
    a.notDuplicated(10);
    a.insertEnd(60);
    a.Display();
    a.Search(60);
    a.replaceAt(4, 70);
    a.Display();
    a.getSize();
}
