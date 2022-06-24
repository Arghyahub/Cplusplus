// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
    private:
    bool checkJourney(petrolPump *p, int i, int n)
    {
        int j=i , petrol=0 ;
        do
        {
            petrol += p[i%n].petrol - p[i%n].distance ;
            i++ ;
            if (petrol<0)
                return false ;
        } while (i%n != j) ;
        return true ;
    }
    
    public:
    
    
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       for (int i=0; i<n; i++)
       {
            if ( p[i].petrol < p[i].distance)
                continue ;
            else
            {
                if (checkJourney( p , i, n  ))
                    return i ;
            }
       }
       return -1 ;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends