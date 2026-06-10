//Lower Bound in C++ STL 
// >= target 
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {1, 3, 3, 5, 7};

    int index = lower_bound(arr, arr + 5, 3) - arr;

    cout << index;

    return 0;
}