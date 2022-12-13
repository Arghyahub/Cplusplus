class Solution {
    pair<int,vector<int>> p = {-1,{0,0,0,0,0,0,0,0,0,0,0,0}} ; 
public:

    void solve(vector<int>& alice, vector<int>& bob, int n, int i, int diff)
    {
        if (i==12 && n!=0){
            int save = bob[11] ;
            bob[11] = save + n;
            if (diff > p.first){
                p.first = diff;
                p.second = bob;
            }
            bob[11] = save;
            return;
        }
        if (n==0){
            if (diff > p.first){
                p.first = diff;
                p.second = bob;
            }
            return ;
        }

        // Shoot 1 high
        if (n > alice[i]){
            bob[i] = alice[i] + 1;
            solve(alice,bob,n - bob[i], i+1, diff + i ) ;
            bob[i] = 0 ;
        }
        // Dont shoot
        solve(alice,bob,n,i+1,diff) ;
    }

    vector<int> maximumBobPoints(int n, vector<int>& alice) {
        vector<int> bob(12,0);
        solve(alice,bob,n,0,0) ;
        return p.second;
    }
};
