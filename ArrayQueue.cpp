#include <iostream>
#include <cassert>
using namespace std;
//const int Max_Size = 100;
class ArrayQueue
{
private:
    int front;
    int rear;
    int length;
    int* arr;
    int maxsize;
public:
    ArrayQueue(int size)
    {
        if (size <= 0)
        {
            cout << "The Queue by default let size = 100\n";
            maxsize = 100;
        }
        else
            maxsize = size;
        front = 0;
        arr = new int[maxsize];
        rear = maxsize - 1;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxsize;
    }
    void enqueue(int Element)
    {
        if (isFull())
            cout << "Queue can't Enqueue!...\n";
        else
        {
            rear = (rear + 1) % maxsize;
            arr[rear] = Element;
            length++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "Queue can't Dequeue!...\n";
        else
        {
            front = (front + 1) % maxsize;
            length--;
        }
    }
    void Size()
    {
        cout << "Size of Queue = " << length << endl;
    }
    void rearQueue()
    {
        assert(!isEmpty());
        cout << "Rear Element = " << arr[rear] << endl;
    }
    void frontQueue()
    {
        assert(!isEmpty());
        cout << "Front Element = " << arr[front] << endl;
    }
    void print()
    {
        cout << "Queue Elements : [ ";
        if (isEmpty())
            cout << "Empty";
        else
        {
            for (int i = front; i != rear; i = (i + 1) % maxsize)//Circular 
            {
                cout << arr[i] << " ";
            }
            cout << arr[rear];
        }   
        cout << "]\n";
    }
    void QueueSearch(int Element)
    {
        int pos = -1;
        if (!isEmpty())
        {
            for (int i = front; i != rear; i = (i + 1) % maxsize)//Circular 
            {
                if (arr[i] == Element)
                {
                    pos = i;
                    break;
                }
            }
            if (arr[rear] == Element)
                pos = rear;
            cout << "The Element if Found on index : " << pos << endl;
        }
        else
            cout << "Queue is Empty!...\n";
    }
};
int main()
{
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
