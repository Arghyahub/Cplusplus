class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long succ) {
        sort(p.begin(),p.end()) ;
        int n = s.size() , m = p.size() ;
        vector<int> ans(n) ;
        for (int i=0; i<n; i++){
            long long x;
            if (succ%s[i]==0) 
                x=succ/s[i] ;
            else 
                x = (succ/s[i])+1;
            auto ind = lower_bound(p.begin(),p.end(),x) - p.begin() ;
            ans[i] = m - ind;
        }
        return ans;
    }
};
