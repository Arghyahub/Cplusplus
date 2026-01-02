/*
https://leetcode.com/problems/combination-sum-ii/description/
*/
class Solution {
    vector<vector<int>> ans;
    vector<int> tmp;
    void solve(vector<int> &nums, int leftSum, int idx){
        if (leftSum==0){
            ans.push_back(tmp);
            return;
        }
        if (leftSum<0 || idx>=nums.size()) return;

        for (int i=idx; i<nums.size(); i++){
            if (i!=idx && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            solve(nums,leftSum-nums[i],i+1);
            tmp.pop_back();
        }
    }
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            solve(candidates,target,0);
            return ans;
        }
    };
