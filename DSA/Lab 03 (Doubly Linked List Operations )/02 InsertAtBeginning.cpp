#include<iostream>
using namespace std;

struct Node{
        int data;
        Node* prev;
        Node* next;
};

void ForwardDL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data=1;
    second->data=2;
    third->data=3;
    fourth->data=4;

    head->next = second;
    second->next = third;
    third->next = fourth;

    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    ForwardDL(head);

    insertAtBeginning(head,11);
    ForwardDL(head);
    

}
