class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end()) ;
        int n = sat.size() ;
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0)) ;
        vector<int> row1(n+1,0) ;
        vector<int> row2(n+1,0) ;
        
        for (int i=n-1; i>=0; i--){
            for (int time=i; time>=0; time--){
                int inc = sat[i]*(time+1) + row1[time+1] ;
                int exc = row1[time] ;
                row2[time] = max(inc,exc) ;
            }
            row1 = row2 ;
        }
        
        return row2[0] ;
    }
};
