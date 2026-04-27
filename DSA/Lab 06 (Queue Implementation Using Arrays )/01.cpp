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
};

int main()
{
    int size;
    cout << "Enter queue size: ";
    cin >> size;
    Queue q(size);
    int choice, value;
    do {
            cout << "************** Queue Menu ***********"<<endl;
            cout << "1. Enqueue"<<endl;
            cout << "2. Dequeue"<<endl;
            cout << "3. Exit"<<endl;
            cout << "**************************************"<<endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value to enqueue: ";
                    cin >> value;
                    q.enqueue(value);
                    break;
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    cout << "Exiting program..."<<endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again"<<endl;
            }
        } while (choice != 3);

}
