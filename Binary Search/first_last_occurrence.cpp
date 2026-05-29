#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,2,2,3,4};

    int n = 6;

    int target = 2;

    int first = -1;
    int last = -1;

    // first occurrence
    int left = 0;
    int right = n - 1;

    while(left <= right) {

        int mid = (left + right) / 2;

        if(arr[mid] == target) {

            first = mid;

            right = mid - 1;
        }

        else if(arr[mid] < target) {

            left = mid + 1;
        }

        else {

            right = mid - 1;
        }
    }

    // last occurrence
    left = 0;
    right = n - 1;

    while(left <= right) {

        int mid = (left + right) / 2;

        if(arr[mid] == target) {

            last = mid;

            left = mid + 1;
        }

        else if(arr[mid] < target) {

            left = mid + 1;
        }

        else {

            right = mid - 1;
        }
    }

    cout << "First = " << first << endl;

    cout << "Last = " << last;

    return 0;
}