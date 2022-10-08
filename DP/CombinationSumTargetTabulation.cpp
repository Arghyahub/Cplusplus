#include <bits/stdc++.h> 
// int solve(vector<int> &num, int tar, vector<int> &dp)
// {
//     if (tar<0) return 0 ;
//     if (tar==0) return 1 ;
    
//     if (dp[tar]!=-1) return dp[tar] ;
    
//     int ans = 0;
//     for (int i=0; i<num.size(); i++)
//         ans+= solve(num,tar-num[i],dp) ;
//     return dp[tar] = ans;
// }
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar+1,0) ;
    dp[0] = 1;
    
    for (int t=1; t<=tar; t++){
        int ans = 0 ;
        for (int i=0; i<num.size(); i++){
            if (t-num[i]>=0)
                ans+=dp[t-num[i]] ;
        }
        dp[t] = ans;
    }
    return dp[tar] ;
}
