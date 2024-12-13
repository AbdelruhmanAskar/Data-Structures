#include <iostream>
#include <cassert>
using namespace std;
class linkedlist
{
private:
	struct Node
	{
		int item;
		Node* next;
	};
	Node* head;
	Node* tail;
	int length;
public:
	linkedlist()
	{
		tail = head = nullptr;
		length = 0;
	}
	bool isEmpty()
	{
		return length == 0;//head == nullptr
	}
	void InsertFirst(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isEmpty()) {
			newnode->next = nullptr;
			head = tail = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
		length++;
	}
	void InsertLast(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isEmpty()) {
			newnode->next = nullptr;
			head = tail = newnode;
		}
		else
		{
			tail->next = newnode;
			newnode->next = nullptr;
			tail = newnode;
		}
		length++;
	}
	void InsertAtPos(int pos,int element)
	{
		if (pos < 0 || pos > length)
			cout << "Out of Range on InsertAtPos...!\n";
		else 
		{
		Node* newnode = new Node;
		newnode->item = element;
		if (pos == 0)
			InsertFirst(element);
		else if (pos == length)
			InsertLast(element);
		else
		{
			Node* cur = head;
			for (int i = 1; i < pos; i++)
				cur = cur->next;
			newnode->next = cur->next;
			cur->next = newnode;
			length++;
		}
		}
	}
	void RemoveFirst()
	{
		if (isEmpty())
			cout << "Can't delete Empty List on RemoveFirst...!\n";
		else if (length == 1)
		{
			delete head;
			head = tail = nullptr;
			length--;
		}
		else
		{
			Node* cur = head;
			head = head->next;
			delete cur;
			length--;
		}
	}
	void RemoveLast()
	{
		if (isEmpty())
			cout << "Can't delete Empty List on RemoveLast...!\n";
		else if (length == 1)
		{
			delete head;
			head = tail = nullptr;
			length--;
		}
		else
		{
			Node* cur = head->next;
			Node* prv = head;
			while (cur != tail)
			{
				prv = cur;
				cur = cur->next;
			}
			delete cur;
			prv->next = nullptr;
			tail = prv;
			length--;
		}
	}
	void Remove(int element)
	{
		if (isEmpty())
		{
			cout << "Can't delete Empty List on Remove...!\n";
			return;
		}
		Node* cur, * prv;
		if (head->item == element)
		{
			/*RemoveFirst();*/
			cur = head;
			head = head->next;
			delete cur;
			length--;
			if (isEmpty())
				tail = nullptr;
		}
		else
		{
			cur = head->next;
			prv = head;
			while (cur != nullptr && cur->item != element)
			{
				prv = cur;
				cur = cur->next;
			}
			if (cur == nullptr)
				cout << "The Element Doesn't Exist In The List on Remove...!\n";
			else
			{
				prv->next = cur->next;
				if (tail == cur)
				{
					tail = prv;
					delete cur;
					length--;
				}
			}
		}
	}
	void reverse()
	{
		Node* prv, * cur, * next;
		prv = nullptr;
		cur = head;
		next = cur->next;
		tail = head;
		while (next != nullptr)//cur != nullptr
		{
			next = cur->next;
			cur->next = prv;
			prv = cur;
			cur = next;
		}
		head = prv;
	}
	void Search(int element)
	{
		Node* cur = head;
		bool check = 0;
		int pos = 0;
		while (cur != nullptr)
		{
			if (cur->item == element)
			{
				check = 1;
				break;
			}
			cur = cur->next;
			pos++;
		}
		if (check)
			cout << "The Element Found in Index : " << pos << endl;
		else
			cout << "The Element Has not Found on Search...!\n";
	}
	void Display()
	{
		cout << "Linked List Elements : [ ";
		Node* cur = head;
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
	linkedlist l;
	l.InsertFirst(10);
	l.InsertAtPos(1, 20);
	l.InsertLast(30);
	l.InsertLast(40);
	l.InsertLast(50);
	l.InsertAtPos(5,60);
	l.InsertFirst(0);
	l.Display();
	l.RemoveFirst();
	l.RemoveLast();
	l.Remove(30);
	l.Display();
	l.InsertFirst(0);
	l.InsertAtPos(1, 10);
	l.Display();
	l.Remove(10);
	l.Remove(20);
	l.Display();
	l.reverse();
	l.Display();
	l.Search(40);
}