class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s==t) return true;
        if (s.length()>t.length()) return false;
        for (int i=0, j=0; j<t.length(); j++)
        {    
            if (s[i]==t[j])
                i++;
            
            if (i==s.length()) return true;
        }
        return false;
    }
};