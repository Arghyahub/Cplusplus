// Stores previous date as a parameter to judge if we need to buy a ticket
class Solution {
    vector<int> cst = {1,7,30} ;
    vector<vector<int>> dp;
    int solve(vector<int>& days, vector<int>& costs,int i, int lim){
        if (i==days.size())
            return 0;
        
        if (dp[i][lim]!=-1)
            return dp[i][lim] ;
        
        int inc=INT_MAX , exc = INT_MAX ;
        if (lim<days[i]){
            for (int j=0; j<3; j++){
                int tmp = solve(days,costs,i+1,days[i]+cst[j]-1) ;
                if (tmp!=INT_MAX)
                    inc = min(inc , tmp + costs[j] ) ;
            }
        }
        else{
            exc = solve(days,costs,i+1,lim) ;
        }

        return dp[i][lim] = min(inc,exc) ;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(365,vector<int>(365+30,-1)) ;
        return solve(days,costs,0,0) ;
    }
};
