#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::swap

void SelectionSort(std::vector<int> &arr, bool decending = false) {
    int vec_size = arr.size();
    for (int i = 0; i < vec_size - 1; i++) {
        int min_index = i; // Initialize min_index to the current index
        for (int j = i + 1; j < vec_size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[min_index], arr[i]);
    }

    if(decending){
        std::reverse(arr.begin(),arr.end());
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

    SelectionSort(list,true); // function call.

    std::cout << "Sorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
