// Good concept of when to forward l and check condition
class Solution{
    public:
    int findSubString(string &str)
    {
        if (str.size()==1) return 1;
        unordered_set<char> all ;
        unordered_map<char,int> window ;
        for (char ch : str){
            all.insert(ch) ;
        }
        
        int l=0,r=0 , ans=str.size() ;
        while(r<str.size()){
            window[str[r]]++;
            
            while (window[str[l]]>1){
                window[str[l]]--;
                l++;
            }
            if (window.size()==all.size())
                ans = min(ans,r-l+1) ;
            
            r++;
        }
        return ans;
    }
};
