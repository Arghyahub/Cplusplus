
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {        // WE WILL PLAY WITH INDEXES HERE, BECAUSE INDEX WILL GIVE US THE WIDTH
        heights.push_back(-1) ;
        stack<int> st ;
        int area = -1 ;
        for (int i=0; i<heights.size(); i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()] )   // THE INCOMING ELEMENT IS SMALLER THAN PREV ELEMENT, .:. PREV ELEMENT IS A HILL
            {
                int bignum = heights[st.top()] ;
                st.pop() ;
                int prev_i = st.empty()? -1 : st.top() ;
                int width = i - prev_i -1 ;     // SAY 0th ELEMENT IS A HILL,THEN WE GET PREV_I=-1, THE WIDTH SHOULD BE EQUAL TO 1, SO 0-1+(1) WILL GIVE 1
                area = max(area, width*bignum) ;
            }
            st.push(i) ;
        }
        return area ;
    }
};

