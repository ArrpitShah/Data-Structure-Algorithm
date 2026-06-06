#include <iostream>
#include <vector>
using namespace std;

bool canPaint(vector<int>& boards,
              int painters,
              int maxTime) {

    int painterCount = 1;
    int currentTime = 0;

    for(int board : boards) {

        if(currentTime + board <= maxTime) {

            currentTime += board;
        }
        else {

            painterCount++;
            currentTime = board;

            if(painterCount > painters)
                return false;
        }
    }

    return true;
}

int main() {

    vector<int> boards = {10,20,30,40};

    int painters = 2;

    int left = 40;
    int right = 100;

    int answer = -1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canPaint(boards,
                    painters,
                    mid)) {

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