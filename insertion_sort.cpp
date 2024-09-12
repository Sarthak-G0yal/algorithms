#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::swap

// insertion sort function
void InsertionSort(std::vector<int> &arr, int size, bool descending = false){
    for (int i = 1 ; i < size ; i++){
        int index = i; // declarating other variable
        while( index > 0 && arr[index] < arr[index-1]){
            std::swap(arr[index],arr[index-1]); //swapping till the previous  element is bigger than current element.
            index--;
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

    InsertionSort(list,num); // function call.

    std::cout << "Sorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
