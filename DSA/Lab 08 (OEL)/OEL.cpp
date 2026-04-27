#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;




// ---------------------- Student ----------------------
class Student {
public:
    int id;
    string name;

    Student() : id(0), name("") {}
    Student(int id, string name) : id(id), name(name) {}
};

class Queue {
private:
    Student* arr;
    int front, rear;
    int size;

public:
    Queue(int s=10) {
        arr = new Student[s];
        front = rear = -1;
        size = s;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int v) {
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

    void dequeue() {
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

class Queue {
private:
    Student* arr;
    int front, rear, size;

public:
    Queue(int cap) {
        arr = new Student[cap];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    bool enqueue(Student s) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = s;
        size++;
        return true;
    }

    bool dequeue(Student &s) {
        if (isEmpty()){ 
            return false;
        }
        s = arr[front];
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    void display() {
        if (isEmpty()) {
            cout << "  (empty)\n";
            return;
        }
        cout << "  Waiting Students:\n";
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << "    " << arr[index].id << " - " << arr[index].name << endl;
            index = (index + 1) % capacity;
        }
    }
};