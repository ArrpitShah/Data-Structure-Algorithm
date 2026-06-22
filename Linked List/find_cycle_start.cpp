#include <iostream>
using namespace std;

class Node {

public:

    int data;
    Node* next;

    Node(int data) {

        this->data = data;
        this->next = NULL;
    }
};

Node* findCycleStart(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL &&
          fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {

            slow = head;

            while(slow != fast) {

                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // cycle starts at 3
    head->next->next->next->next->next =
        head->next->next;

    Node* start = findCycleStart(head);

    if(start) {

        cout << "Cycle starts at: "
             << start->data;
    }

    return 0;
}