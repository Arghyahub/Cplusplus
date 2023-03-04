class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minindx=-1 , maxindx=-1 , leftbound=-1;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]<minK || nums[i]>maxK) leftbound=i;
            if (nums[i]==minK) minindx=i;
            if (nums[i]==maxK) maxindx=i;
            ans += max(0, min(minindx,maxindx) - leftbound ) ;
        }
        return ans;
    }
};
