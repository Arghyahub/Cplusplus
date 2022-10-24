//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long inv = 0;
        inv = mergeSort(arr,0,N-1) ;
        return inv;
    }
    
    long long mergeSort(long long *arr, long long s, long long e)
    {
        long long inv = 0;
        if (s<e){
            
            int mid = s+(e-s)/2;
            inv += mergeSort(arr,s,mid) ;
            inv += mergeSort(arr,mid+1,e) ;
            
            inv += merge(arr,s,e) ;
        }
        return inv;
    }
    
    long long merge(long long *main, long long s, long long e)
    {
        int mid = s+(e-s)/2;
        int len1 = mid+1 - s;
        int len2 = e - mid;
        
        long long *arr1 = new long long[len1] ;
        long long *arr2 = new long long[len2] ;
        
        int j=0;
        for (int i=s; i<=mid; i++)
            arr1[j++] = main[i] ;
        
        j=0;
        for (int i=mid+1; i<=e; i++)
            arr2[j++] = main[i] ;
        
        long long inv=0;
        j=0;
        int i=0 , k = s;
        
        while(i<len1 && j<len2)
        {
            if (arr1[i]<=arr2[j])
                main[k++] = arr1[i++] ;
            else{
                main[k++] = arr2[j++] ;
                inv += len1 - i;
            }
        }
        
        while(i<len1)
            main[k++] = arr1[i++] ;
        
        while(j<len2)
            main[k++] = arr2[j++] ;
            
        return inv;
    }
    

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends