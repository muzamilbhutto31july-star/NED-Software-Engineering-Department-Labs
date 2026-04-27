#include<iostream>
using namespace std;
 

class Stack{
        int* arr;
        int size;
        int top;
    public:
        Stack(int s){
            size=s;
            top=-1;
            arr=new int[s];
        }
        void push(int v){
            if(top==size-1){
                cout<<"Stack overflow!!"<<endl;
            }
            else{
                top++;
                arr[top]=v;
                cout<<"pushed "<<v<<" into the stack"<<endl;
            }
        }

        void pop(){
            if(size==-1){
                cout<<"Stack underflow!!"<<endl;
            }
            else{
                cout<<"Popped "<<arr[top]<<" from the stack"<<endl;
                top--;
            }
        }
        int peek(){
            if(top==-1){
                cout<<"Stack is empty!!"<<endl;
                return 0;
            }
            else{
                return arr[top];
            }
        }

        void display(){
            if(top==-1){
                cout<<"Stack is empty!!"<<endl;
            }
            else{
                for(int i=top;i>=0;i--){
                cout << arr[i] << "  ";
                }
                cout<<endl;
            }
        }
        bool isempty(){
            if(top==-1){
                return 1;
            }
            else{
                return 0;
            }
        }

        int peek() {
        if (top== -1) 
            return '\0';
        return arr[top];
        }
};

int main()
{
    Stack s(6);
    s.display();
    s.push(9);
    s.push(4);
    s.push(6);
    s.display();
    cout << "Top element is: " <<s.peek()<<endl;

}