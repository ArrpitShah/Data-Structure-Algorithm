#include <iostream>
#include <vector>
using namespace std;

bool canShip(vector<int>& weights,
             int days,
             int capacity) {

    int currentDays = 1;
    int currentLoad = 0;

    for(int weight : weights) {

        if(currentLoad + weight <= capacity) {

            currentLoad += weight;
        }
        else {

            currentDays++;
            currentLoad = weight;

            if(currentDays > days)
                return false;
        }
    }

    return true;
}

int main() {

    vector<int> weights =
    {1,2,3,4,5,6,7,8,9,10};

    int days = 5;

    int left = 10;
    int right = 55;

    int answer = right;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canShip(weights, days, mid)) {

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