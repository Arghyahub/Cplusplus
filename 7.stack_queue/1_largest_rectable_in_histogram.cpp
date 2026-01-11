/*
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector<int> left(N,-1);
        vector<int> right(N,-1);
        stack<int> st;

        for (int i=0; i<N; i++){
            int val = -1;
            while (!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if (!st.empty())
                val = st.top();

            left[i] = val;
            st.push(i);
        }

        st = {};

        for (int i=N-1; i>=0; i--){
            int val = N;
            while (!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if (!st.empty())
                val = st.top();

            right[i] = val;
            st.push(i);
        }

        // For any histogram a bar can be the limiting factor for the entire area
        // Lets consider each bar to be the limiting factor (smallest)
        // Any bar can be the smallest if things on left and right are not smaller

        int ans = 0;
        for (int i=0; i<N; i++){
            int l = left[i], r = right[i];
            // printf("%d * [%d,%d] = %d\n",heights[i],l,r);
            ans = max(ans , (r-l-1)*heights[i]);
        }
        return ans;
    }
};
