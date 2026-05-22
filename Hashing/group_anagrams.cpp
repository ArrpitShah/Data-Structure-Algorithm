#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    vector<string> strs = {
        "eat","tea","tan","ate","nat","bat"
    };

    unordered_map<string, vector<string>> mp;

    // grouping
    for(string word : strs) {

        string sortedWord = word;

        sort(sortedWord.begin(), sortedWord.end());

        mp[sortedWord].push_back(word);
    }

    // print groups
    for(auto x : mp) {

        for(string word : x.second) {
            cout << word << " ";
        }

        cout << endl;
    }

    return 0;
}