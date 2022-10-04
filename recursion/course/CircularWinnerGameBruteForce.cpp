class Solution {
    int solve(int k, vector<int> &v,int i )
    {
        if (v.size()==1)
            return v[0] ;
        
        int n = v.size() ;
        int x = (i-1+k)%n ;
        v.erase(v.begin()+x) ;
        
        return solve(k,v,x) ;
    }
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n) ;
        for(int i=1; i<=n; i++)
            v[i-1] = i ;
        
        return solve(k,v,0) ;
        
    }
};