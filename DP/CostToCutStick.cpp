class Solution {
    vector<vector<int>> dp ;
    int dfs(vector<int>& cuts, int left, int right)
    {
        if (right-left<=1) return 0;    // If they are at a distance <=1 then there are no elements in btwn

        if (dp[left][right]!=-1) return dp[left][right] ;

        int ans = INT_MAX;
        for (int chop=left+1; chop<right; chop++){
            ans = min( ans , cuts[right]-cuts[left] + dfs(cuts,left,chop) + dfs(cuts,chop,right) );
        }
        return dp[left][right] = ans;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        dp.resize(102,vector<int>(102,-1)) ;
        // So we will add two pointers from 0 to n and do dfs in between all the index
        // And we will return the minimum
        cuts.push_back(0) ;
        cuts.push_back(n) ;
        // sort cuts, because we will traverse between an index range
        // And we want to select all cuts between that range
        sort(cuts.begin(),cuts.end()) ; 
        // Say unsorted cuts = [1,3,4,5,0,7] and left=0 right=cuts.size()-1
        // so the ans will be cuts[right]-cuts[left]=6(Not correct) + {get ans betn left and right}
        // getting answer between is another problem,say for value 0, 0 doesn't resides between 1 and 7, so how can we cut it?

        // Now check for Sorted Cuts = [0,1,3,4,5,7] , left=0,right=cuts.size()-1
        // ans = cuts[left]-cuts[right]=7 + {get answer from the range in between}
        // choosing any number say 4 falls btwn 0 and 7 we will get two rods 0-4 and 4-7
        // Thats Why we sort cuts

        return dfs(cuts,0,cuts.size()-1) ;
    }
};
