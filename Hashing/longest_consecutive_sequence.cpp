#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    int arr[] = {100,4,200,1,3,2};

    int n = 6;

    unordered_set<int> st;

    // insert all elements
    for(int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int longest = 0;

    for(int i = 0; i < n; i++) {

        int num = arr[i];

        // start of sequence
        if(st.find(num - 1) == st.end()) {

            int currentNum = num;
            int count = 1;

            while(st.find(currentNum + 1) != st.end()) {

                currentNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    cout << longest;

    return 0;
}