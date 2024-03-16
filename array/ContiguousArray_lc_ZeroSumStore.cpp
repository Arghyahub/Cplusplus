class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size() ;
        for (int i=0; i<N; i++)
            nums[i] = (nums[i]==1)? 1:-1;
        
        unordered_map<int,int> lastSum;
        lastSum[0] = -1;
        int sum = 0, ans = 0;
        for (int i=0; i<N; i++){
            sum+=nums[i];
            if (lastSum.find(sum)==lastSum.end())
                lastSum[sum] = i;

            ans = max(ans,i-lastSum[sum]) ;
        }
        return ans;
    }
};
