#include <iostream>
#include <stack>
using namespace std;

int main() {

    int arr[] = {2,1,2,4,3};

    int n = 5;

    int result[100];

    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if(st.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}