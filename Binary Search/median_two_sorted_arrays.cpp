#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedian(vector<int>& a,
                  vector<int>& b) {

    if(a.size() > b.size())
        swap(a, b);

    int n1 = a.size();
    int n2 = b.size();

    int low = 0;
    int high = n1;

    while(low <= high) {

        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 =
            (cut1 == 0)
            ? INT_MIN
            : a[cut1 - 1];

        int left2 =
            (cut2 == 0)
            ? INT_MIN
            : b[cut2 - 1];

        int right1 =
            (cut1 == n1)
            ? INT_MAX
            : a[cut1];

        int right2 =
            (cut2 == n2)
            ? INT_MAX
            : b[cut2];

        if(left1 <= right2 &&
           left2 <= right1) {

            if((n1 + n2) % 2 == 0) {

                return
                (
                    max(left1,left2)
                    +
                    min(right1,right2)
                ) / 2.0;
            }

            return max(left1,left2);
        }

        else if(left1 > right2) {

            high = cut1 - 1;
        }

        else {

            low = cut1 + 1;
        }
    }

    return 0;
}

int main() {

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    cout << findMedian(nums1, nums2);

    return 0;
}