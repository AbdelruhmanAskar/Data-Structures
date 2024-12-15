#include <iostream>
using namespace std;
/*
This code implements a stack data structure using a linked list in C++.
A stack follows the LIFO (Last In, First Out) principle, where the last element pushed onto the stack is the first one to be popped off.
The LinedStack class provides the following functionality:

1- Push: Adds an element to the top of the stack.
2- Pop: Removes and discards the top element of the stack.
3- Pop and Return: Removes the top element and returns its value.
4- Peek: Displays the top element without removing it.
5- Print: Displays all elements in the stack from top to bottom.
6- isEmpty: Checks whether the stack is empty.
*/
class LinedStack
{
private:
    struct node
    {
        int item;      // Item stored in the node (stack element)
        node* next;    // Pointer to the next node in the stack
    };

    node* top, * cur; // top points to the top of the stack, cur is used for traversing

public:
    // Constructor: Initializes the stack with top as nullptr (empty stack)
    LinedStack()
    {
        top = nullptr;  // Empty stack, no elements
    }

    // Checks if the stack is empty (if top is nullptr)
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Pushes a new element onto the stack
    void push(int Element)
    {
        node* newnode = new node;
        newnode->item = Element;

        if (isEmpty())
        {
            newnode->next = nullptr;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    // Pops the top element off the stack (removes it)
    void pop()
    {
        if (isEmpty())
            cout << "LinkedStack is Empty on pop\n";
        else
        {
            node* temp = top;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
        }
    }

    // Pops the top element off the stack and returns its value
    int popandreturn()
    {
        if (isEmpty())
            cout << "LinkedStack is Empty on pop\n";
        else
        {
            node* temp = top;
            int value = top->item;
            top = top->next;
            temp = temp->next = nullptr;
            delete temp;
            return value;
        }
    }

    // Displays the top element of the stack without removing it
    void peek()
    {
        if (isEmpty())
            cout << "Stack is Empty on Peek\n";
        else
            cout << "Top item of Stack = " << top->item << endl;
    }

    // Prints all the elements in the stack from top to bottom
    void print()
    {
        cur = top;
        cout << "Stacks items are : ";
        cout << "[ ";
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

int main()
{
    LinedStack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    s.peek();
    s.pop();
    s.peek();
    s.push(50);
    s.push(60);
    s.print();
    cout << s.popandreturn() << " Was Deleted From Stack\n";
    cout << s.popandreturn() << " Was Deleted From Stack\n";
    s.print();
}
