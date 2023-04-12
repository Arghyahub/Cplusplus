class Solution {
    int possible(vector<int>& nums, int maxi){
        // 1 2 2 4
        int ans = 0;
        for (int i=0; i<nums.size()-1;){
            if (abs(nums[i]-nums[i+1])<=maxi){
                ans++;
                i+=2;
            }
            else
                i++;
        }
        return ans;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        int N = nums.size() ;
        sort(nums.begin(),nums.end()) ;
        int s = 0 , e = nums[N-1] , ans=0;
        while (s<=e){
            int mid = s + (e-s)/2 ;
            if (possible(nums,mid) >= p){
                ans = mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};
