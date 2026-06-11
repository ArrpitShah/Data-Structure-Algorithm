#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 3;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = 0;
    int right = rows * cols - 1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        int row = mid / cols;
        int col = mid % cols;

        int value = matrix[row][col];

        if(value == target) {

            cout << "Found";
            return 0;
        }

        else if(value < target) {

            left = mid + 1;
        }

        else {

            right = mid - 1;
        }
    }

    cout << "Not Found";

    return 0;
}