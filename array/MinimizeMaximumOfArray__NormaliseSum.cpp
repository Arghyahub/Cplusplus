class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long N=nums.size() , sum=nums[0] , ans=nums[0] ; // As we can't select 0th num, lets consider it to be maximum

        for (int i=1; i<N; i++){
            sum+=nums[i] ;
            long long k;	// Take the floor value of the sum equally divided among the left array
            if (sum%(i+1)==0)
                k=sum/(i+1) ;
            else
                k=sum/(i+1) + 1; 
            ans = max(ans, k ) ;	// Its not possible to equally divide numbers to all, thus we take to maximum to avoid false hope
        }

        return ans;
    }
};
