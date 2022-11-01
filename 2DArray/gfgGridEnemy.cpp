//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            if (k==0) return n*m;
            vector<int> idx(n);         // NEW FACT, VECTOR IS FASTER THAN UNORDERED_MAP
            vector<int> jdx(m);
            
            
            for (int i=0; i<enemy.size(); i++){         // THE MATRIX IS CUT IS STRAIGHT SLICES, NO BLOCK CAN BE NON-UNIFORM
                int r=enemy[i][0]-1 , c=enemy[i][1]-1 ;
                idx[r]=1;
                jdx[c]=1;
            }
            
            int maxrow=0, row=0;            // IF ONE BLOCK HAS MAX ROWS, THEN ALL THE BLOCK IS THE ADJACENT COLUMN WILL HAVE MAXM ROW
            for (int i=0; i<n; i++)
            {
                row++;
                if (idx[i]==1) row=0;
                maxrow=max(maxrow,row) ;
            }
            
            int maxcol=0, col=0;
            for (int j=0; j<m; j++)         // SAME FOR COLUMS
            {
                col++;
                if (jdx[j]==1) col=0;
                maxcol=max(maxcol,col) ;
            }
            
            return maxcol*maxrow;
        }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends