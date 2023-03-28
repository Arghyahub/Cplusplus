class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,0) ;
        for (int i=days.size()-1; i>=0; i--){
            int one = costs[0] + dp[i+1] ;
            int sevInd = i;
            while (sevInd<days.size() && days[sevInd]<days[i]+7) sevInd++;
            int seven = costs[1] + dp[sevInd] ;

            while (sevInd<days.size() && days[sevInd]<days[i]+30) sevInd++;   // 30 days
            int thirty = costs[2] + dp[sevInd] ;

            dp[i] =  min({one,seven,thirty}) ;
        }
        return dp[0] ;
    }
};
