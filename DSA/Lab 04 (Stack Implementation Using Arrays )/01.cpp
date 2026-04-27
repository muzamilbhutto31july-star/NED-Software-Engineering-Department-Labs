#include<iostream>
using namespace std;

class Stack {
    int* arr;
    int size;
    int top;
public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[s];
    }

    void push(int v) {
        if (top == size - 1) {
            cout << "Stack overflow!!" << endl;
        } else {
            arr[++top] = v;
            cout << "Pushed " << v << " into the stack" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow!!" << endl;
        } else {
            cout << "Popped " << arr[top] << " from the stack" << endl;
            top--;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }

    bool isempty() {
        return (top == -1);
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);

    do {
        cout << "\n**************** STACK MENU *************" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek (Top Element)" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"-------------------------"<<endl;
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout<<"-------------------------"<<endl;
                break;


            case 2:
                cout<<"-------------------------"<<endl;
                s.pop();
                cout<<"-------------------------"<<endl;
                break;


            case 3:
                cout<<"-------------------------"<<endl;
                value = s.peek();
                if (value != -1)
                    cout << "Top element is: " << value << endl;
                cout<<"-------------------------"<<endl;
                break;

            case 4:
                cout<<"-------------------------"<<endl;
                s.display();
                cout<<"-------------------------"<<endl;
                break;

            case 5:
                cout<<"-------------------------"<<endl;
                if (s.isempty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                cout<<"-------------------------"<<endl;
                break;


            case 6:
                cout<<"-------------------------"<<endl;
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
