#include <iostream>
#include <vector>
using namespace std;

bool canAllocate(vector<int>& books,
                 int students,
                 int maxPages) {

    int studentCount = 1;
    int pages = 0;

    for(int book : books) {

        if(pages + book <= maxPages) {

            pages += book;
        }
        else {

            studentCount++;

            pages = book;

            if(studentCount > students)
                return false;
        }
    }

    return true;
}

int main() {

    vector<int> books = {10,20,30,40};

    int students = 2;

    int left = 40;
    int right = 100;

    int answer = -1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(canAllocate(books,
                       students,
                       mid)) {

            answer = mid;

            right = mid - 1;
        }
        else {

            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}