class Solution {
private:
    void nxsmall(vector<int> &arr , vector<int> &ans, int n)
    {
        stack<int> st;
        st.push(-1) ;
        for (int i=n-1; i>=0; i--)
        {
            while( st.top()!=-1 && arr[st.top()] >= arr[i] )
            {
                st.pop() ;
            }
            ans[i] = st.top() ;
            st.push(i) ;
        }
    }
    void pvsmall(vector<int> &arr , vector<int> &ans, int n)
    {
        stack<int> st;
        st.push(-1) ;
        for (int i=0; i<n; i++)
        {
            while( st.top()!=-1 && arr[st.top()] >= arr[i] )
            {
                st.pop() ;
            }
            ans[i] = st.top() ;
            st.push(i) ;
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() ;
        vector<int> nextsmall(n,0) ;
        vector<int> prevsmall(n,0) ;
        
        nxsmall(heights,nextsmall,n) ;
        pvsmall(heights,prevsmall,n) ;
        int ans = INT_MIN ;
        
        for (int i=0; i<n; i++)
        {
            if (nextsmall[i]==-1)
                nextsmall[i]=n ;
            int l = nextsmall[i] - prevsmall[i] -1 ;
            int area = l*heights[i] ;
            ans = max(ans,area) ;
        }
        
        return ans ;
    }
};