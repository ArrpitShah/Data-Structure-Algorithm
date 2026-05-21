#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {

    int arr[] = {1,1,1,2,2,3};

    int n = 6;
    int k = 2;

    unordered_map<int, int> freq;

    // frequency count
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // max heap
    priority_queue<pair<int,int>> pq;

    for(auto x : freq) {

        pq.push({x.second, x.first});
    }

    // top k elements
    for(int i = 0; i < k; i++) {

        cout << pq.top().second << " ";

        pq.pop();
    }

    return 0;
}