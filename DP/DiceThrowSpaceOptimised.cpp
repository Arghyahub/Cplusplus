    
  public:
    long long noOfWays(int M , int N , int X) {
        // code here
        // vector<vector<long long>> dp(N+1,vector<long long>(X+1,0)) ;
        vector<long long> prevrow(X+1,0) ;
        vector<long long> currrow(X+1,0) ;
        
        prevrow[0] = 1;
        
        for (int n=1; n<=N; n++){
            for (int x=0; x<=X; x++){
                
                long long ans = 0 ;
                for (int i=1; i<=M; i++)
                    if (x-i>=0)
                        ans += prevrow[x-i] ;
                
                currrow[x] = ans ;
            }
            prevrow = currrow ;
        }
        return currrow[X] ;
    }
};
