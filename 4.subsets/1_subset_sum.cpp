/*
90. Subsets II
https://leetcode.com/problems/subsets-ii/description/
*/

class Solution {
    vector<vector<int>> ans;
    vector<int> tmp;
public:
    void solve(vector<int>& nums, int i){
        ans.push_back(tmp);
        for (int j=i; j<nums.size(); j++){
            if (j!=i && nums[j]==nums[j-1]) continue;
            tmp.push_back(nums[j]);
            solve(nums,j+1);
            tmp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(nums,0);
        return ans;
    }
};
