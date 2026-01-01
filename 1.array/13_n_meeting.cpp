/*
https://leetcode.com/problems/non-overlapping-intervals/description/

We sort by last value, because we want laps to release early
If you sort by shortest duration it doesn't work because shortest duration can overlap with two bigs
   ____
____  ____

Best is to take the eary ending first then the 3rd one will be free
*/
class Comp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) const {
        return a[1]<b[1];
    }
};
class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end(),Comp());
            // for (auto se : intervals){
            //     printf("[%d,%d] ",se[0],se[1]);
            // }
            int r = intervals[0][0], count=0;
            for (auto se : intervals){
                if (se[0]<r) count++;
                else r = max(r,se[1]);
            }
            return count;
        }
    };
