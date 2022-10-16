class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size() ;
        map<pair<int,int>,int> maxi;        // NEW CONCEPT
        
        for (int i=0; i<n; i++){
            maxi[{i,i}] = arr[i] ;
            for (int j=i+1; j<n; j++)
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]) ;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
        
        for (int start=n-1; start>=0; start--){
            for (int end=0; end<n; end++){
                if (start>=end) continue;
                int ans = 1e6 ;
                for (int k=start; k<end; k++){
                    int tmp = maxi[{start,k}]*maxi[{k+1,end}] + dp[start][k]+dp[k+1][end];
                    ans = min(ans,tmp) ;
                }
                dp[start][end] = ans; 
            }
        }
        return dp[0][n-1] ;
    }
};
