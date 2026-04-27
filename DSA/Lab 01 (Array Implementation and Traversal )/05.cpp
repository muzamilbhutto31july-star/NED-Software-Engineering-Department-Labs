#include<iostream>
using namespace std;
int main(){
    int arr[8]={25,16,38,10,35,48,20,50};
    int size=sizeof(arr)/sizeof(arr[0]);
    int max1,max2;
    if(arr[0]>=arr[1]){
        max1=arr[0];
        max2=arr[1];
    }
    else{
        max2=arr[0];
        max1=arr[1];
    }

    for(int i=2;i<size;i++){
        if(arr[i]>max1){
            max2=max1;
            max1=arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    cout<<"Second Maximum element is: "<<max2;
}