#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear;
    int size;

public:
    Queue(int s) {
        arr = new int[s];
        front = rear = -1;
        size = s;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void push(int v) {
        if (isFull()) {
            cout << "Queue Overflow!!" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = v;
        cout << "Pushed " << v << " into Queue" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!!" << endl;
            return;
        }

        cout << "Popped " << arr[front] << " from Queue" << endl;

        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % size;
        }
    }

    int start() {
        if (isEmpty()) {
            cout << "Queue is empty!!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    cout << "Front element: " << q.start() << endl;

    q.pop();
    q.display();

    q.push(40);
    q.push(50);
    q.push(60);  // will show overflow
    q.display();

    q.pop();
    q.pop();
    q.display();

    cout << "Front element: " << q.start() << endl;
}
