class Solution {
    int fin = 0 , inf = 100000;
    vector<vector<int>> dp;
    vector<vector<bool>> choice;
    int solve(vector<int> &ppl, int i, int mask) {
        if (mask == fin) return 0;
        if (i==ppl.size()) return inf;
        if (dp[i][mask]!=-1)
            return dp[i][mask] ;

        int inc = 1 + solve(ppl,i+1,mask|ppl[i]) ;
        int exc = solve(ppl,i+1,mask) ;
        if (inc<exc){
            choice[i][mask] = true;
        }

        return dp[i][mask] = min(inc,exc) ;
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        unordered_map<string,int> mp;
        for (int i=0; i<req.size(); i++)
            mp[req[i]]=i;
        
        vector<int> ppl(people.size()) ;
        for (int i=0; i<people.size(); i++) {
            int num = 0;
            for (int j=0; j<people[i].size(); j++)
                num|= 1<<(mp[people[i][j]]) ;
            ppl[i] = num;
        }

        fin = (1<<(mp.size())) - 1;

        dp.resize(ppl.size()+1,vector<int>(fin+1,-1)) ;
        choice.resize(ppl.size()+1,vector<bool>(fin+1));

        int ln = solve(ppl,0,0) ;

        int dmask = 0;
        vector<int> ans;
        for (int i=0; i<ppl.size(); i++) {
            if (choice[i][dmask]) {
                ans.push_back(i) ;
                dmask |= ppl[i] ;
            }
            if (dmask==fin)
                break;
        }

        return ans ;
    }
};
