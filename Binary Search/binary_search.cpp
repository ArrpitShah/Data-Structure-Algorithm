#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,3,5,7,9};

    int n = 5;

    int target = 7;

    int left = 0;
    int right = n - 1;

    while(left <= right) {

        int mid = (left + right) / 2;

        if(arr[mid] == target) {

            cout << "Found at index: ";
            cout << mid;

            return 0;
        }

        // move right
        else if(arr[mid] < target) {

            left = mid + 1;
        }

        // move left
        else {

            right = mid - 1;
        }
    }

    cout << "Not Found";

    return 0;
}