//What is Two Pointer Technique?    
//Two pointer technique is a common algorithmic approach used to solve problems that involve searching, sorting, or manipulating arrays or linked lists. It involves using two pointers (or indices) to traverse the data structure simultaneously, often from opposite ends, to achieve a specific goal efficiently.
// there are  two pointer  in it first pointer is in last and second pointer is in first and we will move both pointer towards each other until they meet or cross each other. This technique is often used to solve problems such as finding pairs in an array that sum up to a specific target, reversing a linked list, or partitioning an array around a pivot element. By using two pointers, we can often reduce the time complexity of our algorithms from O(n^2) to O(n), making them more efficient for larger datasets.
// Example: Finding pairs in an array that sum up to a specific target
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 7;
    int left = 0; // First pointer
    int right = arr.size() - 1; // Second pointer

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            cout << "Pair found: " << arr[left] << " + " << arr[right] << " = " << target << endl;
            left++; // Move the left pointer to the right
            right--; // Move the right pointer to the left
        } else if (sum < target) {
            left++; // Move the left pointer to the right to increase the sum
        } else {
            right--; // Move the right pointer to the left to decrease the sum
        }
    }

    return 0;
}