#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int arr[] = {1,1,1};

    int n = 3;
    int k = 2;

    unordered_map<int, int> mp;

    mp[0] = 1;

    int currentSum = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {

        currentSum += arr[i];

        if(mp.find(currentSum - k) != mp.end()) {
            count += mp[currentSum - k];
        }

        mp[currentSum]++;
    }

    cout << count;

    return 0;
}