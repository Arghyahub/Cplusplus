//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int asci(char ch,char *x, int n, int *b)
    {
        for (int i=0; i<n; i++)
            if (x[i]==ch)
                return b[i] ;
        int m = ch ;
        return m ;
    }
public:
    /**
     *  Q. Find substring with maximum sum of ASCII code
     *      ASCII value of sum characters(array x[]) are changed(array b[])
     *      like x[]={'c'} , b[] = {-100} 
     *      ans return the substring
     */
    string maxSum(string w,char x[], int b[],int n){ // Use two variable one to keep the track of current sumtillEnd and other for maximum
        int maxi=INT_MIN, maxToEnd = 0, start=0, end=0 , s=0 ;
        for (int i=0; i<w.size(); i++){
            maxToEnd += asci(w[i],x,n,b) ;      // KEEP ADDING TO MAXTOEND
            if (maxi<maxToEnd){                 // IF STORED SUM IS LESS THAN UPDATE THE STORED SUM
                maxi = maxToEnd;
                start = s;                      // OKAY, WE CAN STORE THE STARTING INDEX
                end = i ;
            }
            
            if (maxToEnd<0){        // IF THE SUM IS LESSER THAN 0, IT DOESN'T MATTER TO INCLUDE THE PREVIOUS PORTION
                maxToEnd = 0 ;      // WE CAN HAVE A NEW START FROM THE NEXT INDEX
                s=i+1 ;             // STORE NEXT INDEX, AS IT CAN BE THE BEGINNING OF THE NEXT BIG SUM
            }
        }
        return w.substr(start,end-start+1) ;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends