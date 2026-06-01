#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,1};

    int n = 4;

    int left = 0;
    int right = n - 1;

    while(left < right) {

        int mid = left + (right - left) / 2;

        if(arr[mid] < arr[mid + 1]) {

            left = mid + 1;
        }
        else {

            right = mid;
        }
    }

    cout << "Peak Index = " << left << endl;
    cout << "Peak Value = " << arr[left];

    return 0;
}