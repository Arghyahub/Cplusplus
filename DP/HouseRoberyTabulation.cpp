#include <bits/stdc++.h> 

long long int hrRec(vector<int>& nums)
{
    int n = nums.size() ;
    vector<long long int> dp(n,0) ;
    dp[0] = nums[0] ;
    dp[1] = max(nums[0],nums[1]) ;
    
    for (int i=2; i<n; i++)
    {
        dp[i] = max(nums[i]+dp[i-2],dp[i-1]) ;
    }
    return dp[n-1] ;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size() ;
    if (n==1)
        return valueInHouse[0] ;
    
    
    int first = valueInHouse[0] ;
    int last = valueInHouse[n-1] ;
    
    // case 1 : 1st element included => 0 <-> n-1
    valueInHouse.pop_back() ;
    long long int a = hrRec(valueInHouse) ;
    
    // case 2 : last element included => 1 <-> n
    valueInHouse.push_back(last) ;
    valueInHouse.erase(valueInHouse.begin()) ;
    long long int b = hrRec(valueInHouse) ;
    
    return max(a,b) ;
}