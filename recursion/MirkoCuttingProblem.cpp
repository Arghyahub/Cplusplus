#include<iostream>
#include<climits>
using namespace std;
void getDone(int arr[],int size,int s, int e, int req, int &ans)
{
    if (s>e)
        return ;

    int mid = s+(e-s)/2 , cut=0;

    for (int i=0; i<size; i++)
    {
        if (arr[i]>mid)
            cut+=arr[i]-mid ;
    }
    
    if (cut==req)
    {
        ans=mid ;
        return ;
    }
    else if (cut<req)
    {
        ans=mid ;
        return getDone(arr,size,s,mid-1,req,ans) ;
    }
    else
        return getDone(arr,size,mid+1,e,req,ans) ;

}
int main(){
    int n ,m , low=INT_MAX , high=INT_MIN , ans=-1;
    cin>>n>>m ;
    int arr[n]={0} ;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i] ;
        low=min(low,arr[i]) ;
        high=max(high,arr[i]) ;
    }
    
    getDone(arr,n,low,high,m,ans) ;

    cout<<ans ;
    return 0 ;
}