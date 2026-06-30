#include <iostream>
using namespace std;

class Node {

public:

    int data;
    Node* next;
    Node* random;

    Node(int data) {

        this->data = data;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    if(head == NULL)
        return NULL;

    // Step 1: Insert copied nodes
    Node* curr = head;

    while(curr) {

        Node* copy = new Node(curr->data);

        copy->next = curr->next;

        curr->next = copy;

        curr = copy->next;
    }

    // Step 2: Copy random pointers
    curr = head;

    while(curr) {

        if(curr->random)

            curr->next->random =
                curr->random->next;

        curr = curr->next->next;
    }

    // Step 3: Separate lists
    Node* dummy = new Node(0);

    Node* copyCurr = dummy;

    curr = head;

    while(curr) {

        copyCurr->next = curr->next;

        curr->next = curr->next->next;

        copyCurr = copyCurr->next;

        curr = curr->next;
    }

    return dummy->next;
}

void print(Node* head) {

    while(head) {

        cout << head->data << " ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    Node* copy = copyRandomList(head);

    print(copy);

    return 0;
}