// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  private:
    int maxrectangle(int *arr, int n)
    {
        stack<int> st ;
        int area = 0 ;
        for (int i=0; i<=n; i++)
        {
            if (i==n)
            {
                while (!st.empty() && arr[st.top()] > -1 )
                {
                    int big = arr[st.top()] ; st.pop() ;
                    int small = st.empty()? -1: st.top() ;
                    int width = i - small -1 ;
                    area = max(area,big*width) ;
                }
            }
            else{
                while (!st.empty() && arr[st.top()] > arr[i] )
                {
                    int big = arr[st.top()] ; st.pop() ;
                    int small = st.empty()? -1: st.top() ;
                    int width = i - small -1 ;
                    area = max(area,big*width) ;
                }
                st.push(i) ;
            }
        }
        return area ;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans=maxrectangle(M[0],m) ;
        
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (M[i][j]!=0)
                    M[i][j] = M[i][j] + M[i-1][j] ;
            }
            ans = max(ans, maxrectangle(M[i],m)) ;
            
        }
        return ans ;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends