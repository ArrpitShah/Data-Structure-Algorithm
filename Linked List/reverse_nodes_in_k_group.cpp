#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* reverseKGroup(Node* head, int k) {

    Node* temp = head;

    for(int i = 0; i < k; i++) {

        if(temp == NULL)
            return head;

        temp = temp->next;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    int count = 0;

    while(curr != NULL && count < k) {

        nextNode = curr->next;

        curr->next = prev;

        prev = curr;

        curr = nextNode;

        count++;
    }

    if(nextNode != NULL) {

        head->next =
            reverseKGroup(nextNode, k);
    }

    return prev;
}

void printList(Node* head) {

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
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    head = reverseKGroup(head, k);

    printList(head);

    return 0;
}