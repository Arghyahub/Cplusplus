#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void maxdist(vector<int> arr, int s, int e , int maxcows, int &ans) 
{
    if (s>e)
        return ;
    int mid=s+(e-s)/2 ;
    int cowcount=1 ;
    int lastpos=arr[0] ;
    for (int i=1; i<arr.size(); i++)
    {
        if (arr[i]-lastpos>=mid)
        {
            cowcount++ ;
            lastpos=arr[i] ;
            if (cowcount==maxcows)
            {
                ans=mid ;
                maxdist(arr,mid+1,e,maxcows,ans) ;
            }
        }
    }
    if (cowcount<maxcows)
        maxdist(arr,s,mid-1,maxcows,ans) ;

}
int main(){
    vector<int> arr={0,4,3,7,10,9} /*{0,3,4,7,10,9} {1,2,3}  {4,2,1,3,6}*/ ;
    int cows=3 ;
    sort(arr.begin(),arr.end()) ;
    int low=arr[0] , high=arr[arr.size()-1] ,ans=-1;

    maxdist(arr,low,high,cows,ans) ;

    cout<<endl<<ans<<endl;

    return 0 ;
}