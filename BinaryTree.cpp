#include <iostream>
#include <cassert>
#include <queue>
using namespace std;
/*
This code implements a Binary Tree (BT) in C++ with various operations for tree traversal and searching. The tree supports the following operations:

1- Preorder: Performs a Depth-First Search (DFS) Preorder traversal (Root -> Left -> Right).
2- Inorder: Performs a Depth-First Search (DFS) Inorder traversal (Left -> Root -> Right).
3- Postorder: Performs a Depth-First Search (DFS) Postorder traversal (Left -> Right -> Root).
4- Levelorder: Performs a Breadth-First Search (BFS) traversal, visiting nodes level by level.
5- binarySearch: Searches for an element in a sorted array using the Binary Search algorithm.
*/

class BT
{
private:
	struct Node
	{
		int item;       // Value of the current node
		Node* left;     // Pointer to the left child
		Node* right;    // Pointer to the right child
	};
public:
	BT(){}

	// Depth-First Search (DFS) Preorder Traversal: Root -> Left -> Right
	void Preorder(Node* p)
	{
		if (p != nullptr)
		{
			cout << p->item << " ";    // Print the root node
			Preorder(p->left);         // Recursively traverse the left subtree
			Preorder(p->right);        // Recursively traverse the right subtree
		}
	}

	// Depth-First Search (DFS) Inorder Traversal: Left -> Root -> Right
	void Inorder(Node* p)
	{
		if (p != nullptr)
		{
			Inorder(p->left);          // Recursively traverse the left subtree
			cout << p->item << " ";    // Print the root node
			Inorder(p->right);         // Recursively traverse the right subtree
		}
	}

	// Depth-First Search (DFS) Postorder Traversal: Left -> Right -> Root
	void Postorder(Node* p)
	{
		if (p != nullptr)
		{
			Postorder(p->left);        // Recursively traverse the left subtree
			Postorder(p->right);       // Recursively traverse the right subtree
			cout << p->item << " ";    // Print the root node
		}
	}

	// Breadth-First Search (BFS) Levelorder Traversal: Visit nodes level by level
	void Levelorder(Node* p)
	{
		if (p == nullptr)
			return;

		queue<Node*> Q;                // Queue for BFS traversal
		Q.push(p);                     // Start with the root node

		while (!Q.empty())
		{
			Node* cur = Q.front();     // Get the current node
			cout << cur->item << " ";  // Print the node value

			if (cur->left != nullptr)  // Add left child to the queue
				Q.push(cur->left);

			if (cur->right != nullptr) // Add right child to the queue
				Q.push(cur->right);

			Q.pop();                   // Remove the current node from the queue
		}
	}

	// Binary Search: Search for an element in a sorted array
	int binarySearch(int arr[], int length, int height, int element)
	{
		while (length <= height)
		{
			int mid = (length + height) / 2; // Calculate the middle index

			if (arr[mid] == element)        // Element found
				return mid;

			if (arr[mid] > element)         // Search in the left half
				height = mid - 1;
			else                            // Search in the right half
				length = mid + 1;
		}
		return -1;                          // Element not found
	}
};

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };       // Sorted array for binary search
	int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

	int num;
	cout << "Enter an Integer: ";
	cin >> num;                            // Input the element to search

	BT Treee;                                 // Create an object of the BT class
	int result = Treee.binarySearch(arr, 0, n - 1, num); // Call binary search

	if (result == -1)
		cout << "The Number: (" << num << ") Was Not Found" << endl;
	else
		cout << "The Number: (" << arr[result] << ") Was Found At Index: (" << result << ")" << endl;

	return 0;
}
