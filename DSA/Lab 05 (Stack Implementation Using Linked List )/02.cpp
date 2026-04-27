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
};
int main() {
    Stack s;
    s.display();
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(3);
    s.display();
    s.peek();
}


