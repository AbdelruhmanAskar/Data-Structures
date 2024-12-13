#include <iostream>
#include <cassert>
using namespace std;
class Doublylist
{
private:
	struct Node
	{
		int item;
		Node* prv;
		Node* next;
	};
	Node* first, * last;
	int length;
public:
	Doublylist()
	{
		first = last = nullptr;
		length = 0;
	}
	bool isEmpty()
	{
		return length == 0;
	}
	void InsertFirst(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isEmpty())//length == 0
		{
			first = last = newnode;
			newnode->next = newnode->prv = nullptr;
		}
		else
		{
			newnode->next = first;
			newnode->prv = nullptr;
			first->prv = newnode;
			first = newnode;
		}
		length++;

	}
	void InsertLast(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isEmpty())//length == 0
		{
			first = last = newnode;
			newnode->next = newnode->prv = nullptr;
		}
		else
		{
			newnode->next = nullptr;
			newnode->prv = last;
			last->next = newnode;
			last = newnode;
		}
		length++;
	}
	void InsertAtPos(int pos, int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (pos < 0 || pos > length)
		{
			cout << "Out of Range on InsertAtPos...!\n";
			return;
		}
		if (isEmpty())//length == 0
		{
			first = last = newnode;
			newnode->next = newnode->prv = nullptr;
			length++;
		}
		else if (pos == 0)
			InsertFirst(element);
		else if (pos == length)
			InsertLast(element);
		else
		{
			Node* cur = first;
			for (int i = 1; i < pos; i++)
				cur = cur->next;
			newnode->next = cur->next;
			newnode->prv = cur;
			cur->next = newnode;
			cur->next->prv = newnode;
			length++;
		}
	}
	void RemoveFirst()
	{
		if (isEmpty())
		{
			cout << "Can't Delete Empty List on RemoveFirst...!\n";
			return;
		}
		else if (length == 1)//first = last => 1 Element
		{
			delete first;
			first = last = nullptr;
		}
		else
		{
			Node* cur = first;
			first = first->next;
			first->prv = nullptr;
			delete cur;
		}
		length--;
	}
	void RemoveLast()
	{
		if (isEmpty())
		{
			cout << "Can't Delete Empty List on RemoveLast...!\n";
			return;
		}
		else if (length == 1)//first = last => 1 Element
		{
			delete first;
			first = last = nullptr;
		}
		else
		{
			Node* cur = last;
			last = last->prv;
			last->next = nullptr;
			delete cur;
		}
		length--;
	}
	void Remove(int element)
	{
		if (isEmpty())
		{
			cout << "Can't Delete Empty List on Remove...!\n";
			return;
		}
		else if (first->item == element)//first = last => 1 Element
			RemoveFirst();
		else
		{
			Node* cur = first->next;
			while (cur != nullptr && cur->item != element)
				cur = cur->next;
			if (cur == nullptr)
			{
				cout << "The Element is Not Found Here on Remove...!\n";
				return;
			}
			else if (cur->next == nullptr)
				RemoveLast();
			else
			{
				cur->prv->next = cur->next;
				cur->next->prv = cur->prv;
				delete cur;
				length--;
			}
		}
	}
	void Display()
	{
		Node* cur = first;
		cout << "Doubly Linked List Elements are : [ ";
		while (cur != nullptr)
		{
			cout << cur->item << " ";
			cur = cur->next;
		}
		cout << "]\n";
	}
	void ReversedDisplay()
	{
		Node* cur = last;
		cout << "Doubly Linked List Elements After Reversed are : [ ";
		while (cur != nullptr)
		{
			cout << cur->item << " ";
			cur = cur->prv;
		}
		cout << "]\n";
	}
	~Doublylist()
	{
		Node* cur;
		while (first != nullptr)
		{
			cur = first;
			first = first->next;
			delete cur;
		}
		last = nullptr;
		length = 0;
	}
};
int main()
{
	Doublylist d;
	d.InsertFirst(0);
	d.InsertAtPos(1, 10);
	d.InsertAtPos(2, 20);
	d.InsertLast(30);
	d.InsertLast(40);
	d.InsertLast(50);
	d.Display();
	d.ReversedDisplay();
	d.RemoveFirst();
	d.RemoveLast();
	d.Display();
	d.Remove(20);
	d.Display();
}