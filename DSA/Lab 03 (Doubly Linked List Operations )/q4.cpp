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

void insertAtPos(Node*& head, int pos, int data) {
    Node* newNode = new Node(data);
    if (pos == 0 || head == NULL) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL && count < pos - 1) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
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

    insertAtPos(head, 4, 44);

    cout << "After Insertion: ";
    printDL(head);

    return 0;
}
