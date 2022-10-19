
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1) ;
        stack<int> st ;
        int area = -1 ;
        for (int i=0; i<heights.size(); i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()] )
            {
                int bignum = heights[st.top()] ;
                st.pop() ;
                int prevsmall = st.empty()? -1 : st.top() ;
                int width = i - prevsmall -1 ;
                area = max(area, width*bignum) ;
            }
            st.push(i) ;
        }
        return area ;
    }
};

