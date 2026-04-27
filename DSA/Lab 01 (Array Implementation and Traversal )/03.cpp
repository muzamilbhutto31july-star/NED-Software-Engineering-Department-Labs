#include<iostream>
using namespace std;
int main(){
    int arr[6]={44,22,6,1,77,4};
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<6;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout << "Maximum element in array is: " << max << endl;
    cout << "Minimum element in array is: " << min << endl;
}