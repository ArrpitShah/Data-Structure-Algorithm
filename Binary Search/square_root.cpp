#include <iostream>
using namespace std;

int main() {

    int n = 25;

    int left = 0;
    int right = n;

    int answer = -1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        long long square = 1LL * mid * mid;

        if(square == n) {

            answer = mid;
            break;
        }

        else if(square < n) {

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