#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v){
        data = v;
        next = NULL;
        
    }
};

// Print circular linked list
void printS(Node* head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = head;
    do{
        cout << temp->data << "-->";
        temp = temp->next;
    } while(temp != head);

    cout << "head" << endl;
}


// Insert at beginning
void insertB(Node* &head, int v){
    Node* new_Node = new Node(v);

    if(head == NULL){
        new_Node->next = new_Node;
        head = new_Node;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next; 
    }

    new_Node->next = head;
    temp->next = new_Node;
    head = new_Node;
}


// Delete at beginning
void deleteB(Node* &head){
    if(head == NULL) return;

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }

    tail->next = head->next;
    delete head;
    head = tail->next;
}


// Insert at end
void insertE(Node* &head, int v){
    Node* new_Node = new Node(v);

    if(head == NULL){
        new_Node->next = new_Node;
        head = new_Node;
        return;
    }

    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }

    tail->next = new_Node;
    new_Node->next = head;
}


// Delete at end
void deleteE(Node* &head){
    if(head == NULL) return;

    if(head->next == head){
        delete head;
        head = NULL;
        return;
    }

    Node* tail = head;
    Node* pretail = NULL;
    while(tail->next!= head){
        pretail=tail;
        tail = tail->next;
    }

    pretail->next = head;
    delete tail;
}


void insertP(Node* &head, int pos, int v){
    Node* new_Node = new Node(v);

    if(pos == 1){
        insertB(head, v);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    new_Node->next = temp->next;
    temp->next = new_Node;
}



// Delete at a specific position
void deleteP(Node* &head, int pos){
    if(pos == 1){
        deleteB(head);
        return;
    }

    Node* temp = head;
    int count = 1;


    while(count < pos-1 && temp->next != head){
        temp = temp->next;
        count++;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}



// MAIN
int main(){
    Node* head = NULL;

    insertB(head, 3);
    insertB(head, 2);
    insertB(head, 1);

    printS(head);

    insertE(head, 4);
    insertE(head, 5);
    printS(head);

    insertP(head, 3, 99);
    printS(head);

    deleteB(head);
    printS(head);

    deleteE(head);
    printS(head);

    deleteP(head, 3);
    printS(head);

    return 0;
}
