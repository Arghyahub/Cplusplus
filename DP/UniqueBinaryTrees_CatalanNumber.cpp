class Solution {
public:
    int numTrees(int n) {
        int num=2*n , deno=n+1 , k=n;
        long long ans = 1;
        
        for (int i=0; i<k; i++){
            ans*=(num-i) ;      // take upto [2n - (n-1)]
            ans/=(i+1) ;        // take upto n!
        }
        ans=ans/deno ;
        return ans;
    }
};
