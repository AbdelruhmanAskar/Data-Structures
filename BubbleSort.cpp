#include <iostream>
#include <algorithm> // Optional for built-in swap function
using namespace std;

// Function to perform Bubble Sort in Ascending order (low to high)
void BubbleSortFromLow(int arr[], int size)
{
    bool flag = true; // Flag to check if the array is already sorted
    int counter = 0;  // Counter to track the number of swaps
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // Check if adjacent elements are in the wrong order
            {
                swap(arr[j + 1], arr[j]);
                flag = false;
                counter++;    // Increment swap counter
            }
        }
        if (flag) // If no swaps occurred, the array is already sorted
            break;
    }
    cout << "Array Swaped " << counter << " Times.\n";
}

// Function to perform Bubble Sort in descending order (high to low)
void BubbleSortFromHigh(int arr[], int size)
{
    bool flag = true; // Flag to check if the array is already sorted
    int counter = 0;  // Counter to track the number of swaps
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1]) // Check if adjacent elements are in the wrong order
            {
                swap(arr[j + 1], arr[j]);
                flag = false;
                counter++;    // Increment swap counter
            }
        }
        if (flag) // If no swaps occurred, the array is already sorted
            break;
    }
    cout << "Array Sorted " << counter << " Times.\n";
}

// Custom swap function to exchange the values of two integers
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Function to print the elements of an array
void print(int arr[], int s)
{
    cout << "Elements : [ ";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    // Define and initialize the array to be sorted
    int arr[] = { 60, 50, 10, 70, 90, 40, 0 };
    //int arr[] = { 0,10,20,30,40,50,60 }; // Uncomment this for a pre-sorted array
    int s = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Perform Bubble Sort in Ascending order (low to high)
    cout << "Performing Bubble Sort from Low to High...\n";
    BubbleSortFromLow(arr, s);
    print(arr, s);

    cout << "======================\n";

    // Perform Bubble Sort in Descending order (high to low)
    cout << "Performing Bubble Sort from High to Low...\n";
    BubbleSortFromHigh(arr, s);
    print(arr, s);

    return 0;
}
