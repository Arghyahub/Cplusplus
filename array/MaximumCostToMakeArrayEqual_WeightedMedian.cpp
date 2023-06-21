#define ll long long
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<ll,ll> > zip(nums.size());
        for (int i=0; i<nums.size(); i++)
            zip[i] = {nums[i],cost[i]} ;
        
        sort(zip.begin(),zip.end()) ;
        ll sum = 0 ;
        for (int i=0; i<cost.size(); i++) sum+=(ll)cost[i] ;
        ll median = -1;
        ll currsum = 0;
		// say 1 has a cost of 3 we can say there are three 1's with cost of 3
		// Now we can lay them on a number line and choose the median
        while (currsum < (sum+1)/2 ){
            median++;
            currsum += zip[median].second ;
        }

        ll ans = 0;
        for (int i=0; i<nums.size(); i++){ // Ans is to move every number to the median
            ans += abs(zip[i].first - zip[median].first)*zip[i].second;
        }

        return ans;
    }
};
