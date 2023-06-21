#define ll long long
class Solution {
    ll binsh(vector<int>& nums, vector<int>& cost, int mid){
        ll pay = 0;
        for (int i=0; i<nums.size(); i++)
            pay+= 1LL * abs(nums[i]-mid)*cost[i] ;
        return pay;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll s = 0 , e = 1e6 , ans = 0;
        while (s<=e){
            ll mid = s + (e-s)/2 ;
            ll x = binsh(nums,cost,mid) ;
            ll xplus1 = binsh(nums,cost,mid+1) ;
            if (x > xplus1){
                ans = xplus1;
                s = mid+1;
            }
            else {
                ans = x;
                e = mid-1;
            }
        }
        return ans;
    }
};
