#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/codestudio/problem-details/cooking-ninjas_1164174
/*N=4,ranks=[1, 2, 3, 4] and ‘M’ = 11 dishes.minimum timeto cook 11 dishes will be 12 minutes.
Cook-0 prepare 4 dishes in 10 minutes i.e (1 dish in 1 minute, 1 more dish in next 2 minutes, 1 more dish in next 3 minutes, 1 more dish in next 4 minutes).
Cook-1 prepare 3 dishes in 12 minutes i.e (1 dish in 2 minutes, 1 more dish in 4 minutes, 1 more dish in 6 minutes).
Cook-2 prepare 2 dishes in 9 minutes i.e (1 dish in 3 minutes, 1 more dish in the next 6 minutes).
Cook-3 prepare 2 dishes in 12 minutes i.e (1 dish in 4 minutes, 1 more dish in the next 8 minutes).
If all four cooks work simultaneously then they can prepare(4 + 3 + 2 + 2 = 11) dishes in 12 minutes. And it is the minimum possible time.*/
bool ispossible (vector<int> arr,int size,int numDishes, int totalTime) ;
int main(){
    vector<int> rank;
    int size,numDishes ;
    cin>>size>>numDishes ;
    int small=INT_MAX ;
    for (int i=0; i<size; i++)
    {
        int x;
        cin>>x;
        rank.push_back(x) ;
        small=min(small,x) ;
    }
    int end = small*numDishes*(numDishes+1)/2 , start=0;
    /* the largest time it could take is to use the smallest rank multiple time (here 1)
    so max time = r*1 + r*2 + r*3 ... = r(1+2+3+4+...) = r*n*(n+1)/2 ;
    */
    int ans =-1;

    while (start<=end )
    {
        int mid = start + (end-start)/2 ;
        
        if (ispossible(rank,size,numDishes,mid))
        {
            ans=mid ;
            end=mid-1 ;
        }
        else
            start=mid+1 ;
    }

    cout<<ans ;
    return 0 ;
}

bool ispossible (vector<int> arr,int size,int numDishes, int totalTime)
{
    int dish=0 ;
    for (int r : arr)
    {
        int mul=1 ; // keeps multiplying 1,2,3...
        int time = 0 ;  // checks if the time doesn't exceed totalTime
        while (time<=totalTime)
        {
            if (time+r*mul<=totalTime )
            {
                dish++ ;
                if (dish>=numDishes) {return true ;}  // If num of dishesh exceed
                time+=r*mul ;                       // store the ans and pull end back
                mul++ ;                            // for a more optimised ans
            }
            else {break ; }
        }
    }
    return false ; // If it can't reach total time the mid value is too small
                  // in such less time total dishes can't be made, Pull start forward ;
}

