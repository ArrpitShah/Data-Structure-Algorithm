#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int>& stalls,
              int cows,
              int distance) {

    int count = 1;
    int lastPosition = stalls[0];

    for(int i = 1; i < stalls.size(); i++) {

        if(stalls[i] - lastPosition >= distance) {

            count++;
            lastPosition = stalls[i];
        }

        if(count >= cows)
            return true;
    }

    return false;
}

int main() {

    vector<int> stalls = {1,2,4,8,9};

    int cows = 3;

    sort(stalls.begin(), stalls.end());

    int left = 1;
    int right = stalls.back() - stalls.front();

    int answer = 0;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canPlace(stalls, cows, mid)) {

            answer = mid;

            left = mid + 1;
        }
        else {

            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}