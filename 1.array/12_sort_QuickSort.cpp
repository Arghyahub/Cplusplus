#include<bits/stdc++.h>
using namespace std;

int printArr(vector<int> &vec) {
    for (int x : vec) cout<<x<<" ";
    cout<<endl;
}

int partition(vector<int> &arr, int s, int e){
    int smallCount = 0;
    for (int i=s; i<=e; i++) smallCount += arr[i]<arr[s];

    int partIdx = s + smallCount;
    int store = arr[s];
    swap(arr[s],arr[partIdx]);

    int l=s, r=e;

    while (l<partIdx && r>partIdx){
        while (l<partIdx && arr[l]<store) l++;
        while (r>partIdx && arr[r]>store) r--;
        swap(arr[l],arr[r]);
    }

}

void quickSort(vector<int> &arr, int s, int e){
    if (s>=e) return;
    int partIdx = partition(arr,s,e);
    quickSort(arr,s,partIdx);
    quickSort(arr,partIdx+1,e);
}

int main() {
    vector<int> arr = {1,3,5,2,7,4,9,3};
    printArr(arr);
    quickSort(arr,0,arr.size()-1);
    printArr(arr);
    return 0;
}