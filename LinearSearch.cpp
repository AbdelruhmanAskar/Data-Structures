#include <iostream>
using namespace std;

// Function to perform Linear Search on the array
void LinearSearch(int arr[], int size, int number)
{
    bool check = 0; // Flag to indicate if the number is found
    int index = 0;  // Variable to store the index of the found number

    // Loop through the array to search for the number
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == number) { // If the current element matches the number
            index = i;          // Store the index
            check = 1;          // Set the flag to true
            break;              // Exit the loop as the number is found
        }
    }

    // Check if the number was found and display the appropriate message
    if (check)
        cout << "Number Was Found on Index -> " << index << endl;
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

    int num;

    // Prompt the user to enter the number to search for
    cout << "Enter The Number: \n";
    cin >> num;

    // Call the LinearSearch function to search for the number
    LinearSearch(arr, size, num);

    return 0;
}
