#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int v){
            data=v;
            next=NULL;
        }
};

class Queue{
    public:
        Node* front;
        Node* rear;
        Queue(){
            front=NULL;
            rear=NULL;
        }

    void enqueue(int v){
        Node* temp=new Node(v);
        cout<<"Enqueued "<<v<<" into Queue"<<endl;
        if(front==NULL){
            front=rear=temp;   
            return ;
        }
        rear->next=temp;
        rear=rear->next;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue UnderFlow!!"<<endl;
            return;

        }
        Node* temp=front;
        cout<<"Dequeued "<<temp->data<<" from Queue"<<endl;
        front=front->next;
        delete temp;
    }
};

int main()
{
    Queue q;
    int choice, value;

    while (true) {
        cout << "--- Queue Menu ---"<<endl;
        cout << "1. Enqueue (Add)"<<endl;
        cout << "2. Dequeue (Remove)"<<endl;
        cout << "3. Exit"<<endl;
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
                return 0;

            default:
                cout << "Invalid choice! Please try again."<<endl;
        }
    }
}