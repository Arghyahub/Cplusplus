class Solution {
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& piles, int i, bool A, int M){
        if (i>=piles.size())
            return 0;
        if (M>piles.size())
            M = piles.size() ;
        if (dp[i][A][M]!=-1)
            return dp[i][A][M] ;
        
        int ans = 0 , score = 0 , sum=0;
        if (A){
            for (int j=i; j<i+2*M && j<piles.size(); j++){
                sum+= piles[j] ;	// Keep track of sum
                score = sum + solve(piles,j+1,false,max(M,j+1-i)) ;		// X is not index it is the number of piles picked
                ans = max(ans,score) ;	// Alice will try to maximize her score
            }
        }
        else {
            ans = INT_MAX ;
            for (int j=i; j<i+2*M && j<piles.size(); j++){
                score = solve(piles,j+1,true,max(M,j+1-i)) ;
                ans = min(ans,score) ;	// Bob will try to maximize his score and minimse Alice's score
            }
        }
        return dp[i][A][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int N = piles.size() ;
        dp.resize(N,vector<vector<int>>(2,vector<int>(N+1,-1))) ;
        return solve(piles,0,true,1) ;
    }
};
