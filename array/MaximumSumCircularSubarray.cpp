class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
			// To Find max sum curcular array you can deduct min sum subarray
        int sum=0 , maxelem=nums[0], n=nums.size() ;
        for(int i=0; i<n; i++){
            sum+=nums[i] ;
            maxelem=max(maxelem,nums[i]) ;
        }

        int maxm=0, straight=INT_MIN;

        int minm=0 , wrap=INT_MAX ;
        for (int i=0; i<n; i++){
            if (maxm<0) maxm=0;
            maxm+=nums[i] ;
            straight=max(straight,maxm) ;

            if (minm>0) minm=0;
            minm+=nums[i] ;
            wrap=min(wrap,minm) ;
        }

        if (max(straight,sum-wrap)==0)
            return maxelem;
        
        return max({straight,sum-wrap,maxelem}) ;
    }
};
