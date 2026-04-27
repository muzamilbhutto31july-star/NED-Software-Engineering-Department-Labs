#include<iostream>
using namespace std;
int main(){
    int arr[5]={};
    for(int i=0;i<5;i++){
        cout<<"Enter Element at index ["<<i+1<<"] = ";
        cin>>arr[i];
    }
    cout<<"-------------------------------------------------------"<<endl;
    for(int i=0;i<5;i++){
        cout<<"Element at index ["<<i+1<<"] is "<<arr[i]<<endl;
    }
}