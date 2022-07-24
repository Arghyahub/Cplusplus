//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {       // N ARRY MEANS ONE NODE CAN HAVE N CHILD NODES
        
        unordered_map<int,stack<int>> mp ;   // FOR EACH NODE WE WILL STORE ITS CHILD NODES IN STACK (TO ACCESS IT IN REVERSE DIRECTION)
        
        for (int i=0; i<2*e; i+=2)      
        {
            int node = A[i] ;
            int conn = A[i+1] ;
            mp[node].push(conn) ;       // STORE CONNECTION TO STACK
        }
        
        auto it = mp.begin() ;
        
        for (int i=0; i<2*e; i+=2)
        {
            int Bnode = B[i] ;
            int Bconn = B[i+1] ;
            
            if (mp[Bnode].top() != Bconn )      //  CHECK NODE IN REVERSE
                return 0 ;
            mp[Bnode].pop() ;
        }
        return 1 ;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends