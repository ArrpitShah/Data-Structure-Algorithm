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

Node* mergeLists(Node* list1,
                 Node* list2) {

    Node dummy(0);

    Node* tail = &dummy;

    while(list1 != NULL &&
          list2 != NULL) {

        if(list1->data < list2->data) {

            tail->next = list1;
            list1 = list1->next;
        }
        else {

            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if(list1 != NULL) {

        tail->next = list1;
    }

    if(list2 != NULL) {

        tail->next = list2;
    }

    return dummy.next;
}

void printList(Node* head) {

    while(head != NULL) {

        cout << head->data << " ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    Node* result =
        mergeLists(list1, list2);

    printList(result);

    return 0;
}