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
        int peek(){
            if(isEmpty()){
                cout<<"Queue is Empty!!"<<endl;
                return -1;
            }
            return front->data;
        }
            
        void displayAndCount() {
            int count = 0;
            if (isEmpty()) {
                cout << "Queue is Empty!!"<<endl;
                return;
            }
            Node* temp = front;
            cout << "Queue elements: ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
                count++;
            }
            cout << endl;
            cout << "There are total " << count << " elements in the Queue." << endl;
            }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.displayAndCount();
}








