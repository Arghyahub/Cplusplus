#include <bits/stdc++.h> 

long long int hrRec(vector<int>& v, int i, int n,vector<long long int> &dp)
{
    if (i>=n)
        return 0 ;
    
    if (dp[i]!=-1)
        return dp[i] ;
    
    long long int inc = v[i] + hrRec(v,i+2,n,dp) ; 
    
    long long int exc = hrRec(v,i+1,n,dp) ;
    
    return dp[i] = max(inc,exc) ;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size() ;
    if (n==1)
        return valueInHouse[0] ;
    
    vector<long long int> dp(n,-1) ;
    // case 1 : 1st element included => 0 <-> n-1
    long long int a = hrRec(valueInHouse,0,n-1,dp) ;
    
    fill(dp.begin(),dp.end(),-1) ;
    
    // case 2 : last element included => 1 <-> n
    long long int b = hrRec(valueInHouse,1,n,dp) ;
    
    return max(a,b) ;
}