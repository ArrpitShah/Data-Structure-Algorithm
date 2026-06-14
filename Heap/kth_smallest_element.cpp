#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    vector<int> nums = {7,10,4,3,20,15};

    int k = 3;

    priority_queue<int> pq;

    for(int num : nums) {

        pq.push(num);

        if(pq.size() > k) {

            pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}