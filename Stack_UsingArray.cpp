#include <iostream>
using namespace std;
const int Max_Size = 100; // Maximum size of the stack
/*
This code implements a stack data structure in C++ using a fixed-size array. The stack supports the following operations:

1- Push: Adds an element to the top of the stack (if the stack is not full).
2- Pop: Removes the top element from the stack (if the stack is not empty).
3- Gettop: Displays the current top element of the stack (if the stack is not empty).
4- Print: Displays all elements in the stack from top to bottom.
*/
class Stack
{
private:
    int top;             // Points to the top of the stack
    int items[Max_Size]; // Array to hold stack elements (fixed size)

public:
    // Constructor to initialize the stack
    Stack()
    {
        top = -1; // Indicates the stack is empty at initialization
    }

    // Checks if the stack is full (top has reached Max_Size - 1)
    bool isFull()
    {
        return top == Max_Size - 1;
    }

    // Checks if the stack is empty (top is -1)
    bool isEmpty()
    {
        return top == -1;
    }

    // Pushes an element onto the stack
    void push(int Element)
    {
        if (isFull()) // If stack is full, cannot push
            cout << "Stack is Full on Push\n";
        else
        {
            top++;
            items[top] = Element; 
        }
    }

    // Pops the top element from the stack
    void pop()
    {
        if (isEmpty())
            cout << "Stack is Empty on Pop\n";
        else
        {
            top--;
        }
    }

    // Prints the element at the top of the stack
    void gettop()
    {
        if (isEmpty())
            cout << "There is No Elements\n";
        else
        {
            cout << "Top Element = " << items[top] << endl;
        }
    }

    // Prints all elements in the stack from top to bottom
    void print()
    {
        cout << "[ ";
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.print();
    s.gettop();
}
