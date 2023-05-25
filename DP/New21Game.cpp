// the score should be in between k and n
// You can pickup cards from 1 to maxpts
class Solution {
    vector<double> dp;
    double solve(int n, int k, int maxPts, int score) {
        if (score>=k){
            if (score<=n) return 1;
            return 0;
        }
        if (dp[score]!=-1)
            return dp[score] ;
        double ans = 0;
        for (int i=1; i<=maxPts; i++){
            ans+=solve(n,k,maxPts,score+i) ;
        }
        ans = ans/(double)maxPts;
        return dp[score] = ans;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        dp.resize(k+1,-1) ;
        return solve(n,k,maxPts,0) ;
    }
};
