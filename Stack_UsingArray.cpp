#include <iostream>
using namespace std;
const int Max_Size = 100;
class Stack
{
private:
    int top;
    int items[Max_Size];// -> Fixed Size
public:
    Stack()
    {
        top = -1;
    }
    bool isFull()
    {
        return top == Max_Size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    void push(int Element)
    {
        if (isFull())
            cout << "Stack is Full on Push\n";
        else
        {
            top++;
            items[top] = Element;
        }
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack is Empty on Pop\n";
        else
        {
            top--;
        }
    }
    void gettop() 
    {
        if (isEmpty())
            cout << "There is No Elements\n";
        else
        {
            cout << "Top Element = " << items[top] << endl;
        }
    }
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