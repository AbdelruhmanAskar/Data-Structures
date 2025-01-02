#include <iostream>
//#include <algorithm> // Optional if using the built-in swap function
using namespace std;

// Function to perform Selection Sort in ascending order by finding the (minimum) element
void SelectionSortByMin(int arr[], int size)
{
    int minidx; // Index of the smallest element
    for (int i = 0; i < size - 1; i++) // Outer loop to track passes
    {
        minidx = i; // Assume the current element is the smallest
        for (int j = i + 1; j < size; j++) // Inner loop to find the smallest element in the unsorted part
        {
            if (arr[j] < arr[minidx]) // Update minidx if a smaller element is found
                minidx = j;
        }
        // Swap the smallest element with the first element of the unsorted part
        swap(arr[minidx], arr[i]);
    }
}

// Function to perform Selection Sort in descending order by finding the (maximum) element
void SelectionSortByMax(int arr[], int size)
{
    int Maxidx; // Index of the largest element
    for (int i = 0; i < size - 1; i++) // Outer loop to track passes
    {
        Maxidx = i; // Assume the current element is the largest
        for (int j = i + 1; j < size; j++) // Inner loop to find the largest element in the unsorted part
        {
            if (arr[j] > arr[Maxidx]) // Update Maxidx if a larger element is found
                Maxidx = j;
        }
        // Swap the largest element with the first element of the unsorted part
        swap(arr[Maxidx], arr[i]);
    }
}

// Custom swap function to exchange the values of two integers
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Function to print the elements of an array
void print(int arr[], int size)
{
    cout << "Elements : [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; //
    }
    cout << "]\n";
}

int main()
{
    // Define and initialize the array
    int arr[] = { 60, 70, 30, 20, 0, 10, 40, 50, 80 };
    int s = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Print the original array
    print(arr, s);

    // Perform Selection Sort by finding the minimum element
    cout << "Performing Selection Sort By Min...\n";
    SelectionSortByMin(arr, s);
    print(arr, s);

    // Perform Selection Sort by finding the maximum element
    cout << "Performing Selection Sort By Max...\n";
    SelectionSortByMax(arr, s);
    print(arr, s);

    return 0;
}
