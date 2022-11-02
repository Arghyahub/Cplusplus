//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{		// FIND INDEX OF THE ARR[I]-K AND SUBTRACT THAT FROM N TO FIND THE TOTAL NUMBER OF CARDS TO REMOVE
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end()) ;
        int ans=INT_MAX , n=arr.size();
        for (int i=n-1; i>=0; i--){
            int j = lower_bound(arr.begin(),arr.end(),arr[i]-k) - arr.begin() ;
            int temp = n - (i-j+1);
            ans=min(ans,temp) ;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends
