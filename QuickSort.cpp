#include <iostream>
using namespace std;

// Function to partition the array into two parts based on the pivot element
int Partition(int arr[], int begin, int end)
{
    int pivot = arr[begin]; // Choose the first element as the pivot
    int i = begin;          // Initialize the left pointer
    int j = end;            // Initialize the right pointer

    while (i < j) // Loop until the two pointers meet
    {
        // Move the left pointer to the right until an element greater than the pivot is found
        do
        {
            i++;
        } while (arr[i] <= pivot);

        // Move the right pointer to the left until an element less than or equal to the pivot is found
        do
        {
            j--;
        } while (arr[j] > pivot);

        // Swap the elements if the pointers have not crossed
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Place the pivot element in its correct position
    swap(arr[begin], arr[j]);
    return j; // Return the position of the pivot
}

// Recursive function to perform QuickSort on the array
void QuickSort(int arr[], int Begin, int End)
{
    if (Begin < End) // Base case: If the segment has more than one element
    {
        // Partition the array and get the pivot index
        int pivot = Partition(arr, Begin, End);

        // Recursively sort the left subarray (elements smaller than the pivot)
        QuickSort(arr, Begin, pivot);

        // Recursively sort the right subarray (elements greater than the pivot)
        QuickSort(arr, pivot + 1, End);
    }
}

// Utility function to print the elements of the array
void print(int arr[], int s)
{
    cout << "Elements: ";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 5, 7, 3, 1, 10, 0, -2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the array before sorting
    print(arr, size);

    // Perform QuickSort on the entire array
    QuickSort(arr, 0, size);

    // Print the array after sorting
    print(arr, size);

    return 0;
}
