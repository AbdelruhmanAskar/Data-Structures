#include <iostream>
using namespace std;

// Function to maintain the Max-Heap property
void Heapify(int arr[], int s, int i) // max-heap
{
    int l = 2 * i + 1; // Index of the left child
    int r = 2 * i + 2; // Index of the right child
    int max = i;       // Initialize the largest element as the root

    // Check if the left child exists and is greater than the root
    if (l < s && arr[l] > arr[max])
        max = l;

    // Check if the right child exists and is greater than the largest so far
    if (r < s && arr[r] > arr[max])
        max = r;

    // If the largest is not the root, swap and recursively heapify the affected subtree
    if (max != i)
    {
        swap(arr[i], arr[max]);
        Heapify(arr, s, max);
    }
}

// Function to build a Max-Heap from the input array
void Bulidheap(int arr[], int s)
{
    // Start from the last non-leaf node and heapify each node
    for (int i = s / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, s, i);
    }
}

// Function to perform Heap Sort
void Heapsort(int arr[], int s)
{
    // Step 1: Build a Max-Heap
    Bulidheap(arr, s);

    // Step 2: Extract elements one by one from the heap
    for (int i = s - 1; i >= 0; i--)
    {
        // Move the current root (maximum element) to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap to restore the Max-Heap property
        Heapify(arr, i, 0);
    }
}

// Function to print the array elements
void print(int arr[], int size)
{
    cout << "Elements : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[] = { 90, 100, 40, 60, 0, 10, 80 };
    int size = sizeof(array) / sizeof(array[0]);

    // Print the array before sorting
    print(array, size);

    // Perform Heap Sort
    Heapsort(array, size);

    // Print the array after sorting
    print(array, size);

    return 0;
}
