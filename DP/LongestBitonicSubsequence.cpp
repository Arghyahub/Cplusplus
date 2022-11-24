class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size() ;
	    vector<int> before(n,1) ;
	    vector<int> after(n,1) ;
	    
	    for (int i=0; i<n; i++){
	        int cnt = 1;
	        for (int j=i-1; j>=0; j--){
	            if (nums[j]<nums[i])
	                cnt = max(cnt,before[j]+1) ;
	        }
	        before[i] = cnt;
	    }
	    
	    for (int i=n-1; i>=0; i--){
	        int cnt = 0;
	        for (int j=i+1; j<n; j++){
	            if (nums[j]<nums[i])
	                cnt = max(cnt,1+after[j]) ;
	        }
	        after[i] = cnt;
	    }
	    
	    int ans = 1;
	    
	    for (int i=0; i<n; i++)
	        ans = max( ans , after[i]+before[i] ) ;
	    return ans;
	}
};