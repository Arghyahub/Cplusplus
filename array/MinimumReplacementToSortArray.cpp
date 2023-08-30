class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int N = nums.size() ;
        long long ans = 0;
        int minmaxNum = nums[N-1] ;
        for (int i=N-2; i>=0; i--) {
            long long parts = ceil((double)nums[i]/(double)minmaxNum) ;
            ans += parts-1 ;
			// Spread out the number by dividing into parts
            minmaxNum = nums[i]/parts;
        }
        return ans;
    }
};
