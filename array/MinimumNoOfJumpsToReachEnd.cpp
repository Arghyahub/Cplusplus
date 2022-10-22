//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if (n<=1) return 0;
        if (arr[0]==0) return -1;
        int farthestdist = arr[0] ;         // THE MAX YOU CAN GO RN IS ARR[0]
        int steps=arr[0] ;                  // THATS ALSO EQUAL TO THE NUMBER OF STEPS YOU CAN TAKE
        int jumps=1;                        
        
        for (int i=1; i<n; i++){
            if (i==n-1) return jumps;       // IF YOU HAVE REACHED LAST INDEX THAT MEANS ITS POSSIBLE
            farthestdist=max(farthestdist , arr[i] + i ) ;      // KEEP CHECKING IN BETWEEN THE ELEMENTS IF SOME ELEMENT CAN INCREASE THE POSSIBILITY TO GO FURTHER
            steps--;        // DECREASE THE STEPS 
            
            if (steps==0){          
                jumps++;        // IF YOU HAVE EXHAUSTED THE NUMBER OF STEPS THAT MEANS, IF FARTHEST IS NOT EQUAL TO CURRENT INDEX, YOU WILL TAKE ANOTHER JUMP
                
                if (i>=farthestdist)    // SAY FARTHEST IS EQUAL TO THE CURRENT INDEX,; THIS IS YOU LAST STEP, YOU CAN MOVE FORWARD; THIS IS WHAT FARTHEST CAN GO UPTO, AND ITS NOT THE LAST INDEX
                    return -1;
                
                steps=farthestdist-i;       // UPDATE STEPS, SOME MIDDLE ELEMENT BETWEEN YOUR INITIAL ELEMENT AND FINAL STEP HAS CONTRIBUTED TO THE FARTHEST YOU CAN GO,
                /**
                 * SAY ARRAY = [2,3,0,0,1]
                 * FROM 2 YOU CAN GO UPTO 3 AND 0
                 * 0 IS THE FARTHEST YOU CAN GO AS PER 2 BUT IF YOU TOOK ONLY 1 STEP, THAT IS 2->3
                 * YOU COULD HAVE TRAVELED TO THE LAST INDEX, THAT IS THE MIDDLE ELEMENT 2->"3"->0 HAS NOW CONTRIBUTED TO YOU FARTHEST
                 */
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends