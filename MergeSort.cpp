#include <iostream>
using namespace std;

// Merge Function to merge two subarrays into the main array
// `arrL` represents the left subarray, `arrR` represents the right subarray
void Merge(int* arr, int sizeL, int* arrL, int* arrR, int sizeR)
{
    int left, right, k;
    left = right = k = 0;

    // Compare elements from both subarrays and merge them in sorted order
    while (left < sizeL && right < sizeR)
    {
        if (arrL[left] <= arrR[right])
        {
            arr[k] = arrL[left]; // Copy from left subarray
            left++;
        }
        else
        {
            arr[k] = arrR[right]; // Copy from right subarray
            right++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (left < sizeL)
    {
        arr[k] = arrL[left];
        left++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (right < sizeR)
    {
        arr[k] = arrR[right];
        right++;
        k++;
    }
}

// MergeSort Function to perform merge sort on an array
void MergeSort(int* arr, int size)
{
    // Base condition: If the array has less than 2 elements, it's already sorted
    if (size < 2)
        return;

    int mid = size / 2; // Find the middle point to divide the array
    int* arrL = new int[mid];         // Left subarray
    int* arrR = new int[size - mid];  // Right subarray

    // Copy data into the left and right subarrays
    for (int i = 0; i < mid; i++)
    {
        arrL[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        arrR[i - mid] = arr[i];
    }

    // Recursively sort the left and right subarrays
    MergeSort(arrL, mid);
    MergeSort(arrR, size - mid);

    // Merge the sorted subarrays back into the original array
    Merge(arr, mid, arrL, arrR, size - mid);

    // Free dynamically allocated memory for the subarrays
    delete[] arrL;
    delete[] arrR;
}

// Function to print the elements of an array
void Print(int* arr, int size)
{
    cout << "Elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 70, 50, 30, 90, 10, 20, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the array before sorting
    Print(arr, size);
    cout << "===================\n";

    // Perform merge sort
    MergeSort(arr, size);

    // Print the array after sorting
    Print(arr, size);

    return 0;
}
