class Solution {
    void getSubs(vector<int> &nums, int &ans, int temp, int index, int prev )
    {
        if (index==nums.size()){
            ans = max(ans,temp) ;
            return ;
        }
        
        // include if greater
        if ( nums[index] > prev ){
            getSubs(nums,ans,temp+1,index+1,nums[index]) ;
        }
        
        // exclude
        getSubs(nums,ans,temp,index+1,prev) ;
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0 ;
        
        getSubs(nums,ans,0,0,INT_MIN) ;
        return ans ;
    }
};