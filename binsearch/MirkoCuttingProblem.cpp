#include<iostream>
#include<vector>
#include<climits>
#include <algorithm>
using namespace std;

// https://www.spoj.com/problems/EKO/

int isPossible(vector<int>,int,int,int) ;
int main(){
    int size, required ;
    cin>>size>>required;
    vector<int> arr ;

    int start = INT_MAX, end = -1 ;

    for (int i=0; i<size; i++)
    {
        int x;
        cin>>x;
        start=min(start,x) ;
        end=max(end,x) ;
        arr.push_back(x);
    }
    int ans ;
    while (start<=end)
    {
        int mid = start + (end-start)/2 ;
        int x = ( isPossible(arr,size,mid,required) ) ;

        if (x == 0)
        {
            ans=mid ;
            break;
        }
        else if (x==-1)
        {
            start=mid+1 ;
        }
        else
        {
            ans=mid ;
            end=mid-1 ;
        }
    }
    cout<<ans ;
    return 0 ;
}

int isPossible(vector<int> arr,int size, int setting, int required ) 
{
    int cutdown=0;
    for (int i : arr)
    {
        if (i>setting)
            cutdown+=i-setting ;
    }
    
    if (required==cutdown)
        return 0;
    else if (cutdown>required)
        return -1 ;
    else 
        return 1 ;
}