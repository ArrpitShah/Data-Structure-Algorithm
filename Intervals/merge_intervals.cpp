#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<pair<int,int>> intervals = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    // sort intervals
    sort(intervals.begin(), intervals.end());

    vector<pair<int,int>> merged;

    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {

        int start = intervals[i].first;
        int end = intervals[i].second;

        int lastEnd = merged.back().second;

        // overlap
        if(start <= lastEnd) {

            merged.back().second =
                max(lastEnd, end);
        }

        // no overlap
        else {

            merged.push_back(intervals[i]);
        }
    }

    // print result
    for(auto x : merged) {

        cout << "[";

        cout << x.first << ",";

        cout << x.second << "] ";
    }

    return 0;
}
