#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    vector<int> nums = {3,2,1,5,6,4};

    int k = 2;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

    for(int num : nums) {

        pq.push(num);

        if(pq.size() > k) {

            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}