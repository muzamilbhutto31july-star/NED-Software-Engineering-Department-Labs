#include <iostream>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node(char v) {
        data = v;
        next = NULL;
    }
};
class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        void push(char v) {
            Node* newNode = new Node(v);
            newNode->next = top;
            top = newNode;
        }

        void pop() {
            if (top == NULL) {
                cout << "Stack Underflow!"<< endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        char peek() {
            if (top == NULL) {
                return '\0';
            }
            return top->data;
        }

        bool isEmpty() { 
            return top == NULL; 
        }
};

bool check(string str) {
    Stack s;
    int n=str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } 
        else {
            if (s.isEmpty()) {
                return false;
            }
            else if (str[i] == ')') {
                if (s.peek() != '(') {
                    return false;
                }
                else {
                    s.pop();
                }
            }
            else if (str[i] == '}') {
                if (s.peek() != '{') {
                    return false;
                }
                else {
                    s.pop();
                }
            }
            else if (str[i] == ']') {
                if (s.peek() != '[') {
                    return false;
                }
                else {
                    s.pop();
                }
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string str = "{()()[]}()";

    if (check(str))
        cout<<"Balanced!"<<endl;
    else
        cout<<"Not Balanced!"<<endl;

    return 0;
}



