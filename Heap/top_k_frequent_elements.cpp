#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {

    vector<int> nums = {1,1,1,2,2,3};

    int k = 2;

    unordered_map<int,int> freq;

    for(int num : nums) {

        freq[num]++;
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    for(auto x : freq) {

        pq.push({x.second, x.first});

        if(pq.size() > k) {

            pq.pop();
        }
    }

    vector<int> answer;

    while(!pq.empty()) {

        answer.push_back(pq.top().second);

        pq.pop();
    }

    for(int x : answer) {

        cout << x << " ";
    }

    return 0;
}