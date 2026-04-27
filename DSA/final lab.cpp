#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int v) {
        data = v;
        next = NULL;
        prev = NULL;
    }
};

void printD(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "<-->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
} 

void printDC(Node* head) {
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << "-->";
        temp = temp->next;
    } while (temp != head);

    cout << "head" << endl;
}


void insertE(Node*& head, int id) {
    Node* new_N = new Node(id);
    if (head == NULL) {
        head = new_N;
        return;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next = new_N;
    new_N->prev=tail;
}

void deleteB(Node*& head) {
    if (head==NULL) return;
    Node* temp = head;
    if (head->next == NULL) {
        head = NULL;
    } 
    else {
        head=head->next;
        head->prev=NULL;
    }
    delete temp;
}

void deleteID(Node*& head, int pd) {
    if (head == NULL) {
        return;
    }
    Node* curr=head;
    if (head->data == pd) {
        deleteB(head);
        return;
    }

    while (curr!=NULL && curr->data!=pd) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Product "<<pd<<"not found in the list." << endl;
        return;
    }

    curr->next->prev=curr->prev;
    curr->prev->next=curr->next;
    delete curr;
}

void convertToDoublyCircular(Node* &head) {
    Node* tail=head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    tail->next = head;
    head->prev = tail;
}


Node* findMiddle(Node* head) {
    if (!head) return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge2(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            temp->next = list1;
            list1->prev = temp;
            temp = list1;
            list1 = list1->next;
        } 
        else {
            temp->next = list2;
            list2->prev = temp;
            temp = list2;
            list2 = list2->next;
        }
    }

    if (list1) {
        temp->next = list1;
        list1->prev = temp;
    } else if (list2) {
        temp->next = list2;
        list2->prev = temp;
    }

    Node* sortedHead = dummyNode->next;
    if (sortedHead) sortedHead->prev = NULL;
    delete dummyNode;

    return sortedHead;
}

Node* Sort(Node* head) {
    if (!head || !head->next) return head;

    Node* middle = findMiddle(head);

    Node* right = middle->next;
    middle->next = NULL;
    if (right) right->prev = NULL;

    Node* left = head;

    left = Sort(left);
    right = Sort(right);
    return merge2(left, right);
}

int main() {
    Node* head = NULL;

    insertE(head, 45);
    printD(head);
    insertE(head, 12);
    printD(head);
    insertE(head, 67);
    printD(head);
    insertE(head, 23);
    printD(head);
    insertE(head, 89);
    printD(head);

    cout<<endl;
    deleteID(head, 89);
    printD(head);
    deleteID(head, 12);
    printD(head);

    convertToDoublyCircular(head);
    printDC(head);

    cout << "Sorting the list:" << endl;
    head->prev->next = NULL;
    head->prev = NULL;
    head = Sort(head);
    printD(head);

}
