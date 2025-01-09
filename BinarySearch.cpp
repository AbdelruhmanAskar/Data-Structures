#include <iostream>
using namespace std;

// Function to perform Binary Search on the array
void BinarySearch(int arr[], int low, int high, int number)
{
    int mid;        // Variable to hold the middle index
    bool check = 0; // Flag to indicate if the number is found

    // Loop until the search range is valid
    while (low <= high)
    {
        mid = (low + high) / 2; // Calculate the middle index

        // If the middle element matches the number
        if (arr[mid] == number)
        {
            check = 1; // Set the flag to true
            break;     // Exit the loop as the number is found
        }

        // If the middle element is less than the number, search the right half
        if (arr[mid] < number)
            low = mid + 1;
        else // If the middle element is greater, search the left half
            high = mid - 1;
    }

    // Output whether the number was found or not
    if (check)
        cout << "Number Was Found on Index -> " << mid << endl;
    else
        cout << "Number Was Not Found\n";
}

int main()
{
    int size;

    // Prompt the user to enter the size of the array
    cout << "Enter Size of Array: \n";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    // Input the elements of the array
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element Number " << i + 1 << endl;
        cin >> arr[i];
    }

    // Note: The array must be sorted for Binary Search to work correctly.
    // Sorting is not implemented in this code. Ensure the input array is sorted.

    int num;

    // Prompt the user to enter the number to search for
    cout << "Enter The Number: \n";
    cin >> num;

    // Call the BinarySearch function to search for the number
    BinarySearch(arr, 0, size - 1, num);

    return 0;
}
