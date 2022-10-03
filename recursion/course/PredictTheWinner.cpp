class Solution {
    int solve(vector<int>& nums, int s, int e)
    {
        if (s>e)
            return 0 ;
        
        // 1. include first
        // case a : player 2 chooses from start
        int a = nums[s] + solve(nums,s+2,e) ;
        // case b : player 2 chooses from end
        int b = nums[s] + solve(nums,s+1,e-1) ;
        
        // include last
        // case a : player 2 chooses from start
        int c = nums[e] + solve(nums,s+1,e-1) ;
        // case b : player 2 chooses from end
        int d = nums[e] + solve(nums,s,e-2) ;
        
        return max(min(a,b),min(c,d)) ;     // Player 2 will want player 1 to get the lowest score thats why minm
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n==0) return true;
        int p1 = solve(nums,0,n) ;
        int p2 = 0 ;
        for (int i=0; i<=n; i++)
            p2+=nums[i] ;
        p2-=p1;
        
        // cout<<p1<<" "<<p2 ;
        
        if (p1>=p2) return true;
        return false;
    }
};