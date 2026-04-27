#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int v){
            data=v;
            prev=NULL;
            next=NULL;
        }
};
void printDL(Node* head){
    Node* temp=head;
    cout<<"Null <--> ";
    while(temp!=NULL){
        cout<<temp->data<<" <--> ";
        temp=temp->next;
    }
    cout<<"NUll"<<endl;
}

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int main()
{
    Node* head=new Node(1);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* forth=new Node(4);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=forth;
    forth->prev=third;
    printDL(head);
    cout << "Total nodes in the linked list = " << countNodes(head) << endl;
}



