#include<iostream>
#include<vector>
using namespace std;
void forwardIndex(vector<int> hist , vector<int> &forw , int n)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n+1 ; j++)
            if (hist[j]<hist[i])
            {
                forw.push_back(j) ;
                break ;
            }
}
void backwardIndex(vector<int> hist , vector<int> &backw, int n)
{
    for (int i=0; i<n; i++)
    {
        bool check= true ;
        for (int j=i; j>=0 ; j--)
            if (hist[j]<hist[i])
            {
                check = false ;
                backw.push_back(j) ;
                break ;
            }
        if (check) backw.push_back(-1) ;
    }
}
int main(){
    vector<int> hist= {2,1,5,6,2,3};
    int area=-1 , n=hist.size();
    vector<int> forw , backw ;
    hist.push_back(-1) ;
    
    forwardIndex(hist,forw,n) ;
    backwardIndex(hist,backw,n) ;


    for (int i=0; i<n; i++)
    {
        int temp = hist[i] * (forw[i] - backw[i] -1 ) ;
        area=max(area,temp) ;
    }

    cout<<"\n Area is : "<<area ;
    return 0 ;
}