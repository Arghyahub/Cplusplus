class Solution {
    unordered_map<int,int> avail;
    unordered_map<int,unordered_set<int>> adj;

    void dfs(int u, int n, int &ans){
        if (n==0){
            ans++;
            return;
        }

        avail[u]--;
        for (auto v : adj[u]){
            if (avail[v])
                dfs(v,n-1,ans) ;
        }

        avail[u]++;
    }

public:
    int numSquarefulPerms(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++)
            avail[ nums[i] ] ++ ;
        
        for (int i=0; i<nums.size(); i++){
            for (int j=0; j<nums.size(); j++){
                int u = nums[i] , v = nums[j] ;
                int s = sqrt(u+v) ;
                if (s*s == u+v){
                    adj[u].insert(v) ;
                    adj[v].insert(u) ;
                }
            }
        }

        int ans = 0;
        for (auto it : adj){
            dfs(it.first,nums.size()-1,ans) ;
        }
        return ans;
    }
};


/**
 * 1. Get the number of available elements
 * 2. Associate or join all elements which form a squareful array
 * 3. Do a dfs search for each and every path and if path length == required length then this is a suitable array
 * /

