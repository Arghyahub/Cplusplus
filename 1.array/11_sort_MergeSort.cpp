#include<bits/stdc++.h>

using namespace std;

int printArr(vector<int> &vec) {
    for (int x : vec) cout<<x<<" ";
    cout<<endl;
}

void merge(vector<int> &arr, int s, int e, int mid) {
    int leftLen = mid-s+1, rightLen = e-mid;
    vector<int> left(leftLen), right(rightLen);

    int l=0, r=0;
    for (l=0; l<leftLen; l++) left[l] = arr[s+l];
    for (r=0; r<rightLen; r++) right[r] = arr[mid+1+r];
    
    l=0, r=0;
    while (l<leftLen && r<rightLen){
        if (left[l]<=right[r])
            arr[s++] = left[l++];
        else 
            arr[s++] = right[r++];
    }

    while (l<leftLen) arr[s++] = left[l++];
    while (r<rightLen) arr[s++] = right[r++];
}

void sortArr(vector<int> &arr, int s, int e) {
    if (s>=e) return;
    int mid = s + (e-s)/2;
    sortArr(arr,s,mid);
    sortArr(arr,mid+1,e);
    merge(arr,s,e,mid);
}


int main() {
    vector<int> arr = {1,3,5,2,7,4,9,3};
    printArr(arr);
    sortArr(arr, 0, arr.size()-1);
    printArr(arr);
    return 0;
}