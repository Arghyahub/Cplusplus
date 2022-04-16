#include<iostream>
#include<vector>
using namespace std;
void getmax(vector<int> arr,int s, int e, int maxstu, int &ans)
{
    if (s>e)
        return ;
    int mid=s+(e-s)/2 , PageCount=arr[0] , SCount=1;

    for (int i=1; i<arr.size(); i++)
    {
        if (PageCount+arr[i]<=mid)
        {
            PageCount+=arr[i] ;
        }
        else
        {
            SCount++ ;
            PageCount=arr[i] ;
            if (SCount>maxstu)
            {
                return getmax(arr,mid+1,e,maxstu,ans) ;
            }
        }
    }
    if (SCount<=maxstu)
    {
        ans=mid ;
        return getmax(arr,s,mid-1,maxstu,ans) ;
    }
}
int main(){
    vector<int> arr = {10,20,30,40} ;
    int students=2 ,ans=-1;
    // given : array is already sorted , & a student should get atleast one book
    int low=arr[0] ,high=0;
    for (int i : arr)
        high+=i ;
    getmax(arr,low,high,students,ans) ;

    cout<<endl<<ans<<endl ;
    return 0 ;
}