class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> pref;
		// Take the prifix of all the elements if prefix is repeated then there exists a sub array which makes sum=0 : Add that
        pref[0]=1; // say a number is divisible by k, then its modulo will be equal to 0, then we need to add that, so add 0 to the map previously
        int sum=0 , ans=0, n=nums.size();
        for (int i=0; i<n; i++){
            sum+=nums[i] ;
            int x = sum%k;
            if (x<0) x+=k;
            ans+= pref[x] ;
            pref[x]++;
        }
        return ans;
    }
};
