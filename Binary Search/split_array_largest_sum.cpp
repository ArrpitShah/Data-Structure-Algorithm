#include <iostream>
#include <vector>
using namespace std;

bool canSplit(vector<int>& nums,
              int k,
              int maxSum) {

    int parts = 1;
    int currentSum = 0;

    for(int num : nums) {

        if(currentSum + num <= maxSum) {

            currentSum += num;
        }
        else {

            parts++;
            currentSum = num;

            if(parts > k)
                return false;
        }
    }

    return true;
}

int main() {

    vector<int> nums = {7,2,5,10,8};

    int k = 2;

    int left = 10;
    int right = 32;

    int answer = right;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canSplit(nums, k, mid)) {

            answer = mid;
            right = mid - 1;
        }
        else {

            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}