#include<iostream>
using namespace std;
class Stack{
        char* arr;
        int size;
        int top;
    public:
        Stack(int s){
            size=s;
            top=-1;
            arr=new char[s];
        }
        void push(char v){
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
            if(top==-1){
                cout<<"Stack underflow!!"<<endl;
            }
            else{
                cout<<"Popped "<<arr[top]<<" from the stack"<<endl;
                top--;
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

        char peek() {
        if (top== -1) 
            return '\0';
        return arr[top];
        }
};

bool check(string str) {
    Stack s(str.size());
    for (int i =0; i < int(str.size()); i++) {
        if (str[i] == '('||str[i] == '{'||str[i] == '[') {
            s.push(str[i]);
        } 
        else{
            if(s.isempty()){
                return 0;
            }
            else if(str[i]==')'){
                if(s.peek()!='('){
                    return 0;
                }
                else{
                    s.pop();
                }
            }

            else if(str[i]=='}'){
                if(s.peek()!='{'){
                    return 0;
                }
                else{
                    s.pop();
                }
            }

            else if(str[i]==']'){
                if(s.peek()!='['){
                    return 0;
                }
                else{
                    s.pop();
                }
            }
        }
    }
    return s.isempty();
}

int main()
{
    string str="((()[{}]{}))";

    bool ans=check(str);

    if (ans){
        cout<<"Parentheses are balanced"<<endl;
    }
    else{
        cout<<"Parentheses are not balanced"<<endl;

    }
}