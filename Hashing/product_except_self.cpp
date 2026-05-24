#include <iostream>
using namespace std;

int main() {

    int arr[] = {1,2,3,4};

    int n = 4;

    int left[100];
    int right[100];
    int answer[100];

    // left product
    left[0] = 1;

    for(int i = 1; i < n; i++) {

        left[i] = left[i-1] * arr[i-1];
    }

    // right product
    right[n-1] = 1;

    for(int i = n-2; i >= 0; i--) {

        right[i] = right[i+1] * arr[i+1];
    }

    // final answer
    for(int i = 0; i < n; i++) {

        answer[i] = left[i] * right[i];
    }

    // print
    for(int i = 0; i < n; i++) {

        cout << answer[i] << " ";
    }

    return 0;
}