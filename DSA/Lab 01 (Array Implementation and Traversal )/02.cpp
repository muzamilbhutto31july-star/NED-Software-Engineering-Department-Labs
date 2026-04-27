#include<iostream>
using namespace std;
void sum_averageOfarr(int arr[],int s){
    int sum=0;
    for(int i=0;i<s;i++){
        sum+=arr[i];
    }
    cout<<"Sum of Array "<<sum<<endl;
    cout<<"Average of Array "<<sum/float(s)<<endl;
}

int main(){
    int arr[6]={3,6,3,6,8,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    sum_averageOfarr(arr,size);
}