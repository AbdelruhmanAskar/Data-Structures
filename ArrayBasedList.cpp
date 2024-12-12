#include <iostream>
#include <cassert>
using namespace std;
class arraylist
{
private:
	int* arr;
	int maxsize;
	int length;
public:
	arraylist(int s)
	{
		if (s < 0)
			maxsize = 10;//default
		else
			maxsize = s;
		length = 0;
		arr = new int[maxsize];
	}
	bool isEmpty()
	{
		return length == 0;
	}
	bool isFull()
	{
		return length == maxsize;
	}
	void getSize()
	{
		cout << "Length of List = " << length << endl;
	}
	void getMaxSize()
	{
		cout << "Max Size of List = " << maxsize << endl;
	}
	void insertAtPos(int pos, int element)
	{
		if (isFull())
			cout << "List is Full on insertAtPos...!\n";
		else if (pos < 0 || pos > length)
			cout << "Out of Range on insertAtPos...!\n";
		else {
			for (int i = length; i > pos; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[pos] = element;
			length++;
		}
	}
	void insertEnd(int element)
	{
		if (isFull())
			cout << "List is Full on insertAtEnd...!\n";
		else {
			arr[length++] = element;
		}
	}
	int Search(int element)
	{
		for (int i = 0; i < length; i++)
		{
			if (arr[i] == element)
				return i;
		}
		return -1;
	}
	void Remove(int element) 
	{
		assert(!isEmpty());
		int loc = Search(element);
		if (loc == -1) {
			cout << "The Element to be Deleted is not in the List on Remove...!\n";
		}
		else
			RemoveAtPs(loc);
	}
	void RemoveAtPs(int pos)
	{
		if (isEmpty())
			cout << "List is Empty on RemoveAtPs...!\n";
		else if (pos < 0 || pos > length)
			cout << "Out of Range on RemoveAtPs...!\n";
		else {
			for (int i = pos; i < length; i++)
			{
				arr[i] = arr[i + 1];
			}
			length--;
		}
	}
	void Display()
	{
		cout << "Elements of This List : [ ";
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]\n";
	}
	void notDuplicated(int element)
	{
		if(isFull())
			cout << "List is Full on notDuplicated...!\n";
		else
		{
			int flag = Search(element);
			if (flag == -1)
				insertEnd(element);
			else
				cout << "No duplicates are allowed on notDuplicated...!\n";
		}
	}
	void replaceAt(int loc, int element)
	{
		if (loc < 0 || loc >= length)
			cout << "Out of Range on replaceAt...!\n";
		else
			arr[loc] = element;
	}
};
int main()
{
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
	a.replaceAt(4,70);
	a.Display();
	a.getSize();
}