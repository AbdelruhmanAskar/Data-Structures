#include <iostream>
using namespace std;

// Function to perform Insertion Sort in Ascending order (Low To High)
void InsertionSortByLow(int arr[], int s)
{
	int key, j;
	for (int i = 1; i < s; i++) // Loop through each element starting from the second
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) // Shift elements greater than key to the right
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key; // Insert the key at the correct position
	}
}

// Function to perform Insertion Sort in Descending order  (High To Low)
void InsertionSortByHigh(int arr[], int s)
{
	int key, j;
	for (int i = 1; i < s; i++) // Loop through each element starting from the second
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key) // Shift elements smaller than key to the right
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key; // Insert the key at the correct position
	}
}

// Function to print the elements of the array
void print(int arr[], int s)
{
	cout << "Elements : ";
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 60,80,70,10,30,50,20 };
	int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
	print(arr, size); // Print original array
	cout << "=========================\n";
	InsertionSortByLow(arr, size); // Sort array in Ascending order
	print(arr, size); // Print sorted array in Ascending order
	cout << "=========================\n";
	InsertionSortByHigh(arr, size); // Sort array in Descending order
	print(arr, size); // Print sorted array in Descending order
	cout << "=========================\n";
}
