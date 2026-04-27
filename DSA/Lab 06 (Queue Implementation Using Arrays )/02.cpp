#include<iostream>
using namespace std;
class Queue{
    private:
        int* arr;
        int front,rear;
        int size;
    public:
        Queue(int s){
            arr=new int[s];
            front=rear=-1;
            size=s;
        }
        void enqueue(int v) {
            if (rear == size - 1) {
                cout << "Queue overflow!!" << endl;
            }
            else if (front == -1) {
                front = rear = 0;
                arr[rear] = v;
                cout << "Enqueued " << v << " into the queue" << endl;
            }
            else {
                rear++;
                arr[rear] = v;
                cout << "Enqueued " << v << " into the queue" << endl;
            }
        }
        void dequeue() {
            if (front == -1 || front > rear) {
                cout << "Queue underflow!!" << endl;
            }
            else {
                cout << "Dequeued " << arr[front] << " from the queue" << endl;
                front++;
                if (front > rear) {
                    front = rear = -1;
                }
            }
        }

        int peek() {
            if (front == -1 || front > rear) {
                cout << "Queue is Empty!!" << endl;
                return -1;
            }
            else {
                cout << "Front element is: " << arr[front] << endl;
                return arr[front];
            }
        }
};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peek();
}

