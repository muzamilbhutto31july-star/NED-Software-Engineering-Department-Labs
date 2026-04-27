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

void traverseFW(Node* head) {
    Node* temp = head;
    cout << "Forward: NULL <-> ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void traverseBW(Node* head) {
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    Node* ptr = tail;
    cout << "Backward: ";
    while (ptr != NULL) {
        cout << ptr->data << " <-> ";
        ptr = ptr->prev;
    }
    cout << "NULL" << endl;
}

void insertAtB(Node* &head,int v){
    if(head==NULL){
        head=new Node(v);
    }
    else{
        Node* temp=new Node(v);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtE(Node* &head,int v){
    if(head==NULL){
        head=new Node(v);
    }
    else{
        Node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        Node* temp=new Node(v);
        curr->next=temp;
        temp->prev=curr;
    }
}

void insertAtPos(Node*& head, int pos, int data) {
    if (pos == 0) {
        insertAtB(head, data);
        return;
    }
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteAtB(Node*& head) {
    if (head == NULL) {
        cout << "List Empty";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void deleteAtE(Node*& head) {
    if (head == NULL) {
        cout << "List Empty";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    delete temp;
}


void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }
    Node* ptr = head;
    int i = 0;
    while (ptr != NULL && i < pos) {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        cout << "Position out of range" << endl;
        return;
    }
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    delete ptr;
}

void deleteAllWith(Node*& head, int value) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }

    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        if (curr->data == value) {
            if (curr->prev == NULL) {
                head = curr->next;
                if (head != NULL)
                    head->prev = NULL;
            } else {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            delete curr;
        }
        curr = nextNode;
    }
}

void clearList(Node*& head) {
    Node* curr = head;

    while (curr != NULL) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    head = NULL;
}

int main()
{
    Node* head=new Node(3);
    Node* second=new Node(2);
    Node* third=new Node(3);
    Node* forth=new Node(3);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=forth;
    forth->prev=third;
    printDL(head);
    clearList(head);
    printDL(head);

}


