#include <iostream>
#include <cassert>
using namespace std;
class LinkedQueue
{
private:
    struct Node {
        int item;
        Node* next;
    };
    Node* front, * rear;
    int length;
public:
    LinkedQueue()//:front(nullptr),rear(nullptr),length(0)
    {
        front = rear = nullptr;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void Enqueue(int element)
    {
        if (isEmpty())
        {
            front = new Node;
            front->item = element;
            front->next = nullptr;
            rear = front;
        }
        else
        {
            Node* newnode = new Node;
            newnode->item = element;
            newnode->next = nullptr;
            rear->next = newnode;
            rear = newnode;
        }
        length++;
    }
    //Another Method
    /*void Enqueue(int element)
    {
        Node* newnode = new Node;
        newnode->item = element;
        newnode->next = nullptr;
        if (isEmpty())
            rear = front = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        length++;
    }*/
    void Dequeue()
    {
        if (isEmpty())
            cout << "Can't Dequeue Empty Queue.....!\n";
        else
        {
            Node* temp = front;
            front = front->next;
            temp = temp->next = nullptr;
            delete temp;// free(temp)
        }
        length--;
    }
    void getfront()
    {
        assert(!isEmpty());
        cout << "Front = " << front->item << endl;
    }
    void getrear()
    {
        assert(!isEmpty());
        cout << "Rear = " << rear->item << endl;
    }
    void getsize()
    {
        cout << "Size of Queue = " << length << endl;
    }
    void display()
    {
        Node* cur = front;
        cout << "Elements of Queue : [ ";
        while (cur != nullptr)
        {
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
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