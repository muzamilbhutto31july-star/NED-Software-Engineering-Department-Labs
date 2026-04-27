#include<iostream>
using namespace std;
void printArr(int arr[],int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverseArr(int* arr,int s){
    int start=0;
    int end=s-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array before reversing : ";
    printArr(arr,size);
    reverseArr(arr,size);
    cout<<"Array after reversing  : ";
    printArr(arr,size);
}