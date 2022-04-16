#include <bits/stdc++.h>
using namespace std;
/*
Given: no. of cows , free stalls in an array
find highest minimum distance among the cows
*/

bool isPossible(vector<int> arr, int totalCows, int check) ;

int main(){
    vector<int> arr= {4,2,1,3,6} ;
    int totalcows= 2 ;

    sort(arr.begin(),arr.end() ) ; // { 1 2 3 4 6 }
    // We will plot the number of cows on the number line and hence we take the smallest dist as 0, largest=largest val
    int start=0, end=arr[arr.size() -1] ;
    int ans=-1 ;
    while (start<=end)
    {
        int mid = start + (end-start)/2 ;
        if (isPossible(arr,totalcows,mid))
        {
            ans=mid ;
            start=mid+1 ;
        }
        else 
            end=mid-1 ;
    }
    cout<<ans ;
    return 0 ;
}

bool isPossible(vector<int> arr, int totalCows, int check)
{
    int cowCount=1 ;
    int lastposition = arr[0] ; // putting cow on coordinate axis 0 (coordinate array)

    for (int i=1; i<arr.size(); i++)
    {
        if (arr[i] - lastposition>= check) // if the distance is more than or equal to mid shift to next cow
        {
            cowCount++;
            if (cowCount==totalCows)
                return true ;
            lastposition=arr[i] ;   // New position of the cow
        }
    }
    return false ;
}