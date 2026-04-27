#include<iostream>
#include<vector>
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

void bubbleSort(vector<int>& arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortL(Node* head) {
    if (head == NULL || head->next == NULL) return;

    vector<int> arr;
    Node* temp = head;

    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    bubbleSort(arr, arr.size());

    temp = head;
    int i = 0;
    while (temp != NULL) {
        temp->data = arr[i++];
        temp = temp->next;
    }
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
