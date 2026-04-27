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


void deleteAtPosition(Node*& head,int pos){
    if(head==NULL){
        cout<<"List Empty"<<endl;
        return;
    }
    Node* ptr=head;
    int i=0;
    while(ptr!=NULL&&i<pos){
        ptr=ptr->next;
        i++;
    }
    if(ptr==NULL){
        cout<<"Position out of range"<<endl;
        return;
    }
    if(ptr->prev!=NULL)
        ptr->prev->next=ptr->next;
    else
        head=ptr->next;
    if(ptr->next!=NULL)
        ptr->next->prev=ptr->prev;
    delete ptr;
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
    deleteAtPosition(head,3);
    ForwardDL(head);
    

}
