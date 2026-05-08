// In this Section we will implement the Quick Sort algorithm in C++. Quick Sort is a popular sorting algorithm that follows the divide-and-conquer approach. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. The time complexity of Quick Sort is O(n log n) on average and O(n^2) in the worst case, which occurs when the smallest or largest element is always chosen as the pivot.
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {

        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if(low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}