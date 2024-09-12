#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int Partition (std::vector<int> &arr,int low, int high){
// choosing pivot
int pivot =arr[high];

int i =low - 1;

for(int j = low; j <= high - 1; j++){
    if(arr[j] < pivot){
        i++;
        std::swap(arr[i],arr[j]);
    }
}

std::swap(arr[i+1],arr[high]);
return i + 1;
}

// quicksort function
void QuickSort(std::vector<int> &arr, int low, int high, bool decending = false){
    if(low < high){
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }

    if(decending){
        reverse(arr.begin(),arr.end());
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

    QuickSort(list, 0, num - 1, true); // function call.

    std::cout << "Sorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
