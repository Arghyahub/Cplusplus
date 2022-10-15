class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,pair<int,int>> mp;
        int ans = 1 ;
        
        for (int i=0; i<n; i++)
            mp[arr[i]] = {0,i} ;
        
        for (int i=0; i<n; i++){
            if ( mp.find(arr[i]+diff) == mp.end() ) continue;
            if (mp[arr[i]+diff].second <=i) continue;
            
            int sec = mp[arr[i]+diff].second ;
            
            if (mp[arr[i]].first==0){
                mp[arr[i]+diff] = {2,sec} ;
            }
            else{
                mp[arr[i]+diff].first = mp[arr[i]].first + 1;
            }
            ans=max(ans,mp[arr[i]+diff].first) ;
        }
        return ans ;
    }
};
