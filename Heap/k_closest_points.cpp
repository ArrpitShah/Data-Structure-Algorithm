#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    vector<pair<int,int>> points = {
        {1,3},
        {-2,2},
        {5,8},
        {0,1}
    };

    int k = 2;

    priority_queue<
        pair<int,pair<int,int>>
    > pq;

    for(auto point : points) {

        int x = point.first;
        int y = point.second;

        int dist = x*x + y*y;

        pq.push({dist, {x,y}});

        if(pq.size() > k) {

            pq.pop();
        }
    }

    while(!pq.empty()) {

        cout
        << "("
        << pq.top().second.first
        << ","
        << pq.top().second.second
        << ") ";

        pq.pop();
    }

    return 0;
}