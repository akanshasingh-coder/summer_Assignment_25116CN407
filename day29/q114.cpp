//wap to create menu-driven array operations system 
#include <iostream>
using namespace std;

// Maximum capacity of the array
const int MAX_SIZE = 100;

// Function declarations
void display(const int arr[], int size);
void insertElement(int arr[], int& size);
void deleteElement(int arr[], int& size);
void searchElement(const int arr[], int size);
void sortArray(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    // Initial input for array elements
    cout << "Enter the initial number of elements (Max " << MAX_SIZE << "): ";
    cin >> size;
    
    if (size > MAX_SIZE) {
        cout << "Size exceeds maximum limit. Setting size to " << MAX_SIZE << ".\n";
        size = MAX_SIZE;
    }

    if (size > 0) {
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Infinite loop for menu selection until explicit exit
    do {
        cout << "\n===============================" << endl;
        cout << "  ARRAY OPERATIONS MENU SYSTEM " << endl;
        cout << "===============================" << endl;
        cout << "1. Traverse / Display Array" << endl;
        cout << "2. Insert Element" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Search Element (Linear)" << endl;
        cout << "5. Sort Array (Bubble Sort)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(arr, size);
                break;
            case 2:
                insertElement(arr, size);
                break;
            case 3:
                deleteElement(arr, size);
                break;
            case 4:
                searchElement(arr, size);
                break;
            case 5:
                sortArray(arr, size);
                break;
            case 6:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

// 1. Traverse and display array elements
void display(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Current Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nTotal Elements: " << size << endl;
}

// 2. Insert an element at a specific index
void insertElement(int arr[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Error: Array Overflow! Cannot insert more elements." << endl;
        return;
    }

    int element, position;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter index position (0 to " << size << "): ";
    cin >> position;

    // Validate boundaries
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right to create space
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element and update structural size variable
    arr[position] = element;
    size++;
    cout << "Element inserted successfully." << endl;
}

// 3. Delete an element from a specific index
void deleteElement(int arr[], int& size) {
    if (size == 0) {
        cout << "Error: Array Underflow! No items to delete." << endl;
        return;
    }

    int position;
    cout << "Enter index position to delete (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift subsequent elements left to overwrite target
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "Element deleted successfully." << endl;
}

// 4. Perform a Linear Search for a value
void searchElement(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int target;
    cout << "Enter element to search for: ";
    cin >> target;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Element " << target << " found at index " << i << "." << endl;
            return;
        }
    }
    cout << "Element " << target << " not found in the array." << endl;
}

// 5. Sort the array using Bubble Sort
void sortArray(int arr[], int size) {
    if (size <= 1) {
        cout << "Array is already sorted." << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap values
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // Break early if array becomes sorted completely
        if (!swapped) break;
    }
    cout << "Array sorted successfully in ascending order." << endl;
}
