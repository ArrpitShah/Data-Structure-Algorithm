#include <iostream>
#include <stack>
using namespace std;

int main() {

    string s = "{[()]}";

    stack<char> st;

    bool valid = true;

    for(char ch : s) {

        // opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {

            st.push(ch);
        }

        // closing brackets
        else {

            if(st.empty()) {
                valid = false;
                break;
            }

            char top = st.top();

            if(
                (ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')
            ) {
                st.pop();
            }
            else {
                valid = false;
                break;
            }
        }
    }

    if(!st.empty())
        valid = false;

    if(valid)
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}