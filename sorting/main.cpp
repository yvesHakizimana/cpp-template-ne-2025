#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void bubble_sort(vector<T> & arr){
    int n = arr.size();
    int i, j;
    for(i = 0; i < n - 1 ; ++i){
        bool swapped = false;
        for(j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break; // for optimization purposes in the outer loop , when we don't have a swap in place
    }
}


template <typename T>
void selection_sort(vector<T>& arr){
    int n = arr.size();
    int i, j, minIndex;
    for( i = 0; i < n - 1; ++i){
        minIndex = i;
        for(j = i + 1; j < n; ++j){
            if(arr[j] < arr[minIndex]) // we must compare each element with the minimum element
                minIndex = j;
        }
        // for optimization when there is no other minimum element no need to swap because the minimum is still the minimum
        if(minIndex != i)
            swap(arr[i], arr[minIndex]); 
    }
}

template <typename T>
void insertion_sort(vector<T>& arr) {
    int n = arr.size();
    int i, j, key;
    // we will be starting from one due to we are going to compare the element to all other elements which are before it.
    for (i = 1; i < n; ++i){
        key = arr[i];
        j = i - 1; // j will be holding the elements before i 

        while(j >= 0 && arr[j] > key){
            // shift the tall number to one position right.

            arr[ j + 1] = arr[j];
            j--;
        }
        // after shifting all the elements the key will be aligned to j + 1 position.
        arr[j+1] = key;
    }
}


template <typename T>
void merge(vector<T>& arr, int left, int mid, int right){
    vector<T> temp(right - left + 1); // what does this means.
    int i = left, j = mid + 1, k = 0;

    // merge the sorted subarrays.
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i];
        else 
            temp[k++] = arr[j];
    }

    // we can remain some elements in both subarrays then use them to fill up the arrays.
    while(i <=  mid) temp[k++] = arr[i++];

    while(i <= right) temp[k++] = arr[j++];

    // copy operation back to the array
    for (int p = 0; p < k; ++p){
        arr[left + p] = temp[p];
    }
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left ) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename T>
int partition(vector<T>& arr, int low, int high) {
    T pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;    // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]); // Move smaller elements to left
        }
    }
    std::swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1; // Return pivot index
}

template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition array
        quickSort(arr, low, pi - 1);        // Sort left subarray
        quickSort(arr, pi + 1, high);       // Sort right subarray
    }
}


int main(){
    vector<int> arr = {5, 2, 8, 1, 9};
    cout << "Original array: ";
    for(int x: arr) cout << x << " ";
    cout << "\n";
    
    vector<int> arr1 = arr;
    bubble_sort(arr1);
    cout << "Bubble Sort: ";
    for(int x : arr1) cout << x << " ";
    cout << "\n";


    vector<int> arr2 = arr;
    selection_sort(arr2);
    cout << "Selection Sort: ";
    for(int x: arr2) cout << x << " ";
    cout << "\n";

    vector<int> arr3 = arr;
    insertion_sort(arr3);
    cout << "Insertion Sort: ";
    for(int x: arr3) cout << x << " ";
    cout << "\n";

    // // Test Merge Sort
    // std::vector<int> arr4 = arr;
    // mergeSort(arr4, 0, arr4.size() - 1);
    // std::cout << "Merge Sort: ";
    // for (int x : arr4) std::cout << x << " ";
    // std::cout << "\n";

    // // Test Quick Sort
    // std::vector<int> arr5 = arr;
    // quickSort(arr5, 0, arr5.size() - 1);
    // std::cout << "Quick Sort: ";
    // for (int x : arr5) std::cout << x << " ";
    // std::cout << "\n";

     
    return 0;

}