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

void search(Node* head, int key) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }
    Node* temp = head;
    int pos = 0;
    bool found = false;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value " << key << " found at Index " << pos << endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << "Value " << key << " not found in the list" << endl;
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
    search(head,3);

}