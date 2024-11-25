#include <iostream>
using namespace std;
class LinedStack
{
private:
    struct node
    {
        int item;
        node* next;
    };
    node* top, * cur;
public:
    LinedStack()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
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
    void peek()
    {
        if (isEmpty())
            cout << "Stack is Empty on Peek\n";
        else
            cout << "Top item of Stack = " << top->item << endl;
    }
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