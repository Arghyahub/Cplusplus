#include <bits/stdc++.h> 

long long int hRec(vector<int>& v,long long int n, long long int i,bool check)
{
    if (i>=n)
        return 0 ;
    if (i==n-1 && check==true)
        return 0 ;
    
    long long int inc = 0 ;
    if (i==0){
        inc = v[i] + hRec(v,n,i+2,true) ;
    }
    else
        inc = v[i] + hRec(v,n,i+2,check) ;
    
    long long int exc = hRec(v,n,i+1,check) ;
    
    return max(inc,exc) ;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size() ;
    return hRec(valueInHouse,n,0,false) ;
}