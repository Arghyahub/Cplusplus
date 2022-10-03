#include <bits/stdc++.h> 

long long int hrRec(vector<int>& nums)
{
    int n = nums.size() ;
    long int f = nums[0] ;
    long int s = max(nums[0],nums[1]) ;
    
    for (int i=2; i<n; i++)
    {
        long long int ans = max(nums[i]+f,s) ;
        f = s;
        s = ans ;
    }
    return s ;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size() ;
    if (n==1)
        return valueInHouse[0] ;
    
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