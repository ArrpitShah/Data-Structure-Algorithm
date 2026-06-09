#include <iostream>
using namespace std;

long long power(int base, int n) {

    long long result = 1;

    for(int i = 0; i < n; i++) {

        result *= base;
    }

    return result;
}

int main() {

    int n = 3;
    int m = 27;

    int left = 1;
    int right = m;

    int answer = -1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        long long value = power(mid, n);

        if(value == m) {

            answer = mid;
            break;
        }

        else if(value < m) {

            left = mid + 1;
        }

        else {

            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}