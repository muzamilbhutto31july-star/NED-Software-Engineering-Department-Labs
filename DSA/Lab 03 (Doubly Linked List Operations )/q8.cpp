#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int v) {
        data = v;
        prev = NULL;
        next = NULL;
    }
};

void printDL(Node* head) {
    Node* temp = head;
    cout << "NULL <--> ";
    while (temp != NULL) {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtB(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insertAtE(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(Node*& head, int pos, int data) {
    Node* newNode = new Node(data);

    if (pos == 0 || head == NULL) {
        insertAtB(head, data);
        delete newNode;
        return;
    }

    Node* temp = head;
    int count = 0;

    while (temp->next != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL && count < pos - 1) {
        cout << "Position out of range" << endl;
        delete newNode;
        return;
    }

    if (temp->next == NULL) {
        insertAtE(head, data);
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtB(Node*& head) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteAtE(Node*& head) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    delete temp;
}

void deleteAtPos(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List Empty" << endl;
        return;
    }

    Node* temp = head;
    int i = 0;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void searchValue(Node* head, int value) {
    Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found" << endl;
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

void reverseDLL(Node*& head) {
    if (head == NULL) return;

    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->prev != right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->prev;
    }
}

Node* mergeDLLs(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
    return head1;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int choice, data, pos, subChoice;

    do {
        cout << "\n==================<< DOUBLY LINKED LIST MENU >>=================\n";
        cout << "1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Display List"<<endl;
        cout << "4. Search Value"<<endl;
        cout << "5. Count Nodes"<<endl;
        cout << "6. Reverse List"<<endl;
        cout << "7. Merge Two Lists"<<endl;
        cout << "8. Exit"<<endl;
        cout << "================================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n--- INSERT MENU ---"<<endl;
            cout << "1. Insert at Beginning"<<endl;
            cout << "2. Insert at End"<<endl;
            cout << "3. Insert at Position"<<endl;
            cout << "Enter your choice: ";
            cin >> subChoice;
            cout << "Enter data: ";
            cin >> data;

            if (subChoice == 1)
                insertAtB(head1, data);
            else if (subChoice == 2)
                insertAtE(head1, data);
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> pos;
                insertAtPos(head1, pos, data);
            } else
                cout << "Invalid choice!"<<endl;
            break;

        case 2:
            cout << "\n--- DELETE MENU ---"<<endl;
            cout << "1. Delete at Beginning"<<endl;
            cout << "2. Delete at End"<<endl;
            cout << "3. Delete at Position"<<endl;
            cout << "Enter your choice: "<<endl;
            cin >> subChoice;

            if (subChoice == 1)
                deleteAtB(head1);
            else if (subChoice == 2)
                deleteAtE(head1);
            else if (subChoice == 3) {
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPos(head1, pos);
            } else
                cout << "Invalid choice!"<<endl;
            break;

        case 3:
            printDL(head1);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> data;
            searchValue(head1, data);
            break;

        case 5:
            cout << "Total Nodes: " << countNodes(head1) << endl;
            break;

        case 6:
            reverseDLL(head1);
            cout << "List reversed successfully!"<<endl;
            break;

        case 7:
            cout << "Creating second list automatically..."<<endl;
            head2 = new Node(100);
            head2->next = new Node(200);
            head2->next->prev = head2;
            head1 = mergeDLLs(head1, head2);
            cout << "Lists merged successfully!"<<endl;
            break;

        case 8:
            cout << "Exiting program... Goodbye!"<<endl;
            break;
            
        default:
            cout << "Invalid choice! Try again."<<endl;
        }
    } while (choice != 8);

}