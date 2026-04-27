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

Node* reverseL(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL){
        next = current->next;   
        current->next = prev;   
        prev = current;        
        current = next;        
    }
    return prev; 
}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* fourth=new Node(4);
    Node* fifth=new Node(5);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    printL(head);
    head = reverseL(head);
    printL(head);
}
