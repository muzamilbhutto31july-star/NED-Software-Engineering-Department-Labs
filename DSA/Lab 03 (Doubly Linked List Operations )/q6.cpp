#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int v) {
        data = v;
        prev = NULL;
        next = NULL;
    }
};

void printDL(Node* head) {
    Node* temp = head;
    cout << "NULL <--> ";
    while (temp != NULL) {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void reverseDLL(Node*& head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->prev != right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
    }
}



int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* forth = new Node(4);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = forth;
    forth->prev = third;

    cout << "Original List: ";
    printDL(head);

    reverseDLL(head);

    cout << "After Reversing: ";
    printDL(head);

    return 0;
}
