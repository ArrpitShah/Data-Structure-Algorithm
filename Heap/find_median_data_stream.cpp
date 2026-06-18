#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {

private:

    priority_queue<int> maxHeap;

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;

public:

    void addNum(int num) {

        maxHeap.push(num);

        minHeap.push(maxHeap.top());

        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()) {

            maxHeap.push(minHeap.top());

            minHeap.pop();
        }
    }

    double findMedian() {

        if(maxHeap.size() == minHeap.size()) {

            return
            (
                maxHeap.top()
                +
                minHeap.top()
            ) / 2.0;
        }

        return maxHeap.top();
    }
};

int main() {

    MedianFinder mf;

    mf.addNum(1);
    cout << mf.findMedian() << endl;

    mf.addNum(2);
    cout << mf.findMedian() << endl;

    mf.addNum(3);
    cout << mf.findMedian() << endl;

    mf.addNum(4);
    cout << mf.findMedian() << endl;

    return 0;
}