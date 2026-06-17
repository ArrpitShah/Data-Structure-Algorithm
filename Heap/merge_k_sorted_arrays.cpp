#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {

    int value;
    int row;
    int col;

    bool operator>(const Node& other) const {

        return value > other.value;
    }
};

int main() {

    vector<vector<int>> arr = {

        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    priority_queue<
        Node,
        vector<Node>,
        greater<Node>
    > pq;

    int k = arr.size();

    // first element of each array
    for(int i = 0; i < k; i++) {

        pq.push({
            arr[i][0],
            i,
            0
        });
    }

    vector<int> result;

    while(!pq.empty()) {

        Node current = pq.top();

        pq.pop();

        result.push_back(current.value);

        int row = current.row;
        int col = current.col;

        if(col + 1 < arr[row].size()) {

            pq.push({

                arr[row][col + 1],
                row,
                col + 1
            });
        }
    }

    for(int x : result) {

        cout << x << " ";
    }

    return 0;
}