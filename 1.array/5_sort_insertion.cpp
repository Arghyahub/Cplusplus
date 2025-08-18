#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = { 1,7,4,5,2,8,9,6 };
    int N = sizeof(arr)/sizeof(int);

    for (int i=1; i<N; i++){
        int curr = arr[i];
        int idx = i-1;
        while (idx>=0 && arr[idx] > curr){
            arr[idx+1] = arr[idx];
            idx--;
        }
        arr[idx+1] = curr;
    }

    for (int i=0; i<N; i++) cout<<arr[i]<<" ";

    return 0;
}