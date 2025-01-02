#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
class BT
{
private:
	struct Node
	{
		int item;
		Node* left;
		Node* right;
	};
public:
	BT()
	{
		left = right = nullptr;
	}
	// Depth-First Search (DFS)
	void Preorder(Node* p) // Root -> Left -> Right
	{
		if (p != nullptr)
		{
			cout << p->item << " "; // Root
			Preorder(p->left); // Left
			Preorder(p->right); // Right
		}
	}
	void Inorder(Node* p) // Left -> Root -> Right
	{
		if (p != nullptr)
		{
			Inorder(p->left); // Left
			cout << p->item << " "; // Root
			Inorder(p->right); // Right
		}
	}
	void Postorder(Node* p) // Left -> Right -> Root
	{
		if (p != nullptr)
		{
			Postorder(p->left); // Left
			Postorder(p->right); // Right
			cout << p->item << " "; // Root
		}
	}
	// Breadth-First Search (BFS)
	void Levelorder(Node* p) // Display Every Level
	{
		if (p == nullptr)
			return;
		queue <Node*>Q;
		Q.push(p);
		while (p != nullptr)
		{
			Node* cur = Q.front();
			cout << cur->item << " ";
			if (cur->left != nullptr)
				Q.push(cur->left);
			if (cur->right != nullptr)
				Q.push(cur->right);
			Q.pop();
		}
	}
	int binarySearch(int arr[], int length, int height, int element)
	{
		while (length <= height)
		{
			int mid = (length + height) / 2;
			if (arr[m] == element)
				return mid;

			if (arr[mid] > element)
				height = mid - length;
			else
				length = mid + 1;
		}
		return -1;
	}
};
int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]); //Size
	int num;
	cout << "Enter an Integer :";
	cin >> num;
	int result = binarySearch(arr, 0, n - 1, num);
	if (result == -1)
		cout << "The Number : (" << num << ") Was Not Found" << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" << result << ")" << endl;

	return 0;
}