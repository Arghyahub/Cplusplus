class Solution {

    bool solve(vector<int>& quantity,unordered_map<int,int> &cnt,int ind)
    {
        if (ind == quantity.size())
            return true;
        
        for (auto it : cnt){
            int elem = it.first , freq = it.second;
            if (freq >= quantity[ind]){
                // decrease len , and add number of left len to map
                cnt[elem] = freq - quantity[ind] ;

                bool checkFuture = solve(quantity,cnt,ind+1) ;
                if (checkFuture){
                    return true;
                }

                // BT
                cnt[elem] = freq ;
            }
        }
        return false;
    }

public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> cnt;
        for (int i=0; i<nums.size(); i++)
            cnt[nums[i]] ++ ;
        
        sort(quantity.begin(),quantity.end(),greater<int>()) ;

        return solve(quantity,cnt,0) ;
    }
};
