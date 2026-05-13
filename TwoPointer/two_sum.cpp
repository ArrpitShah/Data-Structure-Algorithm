#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n, target;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while(left < right) {

        int sum = arr[left] + arr[right];

        if(sum == target) {
            cout << arr[left] << " " << arr[right];
            return 0;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "No Pair Found";

    return 0;
}