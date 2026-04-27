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
        bool isEmpty(){
            return front==NULL;
        }
        void enqueue(int v){
            Node* temp=new Node(v);
            cout<<"Enqueued "<<v<<" into Queue"<<endl;
            if(isEmpty()){
                front=rear=temp;   
                return ;
            }
            rear->next=temp;
            rear=rear->next;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue UnderFlow!!"<<endl;
                return;

            }
            Node* temp=front;
            cout<<"Dequeued "<<temp->data<<" from Queue"<<endl;
            front=front->next;
            delete temp;
        }

        void clear() {
            if (isEmpty()) {
                cout << "Queue is already empty!\n";
                return;
            }

            while (!isEmpty()) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }

            rear = NULL;
            cout << "All elements have been removed. Queue is now empty!\n";
}

            
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.clear();
}








