#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = n - 1;

    bool isPalindrome = true;

    while(left < right) {

        if(arr[left] != arr[right]) {
            isPalindrome = false;
            break;
        }

        left++;
        right--;
    }

    if(isPalindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}