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
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int pet=0 , front=0 , rear =0 ;
       while (rear==front || (rear!=front && rear%n!=front) ){
           
           if (p[rear%n].petrol - p[rear%n].distance + pet >= 0){
               pet+= p[rear%n].petrol - p[rear%n].distance ;
               rear++ ;
           }
           else{
               rear++ ;
               front=rear;   // if the previous elements were not able to donate enough petrol starting from middle wont help
               pet = 0 ;     // so start fron the point were you got the negative
           }
           
           if (front >= n)
            return -1 ;
       }
       return front ;
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