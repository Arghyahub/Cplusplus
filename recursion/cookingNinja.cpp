#include<iostream>
#include<vector>
using namespace std;
void cooktime(vector<int> rank,int s, int e, int n,int &ans)
{
    if (s>e)
        return  ;
    int mid = s+(e-s)/2 , mul=1, dish=0;
    for (int i : rank)
    {
        while (i*mul<=mid)
        {
            dish++ ;
            mul++ ;
        }
    }
    if (dish==n)
    {
        ans=mid ;
        return cooktime(rank,s,mid -1,n,ans) ;
    }
    else if (dish<n)
        return cooktime(rank,mid+1,e,n,ans) ;
    else
        return cooktime(rank,s,mid-1,n,ans) ;

}
int main(){
    vector<int> rank;
    int n, numDishes , small=999 , ans=-1;
    cin>>n>>numDishes ;

    for (int i=0; i<n; i++)
    {
        int x;
        cin>>x ;
        small=min(small,x) ;
        rank.push_back(x) ;
    }
    // r*1 + r*2+r*3+r*4+....r*numDishes = r(1+2+3+4+..+numDishesh) = r* (numDishes*(numDishes+1))/2
    int maxtime= small*(numDishes*(numDishes+1))/2 , mintime=0;

    cooktime(rank,mintime,maxtime,numDishes, ans) ;

    cout<<endl<<ans<<endl ;

    return 0 ;
}