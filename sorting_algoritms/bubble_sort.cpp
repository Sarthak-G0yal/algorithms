#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::swap

// Function to perform bubble sort on a vector of integers
// If 'descending' is true, the vector is sorted in descending order
void BubbleSort(std::vector<int> &arr, bool descending = false) {
    int arr_size = arr.size();
    // Loop for bubble sort
    for (int i = 0; i < arr_size - 1; ++i) {
        for (int j = 0; j < arr_size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    if (descending) {
        reverse(arr.begin(), arr.end());
    }
}

int main() {
    int num;
    std::cout << "Enter the total number of elements: ";
    std::cin >> num; // ask for number of elements in vector.

    std::vector<int> list(num);
    std::cout << "Enter elements: ";
    for (int i = 0; i < num; ++i) {
        std::cin >> list[i]; // enter the elements to be sorted.
    }

    std::cout << "Unsorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    BubbleSort(list); // function call.

    std::cout << "Sorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
