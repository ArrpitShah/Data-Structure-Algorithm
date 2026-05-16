// In this Section, we will learn how to count the frequency of elements in an array using hashing. We will use an unordered_map to store the frequency of each element.
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int arr[] = {1,2,2,3,1,2,4};

    int n = 7;

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(auto x : freq) {
        cout << x.first << " -> ";
        cout << x.second << endl;
    }

    return 0;
}
// Explanation:
// We have an array of integers and we want to count the frequency of each element in the array. We use an unordered_map to store the frequency of each element. We iterate through the array and for each element, we increment its frequency in the unordered_map. Finally, we iterate through the unordered_map and print the frequency of each element.
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(n) in the worst case when all elements are distinct.
