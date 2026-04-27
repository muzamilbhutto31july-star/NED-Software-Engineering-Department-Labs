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


void DeleteAtB(Node* &head){
    if(head==NULL){
        cout<<"List Empty";
        return;

    }
    Node* temp=head;
    head=head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;    
}


void DeleteAtE(Node* &head){
    if(head==NULL){
        cout<<"List Empty";
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    else {
        head = NULL;
    }
    delete temp;  
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
    DeleteAtE(head);
    ForwardDL(head);
    

}
