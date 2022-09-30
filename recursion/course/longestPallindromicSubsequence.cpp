class Solution {
    int max(int i , int j){
        if (i>j)
            return i ;
        return j;
    }
    bool checkPalindrome(string s)
    {
        int i=0, j=s.size()-1 ;
        while(i<j){
            if (s[i]!=s[j])
                return false;
            i++ ;
            j-- ;
        }
        return true;    
    }
    
    void getLPS(string &s,string temp,int i, int &ans)
    {
        if (i==s.size())
        {
            if (checkPalindrome(temp))
                ans = max(ans,temp.size()) ;
            return ;
        }
        
        // include
        getLPS(s,temp+s[i],i+1,ans) ;
        
        //exclude
        getLPS(s,temp,i+1,ans) ;
    }
    
    
public:
    int longestPalindromeSubseq(string s) {
        int ans = 0 ;
        getLPS(s,"",0,ans) ;
        return ans;
    }
};