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

Node* getIntersection(Node* headA,
                      Node* headB) {

    if(headA == NULL || headB == NULL)
        return NULL;

    Node* p1 = headA;
    Node* p2 = headB;

    while(p1 != p2) {

        if(p1 == NULL)
            p1 = headB;
        else
            p1 = p1->next;

        if(p2 == NULL)
            p2 = headA;
        else
            p2 = p2->next;
    }

    return p1;
}

int main() {

    Node* common = new Node(8);
    common->next = new Node(4);
    common->next->next = new Node(5);

    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node* ans = getIntersection(headA, headB);

    if(ans)
        cout << "Intersection Node = " << ans->data;
    else
        cout << "No Intersection";

    return 0;
}