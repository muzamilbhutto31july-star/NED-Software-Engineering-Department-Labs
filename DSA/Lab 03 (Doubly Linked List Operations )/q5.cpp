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

void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
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

    deleteAtPosition(head, 3);

    cout << "After Deletion: ";
    printDL(head);

    return 0;
}
