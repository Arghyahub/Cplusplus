#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int func(vector<int> arr , int n)
    {
        int s=0, e=arr.size()-1 ;
        int ans = 0 ;
        while (s<=e)
        {
            int mid=s+(e-s)/2 ;
            if (arr[mid]<n){
                s=mid+1 ;
                ans=mid+1 ;
            }
            else
                e=mid-1 ;
        }
        return ans ;
    }

int main(){
    vector<vector<int>> matrix=  {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}} ;
    int r=matrix.size() ,c=matrix[0].size() ;
    int mini=INT_MAX, maxi=INT_MIN ;
    for (int i=0; i<r; i++)
    {
        mini=min(mini,matrix[i][0]) ;
        maxi=max(maxi,matrix[i][c-1]) ;
    }

    int ans=0 ;
    while (mini<=maxi)
    {
        int mid=mini+(maxi-mini)/2 ;
        int occur=0 ;
        for (int i=0; i<r; i++)
            occur+=func(matrix[i],mid) ; // finding number of occurrences
        
        if (occur>r*c/2)
            maxi=mid-1 ;
        else
        {
            ans=mid ;
            mini=mid+1 ;
        }
    }
    cout<<"Answer is : "<<ans ;
    return 0 ;
}