#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;
/* 
An array will be given having number of pages books have and number of students will be given
Distribute the books so that every student gets a book and the maximum number of pages for student be minimum
*/

bool isPossible(vector<int> arr, int check, int students)
{
    int s=1;
    int count = 0 ;
    for (int i=0 ; i<arr.size(); i++)
    {
        if (count + arr[i] <= check)
            count+=arr[i] ;
        
        else 
        {
            if (s==students)
                return false ;
            else
            {
                s++ ;
                count=arr[i] ;
            }
        }
    }
    return true ;
}


int main()
{
    vector<int> arr = {10,20,30,40} ;
    int students=2 ;
    // since each students will get a book the lowest a book can be assignes should be the start
    // And we will add up the entire array so the maximum numbers of pages will be somewhere near total no. of pages
    int start=arr[0], end=arr[0];
    
    for (int i=1; i<arr.size() ; i++)
    {
        end+=arr[i] ;
        start=min(arr[i],start) ;
    }

    int ans =-1 ;
    while (start<=end)
    {
        int mid = start + (end-start)/2 ;
        
        if (isPossible(arr,mid,students))
        {
            ans=mid ;
            end=mid-1 ;
        }

        else
            start=mid+1 ;
    }

    cout<<"\nThe smallest possible maximum number of pages is : "<<ans<<endl ;
    return 0 ;
}
