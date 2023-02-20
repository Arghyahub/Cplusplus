// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> suff(n,0) ;
        vector<int> pref(n,0) ;
        
        suff[n-1] = arr[n-1] ;
        for (int i=n-2; i>=0; i--)
            suff[i] = max(arr[i],suff[i+1]) ;
        
        pref[0] = arr[0] ;
        for (int i=1; i<n; i++) 
            pref[i] = max(arr[i],pref[i-1]) ;
        
        long long ans = 0;
       								// Minimum of greatest from left,right - current number of blocks 
        for (int i=0; i<n; i++){
            ans += min(pref[i],suff[i]) - arr[i] ;
        }
        
        return ans;
    }
};
