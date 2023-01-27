// New concept of drawing paths to the end of the string,
// If last end is reached then its true that the word is made of other smaller words
class Solution {
    bool isTrue(string &s, unordered_map<string,bool> &mp){
        int n = s.size() ;
        vector<bool> reachable(n+1,false) ;
        mp[s] = false;
        reachable[0] = true;

        for (int i=0; i<n; i++){
            if (!reachable[i]) continue;
            for (int j=i; j<n; j++){
                string tmp = s.substr(i,j-i+1) ;
                if (mp.count(tmp) && mp[tmp] )
                    reachable[j+1] = true; // Mark the next index to be checked the word from
            }
        }
        mp[s] = true;
        return reachable[n] ;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,bool> mp;
        for (auto &word : words)
            mp[word] = true;
        
        vector<string> ans;
        for (auto &word : words){
            if (isTrue(word,mp))
                ans.push_back(word) ;
        }

        return ans;
    }
};
