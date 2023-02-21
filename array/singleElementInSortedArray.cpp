class Solution {
    bool even(int n){
        return !(n&1) ;
    }
	// If no element is inserted before then the odd index and even index element should be same
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() ;
        if (n==1 || nums[0]!=nums[1]) return nums[0] ;
        if (nums[n-1]!=nums[n-2]) return nums[n-1] ;
        int part = n/2;

        int s = 1 , e =n-2;
        while (s<=e){
            int mid = s+(e-s)/2;
            if (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid] ;
            if ((even(mid) && nums[mid]==nums[mid+1]) || (mid&1 && nums[mid]==nums[mid-1]))
                s=mid+1;
            else
                e=mid-1;
        }
        return nums[n-1] ;
    }
};
