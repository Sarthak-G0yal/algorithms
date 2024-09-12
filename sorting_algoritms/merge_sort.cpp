#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// function to merge lists.
void Merge(std::vector <int> &arr, int left, int mid, int right){

    int left_vector_size = mid - left + 1;
    int right_vector_size = right - mid;

    // temperory vectors.
    std::vector <int> vec_left(left_vector_size);
    std::vector <int> vec_right(right_vector_size);

    // coping the elements into the split list.
    for(int i = 0; i < left_vector_size; i++)vec_left[i] = arr[left + i];
    for(int i = 0; i < right_vector_size; i++)vec_right[i] = arr[mid + 1 + i];

    int left_index = 0, right_index = 0;
    int after_index = left;

    // merge the two list back in one.
    while(left_index < left_vector_size && right_index < right_vector_size){
        if(vec_left[left_index] <= vec_right[right_index]){
            arr[after_index] = vec_left[left_index];
            left_index++;
        }else{
            arr[after_index] = vec_right[right_index];
            right_index++;
        }
        after_index++;
    }

    // coping the remaining element of left vec into main array
    while(left_index < left_vector_size){
        arr[after_index] = vec_left[left_index];
        left_index++;
        after_index++;
    }

    // coping the remaining element of right vec into main array
    while(right_index < right_vector_size){
        arr[after_index] = vec_right[right_index];
        right_index++;
        right_index++;
    }
}

// merge sort function
void MergeSort(std::vector<int>& arr, int left, int right, bool decending = false)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);

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

    MergeSort(list, 0, num - 1); // function call.

    std::cout << "Sorted List: ";
    for (const auto &x : list) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}
