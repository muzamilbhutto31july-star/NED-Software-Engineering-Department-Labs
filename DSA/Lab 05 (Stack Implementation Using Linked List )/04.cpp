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
    bool isEmpty() {
        return top == NULL;
    }
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty!!!" << endl;
            return -1;
        }
        return top->data;
    }
    int getSize() {
        return size;
    }
};

Stack reverseStack(Stack s) {
    Stack temp;
    while (!s.isEmpty()) {
        int val = s.peek();
        s.pop();
        temp.push(val);
    }
    return temp;
}
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s = reverseStack(s);
    s.display();
}




