//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {

  public:
    int getSum(int X, int Y, int Z) {
        long long sum[X+1][Y+1][Z+1] , nums[X+1][Y+1][Z+1] ;
        
        fill(&sum[0][0][0] , &sum[0][0][0] + ( (X+1)*(Y+1)*(Z+1) ) , 0 ) ;
        fill(&nums[0][0][0] , &nums[0][0][0] + ( (X+1)*(Y+1)*(Z+1) ) , 0 ) ;
        
        int m = 1e9+7 ;
        
        nums[0][0][0] = 1; // say we have 100 -> 0 + 4*(000) will give zero
        // so we should take 000 as 1 num
        long long ans = 0;
        for (int i=0; i<=X; i++){
            for (int j=0; j<=Y; j++){
                for (int k=0; k<=Z; k++){
                    
                    if (i>0){
                        sum[i][j][k] += (sum[i-1][j][k]*10 + 4*nums[i-1][j][k])%m ; //prev sum*10 + 4*(number of digits used)
                        nums[i][j][k] += (nums[i-1][j][k])%m ;
                    }
                    if (j>0){
                        sum[i][j][k] += (sum[i][j-1][k]*10 + 5*nums[i][j-1][k])%m ;
                        nums[i][j][k] += (nums[i][j-1][k])%m ;
                    }
                    if (k>0){
                        sum[i][j][k] += (sum[i][j][k-1]*10 + 6*nums[i][j][k-1])%m ;
                        nums[i][j][k] += (nums[i][j][k-1])%m ;
                    }
                    ans+=sum[i][j][k]%m ;
                }
            }
        }
        return ans%m ;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends