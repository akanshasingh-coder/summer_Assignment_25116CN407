//wap to merge two sorted arrays
#include <iostream>
#include <vector>

// Function to merge two sorted arrays
std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    merged.reserve(arr1.size() + arr2.size()); // Pre-allocate memory for efficiency

    size_t i = 0; // Pointer for arr1
    size_t j = 0; // Pointer for arr2

    // Traverse both arrays and pick the smaller element
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Copy remaining elements of arr2, if any
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main() {
    // Example sorted input arrays
    std::vector<int> arr1 = {1, 3, 5, 7};
    std::vector<int> arr2 = {2, 4, 6, 8, 9, 10};

    // Merge arrays
    std::vector<int> result = mergeSortedArrays(arr1, arr2);

    // Print the merged array
    std::cout << "Merged Sorted Array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
