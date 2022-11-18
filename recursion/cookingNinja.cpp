#include<bits/stdc++.h>
using namespace std;
void cooktime(int s, int e, vector<int> &rank, int maxDish, int &ans)
{
    if (s>e)
        return ;
    
    int mid = s+(e-s)/2 ;

    int dish=0;
    for (int r : rank){
        int mul=1,time=0 ;

        while (time + r*mul <= mid ){
            time+=r*mul ;
            mul++;
            dish++;
        }
    }
    
    if (dish>=maxDish){
        ans=mid;
        cooktime(s,mid-1,rank,maxDish,ans) ;
    }
    else
        cooktime(mid+1,e,rank,maxDish,ans) ;
}
int main(){
    vector<int> rank = {1,2,3,4} ;
    int numDishes = 11;
    int ans=-1;
    int maxTime = 1*(11*(11+1)/2) ;
    cooktime(0,maxTime,rank,numDishes,ans) ;

    cout<<ans<<endl;

    return 0 ;
}