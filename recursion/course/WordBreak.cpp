class Solution {
    bool solve(string s, unordered_map<string,bool> &mp, int i, vector<int> &dp)
    {
        if (i==s.size())
            return true;
        
        if (dp[i]!=-1)
            return dp[i] ;
        
        string tmp="" ;
        for (int j=i; j<s.size(); j++){
            tmp+=s[j] ;
            if (mp.find(tmp)!=mp.end() && solve(s,mp,j+1,dp))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ;
        unordered_map<string,bool> mp;
        for (int i=0; i<wordDict.size(); i++)
            mp[wordDict[i]] = true;
        
        vector<int> dp(n, -1) ;
        
        return solve(s,mp,0,dp) ;
    }
};