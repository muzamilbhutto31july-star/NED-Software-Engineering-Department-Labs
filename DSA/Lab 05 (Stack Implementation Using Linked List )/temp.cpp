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
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
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
};

int main() {
    Stack myStack;
    
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    
    myStack.display();
    
    myStack.pop();
    
    myStack.display();
    
    return 0;
}