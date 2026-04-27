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

void mergeDLL(Node*& head1, Node*& head2) {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    if (head2 == NULL) {
        return;
    }

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
}


int main() {
        Node* head1 = new Node(1);
    Node* second1 = new Node(2);
    Node* third1 = new Node(3);
    head1->next = second1;
    second1->prev = head1;
    second1->next = third1;
    third1->prev = second1;

    Node* head2 = new Node(4);
    Node* second2 = new Node(5);
    head2->next = second2;
    second2->prev = head2;

    cout << "First List: ";
    printDL(head1);

    cout << "Second List: ";
    printDL(head2);

    mergeDLL(head1, head2);
    cout << "Merged List: ";
    printDL(head1);
}
