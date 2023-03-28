class Solution {
    vector<int> dp;
    int solve(vector<int>& days, vector<int>& costs, int i){
        if (i==days.size())
            return 0;
        
        if (dp[i]!=-1)
            return dp[i] ;
        
        int one = costs[0] + solve(days,costs,i+1) ;
        int sevInd = i;
        while (sevInd<days.size() && days[sevInd]<days[i]+7) sevInd++;
        int seven = costs[1] + solve(days,costs,sevInd) ;

        while (sevInd<days.size() && days[sevInd]<days[i]+30) sevInd++;   // 30 days
        int thirty = costs[2] + solve(days,costs,sevInd) ;

        return dp[i] =  min({one,seven,thirty}) ;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1) ;
        return solve(days,costs,0) ;
    }
};
