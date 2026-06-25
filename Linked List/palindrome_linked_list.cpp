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

Node* reverseList(Node* head) {

    Node* prev = NULL;

    while(head != NULL) {

        Node* nextNode = head->next;

        head->next = prev;

        prev = head;

        head = nextNode;
    }

    return prev;
}

bool isPalindrome(Node* head) {

    if(head == NULL ||
       head->next == NULL) {

        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next &&
          fast->next->next) {

        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf =
        reverseList(slow->next);

    Node* firstHalf = head;

    while(secondHalf != NULL) {

        if(firstHalf->data !=
           secondHalf->data) {

            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if(isPalindrome(head)) {

        cout << "Palindrome";
    }
    else {

        cout << "Not Palindrome";
    }

    return 0;
}