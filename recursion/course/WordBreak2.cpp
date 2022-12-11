class Solution {
    vector<string> ans;

    void solve(unordered_set<string> &dict, string &s ,string saver, int i)
    {
        if (i==s.size()){
            if (saver.size()){
                saver.pop_back() ;
                ans.push_back(saver) ;
                saver.push_back(' ') ;
            }
            return ;
        }

        string word;
        for (int j=i; j<s.size(); j++){
            word.push_back(s[j]) ;
            if (dict.find( word ) != dict.end() ){
                word.push_back(' ') ;
                solve(dict,s,saver+word,j+1) ;
                word.pop_back() ;
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (int i=0; i<wordDict.size(); i++)
            dict.insert(wordDict[i]) ;
        
        string tmp;
        solve(dict,s,"",0) ;
        return ans;
    }
};