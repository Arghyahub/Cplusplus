class Solution {
    int getAns(string &text1, int i, string &text2, int j)
    {
        if (i==text1.length() || j==text2.length())
            return 0 ;
        
        if (text1[i]==text2[j]){
            return 1 + getAns(text1,i+1,text2,j+1) ;
        }
        
        return max( getAns(text1,i,text2,j+1) , getAns(text1,i+1,text2,j) ) ;
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        return getAns(text1,0,text2,0) ;
    }
};