class Solution {
    int getSubs(vector<int> &nums, int temp, int index, int prev )
    {
        if (index==nums.size()){
            return 0 ;
        }
        // include if greater
        int include = 0 ;
        if ( nums[index] > prev ){
            include = 1 + getSubs(nums,temp+1,index+1,nums[index]) ;
        }
        
        // exclude
        int exclude = getSubs(nums,temp,index+1,prev) ;
        
        return max(include,exclude) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        return getSubs(nums,0,0,INT_MIN) ;
    }
};