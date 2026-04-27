#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = NULL;
    }
};

class Stack {
    private:
        Node* top;
        int size;

    public:
        Stack() {
            top = NULL;
            size = 0;
        }

        void push(int v) {
            Node* newNode = new Node(v);
            newNode->next = top;
            top = newNode;
            size++;
            cout << v << " pushed into stack." << endl;
        }

        void pop() {
            if (top == NULL) {
                cout << "Stack Underflow!" << endl;
                return;
            }
            cout << top->data << " popped from stack." << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }

        void display() {
            if (top == NULL) {
                cout << "Stack is empty." << endl;
                return;
            }
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void peek() {
            if (top == NULL) {
                cout << "Stack is empty!!!" << endl;
                return;
            }
            cout << "Top element is: " << top->data << endl;
        }
        
        void getSize() {
            cout << "Current size of the stack is: " << size << endl;
        }
};


int main() {
    Stack s;
    int choice, value;

    do {  
        cout << "\n*******************************" << endl;
        cout << "   LINKED LIST STACK MENU" << endl;
        cout << "*********************************" << endl;
        cout << "1. Insert element (Push)" << endl;
        cout << "2. Delete top element (Pop)" << endl;
        cout << "3. View top element (Peek)" << endl;
        cout << "4. Show all elements (Display)" << endl;
        cout << "5. Get Size" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                if (cin >> value) {
                    s.push(value);
                } else {
                    cout << "Invalid value entered." << endl;
                }
                break;

            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                s.getSize();
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}