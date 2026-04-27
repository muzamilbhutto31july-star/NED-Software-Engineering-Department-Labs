#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            data=value;
            next=NULL;
        }
};

void printL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

void insertAtB(Node* &head,int value){
    Node* temp=new Node(value);
    temp->next=head;
    head=temp;

}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    head->next=second;
    second->next=third;
    third->next=fourth;

    printL(head);
    insertAtB(head,5);
    printL(head);
}