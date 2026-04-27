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

void sortL(Node* head) {
    if (head == NULL || head->next == NULL) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main(){
    Node* head=new Node(1);
    Node* second=new Node(4);
    Node* third=new Node(2);
    Node* fourth=new Node(3);
    head->next=second;
    second->next=third;
    third->next=fourth;

    printL(head);
    sortL(head);
    printL(head);
}