#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = nullptr;
    }
};

void push_back(Node*& head, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* last=head;
    while (last->next!=nullptr) {
        last=last->next;
    }
    last->next = new_node;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node* getMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* sortedMerge(Node* a, Node* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void mergeSort(Node*& headRef) {
    Node* head = headRef;
    Node* a;
    Node* b;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* middle = getMiddle(head);
    a = head;
    b = middle->next;
    
    middle->next = nullptr;

    mergeSort(a);
    mergeSort(b);

    headRef = sortedMerge(a, b);
}

void deleteList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    Node* head = nullptr;
    vector<int> initial_data = {3, 1, 5, 2, 0, 7, 6};

    for (int data : initial_data) {
        push_back(head, data);
    }

    cout << "Original List: "; 
    printList(head);

    mergeSort(head);

    cout << "Sorted List:   "; 
    printList(head);
    
    deleteList(head);

    return 0;
}