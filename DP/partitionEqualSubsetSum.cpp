class Solution {
    bool solve(vector<int>& nums, int i, int total,int sum)
    {
        if (i==0){
            sum+=nums[i] ;
            if (total-sum == sum)
                return true;
            return false;
        }
        
        //inc
        bool inc = solve(nums,i-1,total,sum+nums[i]) ;
        
        //exc
        bool exc = solve(nums,i-1,total,sum) ;
        
        return (inc || exc) ;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int total = 0 , n = nums.size();
        for (int i=0; i<n; i++)
            total+=nums[i] ;

        
        return solve(nums,n-1,total,0) ;
    }
};
