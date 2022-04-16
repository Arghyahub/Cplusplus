#include<iostream>
using namespace std;
/*Given you have N no. of stairs you can only take 1 step or 2 step at a time
How many ways you can reach the top stair
eg n=3
{1,1,1} , {2,1} , {1,2}
ans=3 ways */

int recur(int n)
{
    if (n==0)
        return 1 ;
    else if (n<0)
        return 0 ;
    else 
        return recur(n-1) + recur(n-2) ;   // keep asking yourself if i have climbed 1 or 2 step : How many are left
}                                         // if left==0 then Thats a correct way do +1 
int main(){
    int n;
    cin>>n;
    int noOfWays=recur(n) ;
    cout<<"\nNo of ways : "<<noOfWays ;
    return 0 ;
}