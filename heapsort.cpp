#include <iostream>
#include <vector>

// Function to heapify a subtree rooted at index i
void heapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]); // Swap root with largest

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform HeapSort
void heapSort(std::vector<int> &arr)
{
    int n = arr.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: \n";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    heapSort(arr);

    std::cout << "Sorted array: \n";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << "\n";

    return 0;
}
