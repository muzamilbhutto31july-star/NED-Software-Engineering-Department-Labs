#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& a,int l,int r) {
    int randomIndex=l+rand()%(r-l+1);
    swap(a[randomIndex],a[r]);
    int pivot=a[r];
    int i=l-1;
    for(int j=l; j<=r-1; ++j) {
        if (a[j]<=pivot) {
            ++i;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quickSort(vector<int>& a,int l,int r) {
    if (l<r) {
        int pi=partition(a, l, r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

void printVec(const vector<int>& a) {
    for(int x : a) {
        cout<<x<<" ";
    }
    cout << "\n";
}
int main() {
    srand(time(0));
    vector<int> arr={3,1,5,2,0,7,6};
    cout<<"Original: ";
    printVec(arr);
    auto a2=arr;
    quickSort(a2,0,a2.size()-1);
    cout<<"Quick Sort (Random Pivot): ";
    printVec(a2);
}



